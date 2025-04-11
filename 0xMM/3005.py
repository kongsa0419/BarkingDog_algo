import sys

if __name__ == "__main__":
    global R, C
    R, C = map(int, sys.stdin.readline().strip().split(sep=' '))
    mp = []
    rmp = [] # reversed
    for i in range(R):
        line = sys.stdin.readline().strip()
        mp.append(line)
    for i in range(C): # reversed
        line = ""
        for j in range(R):
            line += mp[j][i]
        rmp.insert(len(rmp), line)
    
    # run
    words = set()
    for r in range(R):
        tokens = list(filter(lambda x: len(x) > 1, mp[r].split('#')))
        words.update(tokens)
    for c in range(C): # reversed
        tokens = list(filter(lambda x : len(x) > 1, rmp[c].split(sep='#')))
        words.update(tokens)
    print(sorted(words)[0])