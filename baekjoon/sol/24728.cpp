#include<stdio.h>

using namespace std;

int w,h; // Map : width, height
int expNum = 0; // experiment Number : How many times to change abiltiy
int maxC, u, d; // Abiltiy 
int timeNum;
int curtime;

class PanCakeCookie{
private:
	int w, h;
	int x, y, t;
	int score;
	int maxC, curC;
	int u, d;
public:
	PanCakeCookie(int w, int h, int maxC, int u, int d);

	int getX();
	int getY();
	int getU();
	int getD();
	int getScore();
	int getC();

	void reset();
	void setU(int x);
	void setD(int x);
	void setC(int x);
	void setT(int t);  
};

#include <iostream>
PanCakeCookie::PanCakeCookie(int w, int h, int maxC, int u, int d){
    this->w = w;
    this->h = h;
    this->maxC = maxC;
    this->u = u;
    this->d = d;
}

int PanCakeCookie::getX() {return this->x;}
int PanCakeCookie::getY(){ return this->y;}
int PanCakeCookie::getU(){ return this->u;}
int PanCakeCookie::getD(){ return this->d;}
int PanCakeCookie::getScore() {return this->score;}
int PanCakeCookie::getC(){ return this->curC;}

void PanCakeCookie::reset(){
    x = 0;
    y = 0;
    t = 0;
    score = 0;
    curC = maxC;
}

void PanCakeCookie::setU(int x){
    if (x<1 || x>1000)
        return;
    u = x;
    reset();
}

void PanCakeCookie::setD(int x){
    if (x<1 || x>1000)
        return;
    d = x;
    reset();
}

void PanCakeCookie::setC(int x){
    if (x<1 || x>1000)
        return;
    maxC = x;
    reset();
}

void PanCakeCookie::setT(int t){
    if (t<1 || t>=w)
        return;
    reset();
    for (int i = 1; i<=t; i++) {
        if (curC > 0) {
            curC = std::max(0, curC - 1);
            y = std::min(h, y+u);
        } else {
            curC = std::min(maxC, curC + 1);
            y = std::max(0, y-d);
        }
        score += y;
    }
    this->x = t;
    this->t = t;
}

int main(){
	scanf("%d %d %d %d %d",&w, &h, &maxC,&u,&d);
	PanCakeCookie pancake = PanCakeCookie(w,h,maxC,u,d);

	// Test For the initial state
	scanf("%d",&timeNum);
	for(int i=0;i<timeNum;i++){
		scanf("%d",&curtime);
		pancake.setT(curtime);
		printf("%d %d %d %d %d %d\n", pancake.getX(), pancake.getY(),pancake.getScore(),
		pancake.getC(),pancake.getU(), pancake.getD());
	}

	// Start Test
	scanf("%d", &expNum);
	
	char type;
	int num;
	
	for(int i=0;i<expNum;i++){
		scanf(" %c %d %d",&type, &num, &timeNum);

		if(type=='u'){
			pancake.setU(num);
			for(int j=0;j<timeNum;j++){
				scanf(" %d",&curtime);
				pancake.setT(curtime);
				printf("%d %d %d %d %d %d\n", pancake.getX(), pancake.getY(),pancake.getScore(),
				pancake.getC(),pancake.getU(), pancake.getD());
			}
		}

		else if(type=='d'){
			pancake.setD(num);
			for(int j=0;j<timeNum;j++){
				scanf(" %d",&curtime);
				pancake.setT(curtime);
				printf("%d %d %d %d %d %d\n", pancake.getX(), pancake.getY(),pancake.getScore(),
				pancake.getC(),pancake.getU(), pancake.getD());
			}
		}

		else if(type=='c'){
			pancake.setC(num);
			for(int j=0;j<timeNum;j++){
				scanf(" %d",&curtime);
				pancake.setT(curtime);
				printf("%d %d %d %d %d %d\n", pancake.getX(), pancake.getY(),pancake.getScore(),
				pancake.getC(),pancake.getU(), pancake.getD());
			}
		}

		else {
			printf("Invalid Input\n");
			return 0;
		}
	}

	return 0;

}