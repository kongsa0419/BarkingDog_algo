'''
처음에는 ascending order를 찾는 로직을 run()에 짜두고,
기존 입력 한번, reverse 배열을 한번. 총 두번을 돌렸다.
O(N x 2)로도 N이 100_000 이하라서 통과할 수 있다.

하지만, O(n)으로 한번에 수행할 수 있었다. 본 풀이는 O(N)으로 더 효율적이다.
'''


import sys

''' return longest sequence of sub-array which lasts ascending/descending order '''
def run(arr) -> int:
    res = 1 # result (Longest)
    inc = dec = 1
    
    for i in range(1, len(arr)):
        if arr[i-1] < arr[i]:
            inc += 1
            dec = 1
        elif arr[i-1] > arr[i]:
            inc = 1
            dec += 1
        else:
            inc += 1
            dec += 1
        res = max(res, inc, dec)
    return res
 
if __name__ == "__main__":
    #input
    N = int(input())
    arr = list(map(int, sys.stdin.readline().strip().split(sep=' ')))
    print(run(arr))