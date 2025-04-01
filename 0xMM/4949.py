import sys

# return type : Boolean
def balanced(line):
    stack = list()
    pairs = {'(' : ')', '[' : ']'} # dictionary(map)
    
    for ch in line:
        if ch in pairs.keys():
            stack.append(ch)
        elif ch in pairs.values():
            if (not stack) or (pairs[stack[-1]] != ch):
                return False
            stack.pop()
    # return False if stack else True
    return True if not stack else False
    
if __name__ == "__main__" :
    while True:
        line = sys.stdin.readline().strip('\n')
        if(len(line)==1 and line == "."):
            break
        print("yes" if balanced(line) else "no")