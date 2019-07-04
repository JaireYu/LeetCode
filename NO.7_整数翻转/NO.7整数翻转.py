class Solution:
    def reverse(self, x: int) -> int:
        numstr = str(x)
        lenth = len(numstr)
        x = ''
        if numstr[0] == '-':
            x += '-'
            numstr = numstr[1:lenth]
            lenth = lenth - 1
        while(lenth != 0):
            if(numstr[lenth-1] == '0'):
                lenth = lenth - 1
            else:
                break
        x += numstr[lenth-1:: -1]
        x = int(x)
        try:
            if(-2**31<=x and x <= 2**31-1):
                return x
            else:
                return 0
        except OverflowError:
            return 0