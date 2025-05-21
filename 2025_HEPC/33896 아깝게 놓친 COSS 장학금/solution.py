import sys
input = sys.stdin.readline
import heapq

pp = []
for _ in range(int(input())):
  name, score, risk, cost = input().split()
  ss = int(score)**3//((int(cost)*(int(risk)+1)))
  heapq.heappush(pp, (-ss, int(cost), name))

heapq.heappop(pp)
print(heapq.heappop(pp)[2])
