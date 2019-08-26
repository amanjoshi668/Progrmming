class EllyCodeConstants:
    def getLiteral(a):
        if a.find('0x'):
            a = a[2:]
        a = a[::-1]
        X = ['ULL','LLU','LL','UL', 'LU','L',  'U']
        T = ['0','1','2','3','4','5','6','7','8','9','O','l','Z','S','T']
        removed = ""
        for t in X:
            if a.find(t) == 0:
                a = a[len(t):]
                removed = t
                break
        
        ans = True
        for i in range(len(a)):
            if i not in T:
                ans = False

        if ans:
            return '0x' + a.reverse() + t
        else:
            return ""
        