import sys
ip = sys.stdin.readlines()

n,m,v = map(int, ip[0].strip().split(" "))
edges = [tuple(map(int, i.strip().split(" "))) for i in ip[1:]]

nei = [[] for _ in range(n)]

for e in edges:
    a,b = e
    nei[a-1].append(b-1)
    nei[b-1].append(a-1)

for i in range(len(nei)):
    nei[i] = sorted(nei[i])


from collections import deque

q = deque([v-1])
visited = [False for i in range(n)]
ans = []

while q:
    cur = q.pop()

    if not visited[cur]:
        ans.append(cur+1)
        visited[cur] = True
    
        for a in reversed(nei[cur]):
            if not visited[a]:
                q.append(a)
    

print(' '.join(map(str, ans)))


q = deque([v-1])
visited = [False for i in range(n)]
ans = []

while q:
    cur = q.popleft()

    if not visited[cur]:
        ans.append(cur+1)
        visited[cur] = True
    
        for a in nei[cur]:
            if not visited[a]:
                q.append(a)
    

print(' '.join(map(str, ans)))