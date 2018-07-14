def weightedUniformStrings(s, queries):
    s1 = list(s)
    s1.sort()
    final = []
    if len(s) > 1:
        for i in range(len(s1)-1, -1, -1):
            if s1[i] == s1[i-1]:
                s1.pop(i)
    s2 = [0] * (ord(s1[-1])-96)
    for i in range(len(s)):
        s2[ord(s[i])-97]+=1

    flag = False
    temp = 0
    for i in range(len(s2)-1,-1,-1):
        if s2[i] == 0:
            s2.pop(i)
    for x in queries:
        for i in range(len(s1)):
            for j in range(s2[i]):
                temp += ord(s1[i])-96
                if temp == x:
                    final.append("Yes")
                    flag = True
                    break
            temp = 0
            if flag:
                break
        if not flag:
            final.append("No")
        flag = False
    return final




s = "l"
queries = [1,12]
#s = "abccddde"
#queries = [1,3,12,5,9,10]
print (weightedUniformStrings(s, queries))