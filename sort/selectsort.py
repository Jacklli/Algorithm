def selectSort(num):
    for i in range(0,len(num)):
        mindex=i
        for j in range(i,len(num)):
            if num[mindex]>num[j]:
                mindex=j
        num[mindex],num[i]=num[i],num[mindex]
    return num
num = [33,21,2,8,761,21]
print selectSort(num)
