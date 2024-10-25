#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


const int dx[4] = {0,-1,0,1};
const int dy[4] = {-1,0,1,0};


class Item;
class Monster;
class Player;


enum class ItemType {
    Weapon, Armor, Amulet
};

enum class AmuletEffect {
    None, 
    Regen,          // HR
    Reincarnation,  // RE
    Courage,        // CO
    Experience,     // EX
    Dexterity,      // DX
    Hunter,         // HU
    Cursed          // CU
};

enum class Tile {
    Wall,       // #
    Empty,      // .
    Player,     // @
    Monster,    // &
    Boss,       // M
    Spike,      // .
    Item,       // B
};

int N, M;
int turn = 0;
vector<vector<Tile>> world;

Player* player;

int start_x, start_y;

Monster* boss;
map<pair<int,int>, Monster*> monsters;
map<pair<int,int>, Item*> items;

vector<int> commands;
string death_by;

class Item {

public:
    ItemType type;

    AmuletEffect effect;    // for item
    int value;              // for weapon & armor

    Item(ItemType _type, AmuletEffect _effect, int _value)
    : type(_type), effect(_effect), value(_value) {}
};


class Monster {
    public:
        int x;
        int y;

        string name;

        int atk;
        int def;
        int hp_max;
        int exp;

        bool boss = false;
        bool dead = false;

        Monster(int _x, int _y, string _name, int _atk, int _def, int _hp_max, int _exp) 
        : x(_x), y(_y), name(_name), atk(_atk), def(_def), hp_max(_hp_max), exp(_exp) {}
        
        bool is_dead() {
            return dead;
        }
};

class Player {
    public:
        int level;

        int hp_max;
        int hp_cur;

        int atk;
        int def;

        int exp_cur;

        int x;
        int y;

        Item * weapon = nullptr;
        Item * armor = nullptr;
        map<AmuletEffect, bool> amulet;
        int amulet_nums = 0;

        Player() {
            level = 1;
            hp_max = hp_cur = 20;
            atk = 2;
            def = 2;
            exp_cur = 0;

            x = start_x;
            y = start_y;
        }

        void level_up() {
            if (exp_cur >= 5*level) {
                exp_cur = 0;
                level++;

                hp_max += 5;
                atk += 2;
                def += 2;
                hp_cur = hp_max;
            }
        }

        void move(int direction) {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if (world[nx][ny] == Tile::Wall)
                return;

            x = nx;
            y = ny;
        }

        void process_tile() {
            Tile tile = world[x][y];
            switch(tile) {
                case Tile::Boss:
                case Tile::Monster: 
                    if (battle(monsters[{x,y}])) 
                        world[x][y] = Tile::Empty;
                    break;

                case Tile::Spike: 
                    get_damaged(amulet[AmuletEffect::Dexterity]? 1 : 5, "SPIKE TRAP");
                    break;

                case Tile::Item: 
                    equip(items[{x,y}]);
                    world[x][y] = Tile::Empty;
                    break;
                default: break;
            }
        }

        bool battle(Monster * monster) {
            int player_dmg, monster_dmg;
            int player_remain_turns, monster_remain_turns;
            int dmg_mult = 1;
            int monster_hp = monster->hp_max;

            monster_dmg = max(1, monster->atk - player->def);

            if (amulet[AmuletEffect::Courage]) {
                if (amulet[AmuletEffect::Dexterity])
                    dmg_mult = 3;
                else
                    dmg_mult = 2;
            }
            player_dmg = max(1, dmg_mult*player->atk - monster->def);

            // first turn
            if (monster->boss && amulet[AmuletEffect::Hunter]) {
                player->hp_cur = player->hp_max;
                
                monster_hp -= player_dmg;
                monster_hp = max(0,monster_hp);
            } else {
                monster_hp -= player_dmg;
                monster_hp = max(0,monster_hp);

                if (monster_hp > 0) {
                    get_damaged(monster_dmg, monster->name);
                    if (this->is_dead() || (monster->x != player->x || monster->y != player->y)) {
                        return false;
                    }
                }   
            }

            player_dmg = max(1, player->atk - monster->def);

            player_remain_turns = player->hp_cur / monster_dmg + (player->hp_cur % monster_dmg?1:0);
            monster_remain_turns = monster_hp / player_dmg + (monster_hp % player_dmg?1:0);

            if (player_remain_turns < monster_remain_turns) {
                // player dead!!
                get_damaged(monster_remain_turns * monster_dmg, monster->name);

                return false;
            } else {
                // monster dead!!
                get_damaged(max(0,(monster_remain_turns-1)) * monster_dmg, monster->name);

                int exp = monster->exp;
                monster->dead = true;
                exp_cur += exp + (amulet[AmuletEffect::Experience] ? exp/5 : 0);
                level_up();
            }

            if (amulet[AmuletEffect::Regen])
                hp_cur = min(hp_max, hp_cur+3);

            return true;
        }

        bool battle_slow(Monster* monster) {
            // same battle, slower execution
            int monster_hp = monster->hp_max;
            int player_hp = hp_cur;

            int player_dmg, monster_dmg;

            int dmg_mult = 1;

            if (amulet[AmuletEffect::Courage]) {
                if (amulet[AmuletEffect::Dexterity])
                    dmg_mult = 3;
                else
                    dmg_mult = 2;
            }

            player_dmg = max(1, dmg_mult*player->atk - monster->def);
            monster_dmg = max(1, monster->atk - player->def);

            if (monster->boss && amulet[AmuletEffect::Hunter]) {
                player_hp = hp_cur = hp_max;
                monster_hp -= player_dmg;
            }

            while (monster_hp > 0 && player_hp > 0) {
                monster_hp -= player_dmg;
                if (monster_hp > 0)
                    player_hp -= monster_dmg;
            }

            if (player_hp <= 0) {
                get_damaged(hp_cur - player_hp, monster->name);
                return false;
            } else {
                get_damaged(hp_cur - player_hp, monster->name);

                int exp = monster->exp;
                monster->dead = true;
                exp_cur += exp + (amulet[AmuletEffect::Experience] ? exp/5 : 0);
                level_up();

                if (amulet[AmuletEffect::Regen])
                    hp_cur = min(hp_max, hp_cur+3);

                return true;
            }

        }

        bool equip(Item * item) {
            switch(item->type) {
                case ItemType::Weapon:  
                    if (weapon != nullptr)
                        atk -= weapon->value;
                    weapon = item;
                    atk += weapon->value;
                    break;

                case ItemType::Armor: 
                    if (armor != nullptr)
                        def -= armor->value;
                    armor = item;
                    def += armor->value;
                    break;

                case ItemType::Amulet: 
                    if (amulet_nums >= 4)
                        return false;
                    if (amulet[item->effect])
                        return false;
                    
                    amulet[item->effect] = 1;
                    amulet_nums++;

                    break;
            }

            return true;
        }

        bool is_dead() {
            return hp_cur <= 0;
        }

        bool get_damaged(int dmg, string deathcause) {
            dmg = max(0,dmg);
            hp_cur -= dmg;

            if (is_dead()) {
                if (amulet[AmuletEffect::Reincarnation]) {
                    amulet[AmuletEffect::Reincarnation] = false;
                    amulet_nums--;
                    
                    hp_cur = hp_max;
                    x = start_x;
                    y = start_y;
                    return false;
                } else {
                    death_by = deathcause;
                    hp_cur = 0;
                    return true;
                }
            }
            return true;
        }
        void output_stats() {
            int atk_bonus = weapon!=nullptr? weapon->value : 0;
            int def_bonus = armor!=nullptr? armor->value : 0;
            cout << "Passed Turns : " << turn << "\n";
            cout << "LV : " << level << "\n";
            cout << "HP : " << hp_cur << "/" << hp_max << "\n";
            cout << "ATT : " << atk-atk_bonus << "+" << atk_bonus << "\n";
            cout << "DEF : " << def-def_bonus << "+" << def_bonus << "\n";
            cout << "EXP : " << exp_cur << "/" << level*5 << "\n";
        }
};

void input_world() {
    cin >> N >> M;

    world.push_back(vector<Tile>(M+2));
    for (int i=1;i<=N;i++) {
        string s;
        cin >> s;
        world.push_back(vector<Tile>(M+2));
        for (int j=1;j<=M;j++) {
            switch(s[j-1]) {
                case '.': 
                    world[i][j] = Tile::Empty; break;
                case '@': 
                    world[i][j] = Tile::Empty; 
                    start_x = i;
                    start_y = j;
                    break;
                case '&': 
                    world[i][j] = Tile::Monster; break;
                case 'M': 
                    world[i][j] = Tile::Boss; break;
                case '^': 
                    world[i][j] = Tile::Spike; break;
                case 'B': 
                    world[i][j] = Tile::Item; break;
                case '#': 
                    world[i][j] = Tile::Wall; break;
            }
        }
    }
    world.push_back(vector<Tile>(M+2));
}

void input_command() {
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++) {
        switch(s[i]) {
            case 'L': commands.push_back(0); break;
            case 'U': commands.push_back(1); break;
            case 'R': commands.push_back(2); break;
            case 'D': commands.push_back(3); break;
        }
    }
}

void input_monster(int x, int y) {
    string name;
    int atk, def, hp_max, exp;
    cin >> name >> atk >> def >> hp_max >> exp;
    
    monsters[{x,y}] = new Monster(x,y,name,atk,def,hp_max,exp);

    if(world[x][y] == Tile::Boss) {
        monsters[{x,y}]->boss = true;
        boss = monsters[{x,y}];
    }
}

void input_item(int x, int y) {
    char type;
    cin >> type;

    string effect;

    int val;

    AmuletEffect ae = AmuletEffect::None;

    switch(type) {
        case 'W':
            cin >> val;
            items[{x,y}] = new Item(ItemType::Weapon, ae, val);
            break;
        case 'A':
            cin >> val;
            items[{x,y}] = new Item(ItemType::Armor, ae, val);

            break;
        case 'O':
            cin >> effect;
            if (!effect.compare("HR")) {
                ae = AmuletEffect::Regen;
            } else if (!effect.compare("RE")) {
                ae = AmuletEffect::Reincarnation;
            } else if (!effect.compare("CO")) {
                ae = AmuletEffect::Courage;
            } else if (!effect.compare("EX")) {
                ae = AmuletEffect::Experience;
            } else if (!effect.compare("DX")) {
                ae = AmuletEffect::Dexterity;
            } else if (!effect.compare("HU")) {
                ae = AmuletEffect::Hunter;
            } else if (!effect.compare("CU")) {
                ae = AmuletEffect::Cursed;
            }

            items[{x,y}] = new Item(ItemType::Amulet, ae, val);

            break;
    }
}

void input_monsters_and_items() {
    int x, y;
    while (cin >> x >> y) {
        if (world[x][y] == Tile::Monster || world[x][y] == Tile::Boss)
            input_monster(x,y);
        else if (world[x][y] == Tile::Item)
            input_item(x, y);
    }
}

void output_world() {
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (player->x == i && player->y == j && !player->is_dead()) {
                cout << "@";
                continue;
            }

            switch(world[i][j]) {
                case Tile::Empty:  cout << '.'; break;
                case Tile::Wall:  cout << '#'; break;
                //case Tile::Player:  cout << '.'; break;
                case Tile::Monster:  cout << '&'; break;
                case Tile::Boss:  cout << 'M'; break;
                case Tile::Spike:  cout << '^'; break;
                case Tile::Item:  cout << 'B'; break;
            }
        }
        cout << "\n";
    }
}

void output_result() {
    if (player->is_dead()) {
        cout << "YOU HAVE BEEN KILLED BY " << death_by << "..";
    } else if (boss->dead) {
        cout << "YOU WIN!";
    } else if (turn >= commands.size()) {
        cout << "Press any key to continue.";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    input_world();
    input_command();
    input_monsters_and_items();

    player = new Player();
    if (!boss) {
        boss = new Monster(-1,-1,"Boss", 0,0,0,0);
        boss->boss = true;
    }

    while (!player->is_dead() && !boss->dead && turn < commands.size()) {
        player->move(commands[turn++]);
        player->process_tile();
    }

    output_world();
    player->output_stats();
    output_result();
    
    
}