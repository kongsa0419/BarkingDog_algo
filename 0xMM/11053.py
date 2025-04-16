'''
LIS 기본 문제 (DP) : O(N**2)
입력이 1_000 이하라서, N**2로 풀 수 있었다.
dp배열에 현재 인덱스까지의 오름차순 순열의 최대길이를 기록한다.
현재 탐색중인 인덱스(j) 전까지 dp에는 그때까지의 순열 최장길이가 저장되어 있는데,
그때의 arr[j]값보다 현재 포인팅하는 arr[i]값이 더 크다면 순열에 arr[i]를 추가할 수 있으므로
dp[i] = dp[j]+1이 된다.
주의할 점은 이 dp[j]+1보다 dp[i]가 클 수 있으므로 주의하자.
'''


import sys

n = int(input())
arr = list(map(int, sys.stdin.readline().strip().split(sep=' ')))
dp = [1] * n
for i in range(1, n):
    mx = 0
    for j in range(0, i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j]+1)
print(sorted(dp)[-1])