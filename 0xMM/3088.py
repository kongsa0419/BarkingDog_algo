import sys

N = int(input())
arrs = []
numset = set()
cnt = 0

#input
for i in range(N):
    arr = list(map(int, sys.stdin.readline().strip().split(' ')))
    arrs.append(arr)

for i in range(N):
    casc = False # cascade
    for item in arrs[i]:
        if item in numset:
            casc = True
            break
    if not casc:
        cnt += 1
    numset.update(arrs[i])
print(cnt)