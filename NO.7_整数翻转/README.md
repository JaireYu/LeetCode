# Python字符串切片和异常控制
* 字符串切片
```py
def reverse(x):
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
        # x += numstr[lenth-1:-1] 会报错因为左面的索引更大
        # x += numstr[lenth-1:-1: -1]   会报错原因未知
        x += numstr[lenth-1::-1]    #不会报错，因为初始值在最后，步长为-1
        try:
            return int(x)
        except OverflowError:   #Overflow作为异常控制语句
            return 0
```