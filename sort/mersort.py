def MergeSort(lists):
    if len(lists) <= 1:
        return lists
    num = int( len(lists)/2 )
    left = MergeSort(lists[:num])
    right = MergeSort(lists[num:])
    return Merge(left, right)
def Merge(left,right):
    r, l=0, 0
    reslut=[]
    while l<len(left) and r<len(right):
        if left[l] < right[r]:
            reslut.append(left[l])
            l += 1
        else:
            reslut.append(right[r])
            r += 1
    reslut += right[r:]
    reslut += left[l:]
    return reslut
print MergeSort([1, 2, 3, 4, 5, 6, 7, 90, 21, 23, 45])
