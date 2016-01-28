#--coding: utf8 --
 
# 堆排序的思想 -- 以大根堆为例:
# 1) 构建堆
# 2) 把堆根取下来放到有序区去 -- 堆跟是当前堆上最大的数字
# 3) 此时堆没有根了，重新调整堆，然后重复1) - 3)直到堆成为一个空堆
# 
# 堆排序是选择排序的一种： 也是每次从未排序的区域选择一个值放入已排序的区域
# 它对直接选择排序的改进是： 对于以前已经比较过的结果可以保留下来：不用再重复比较：这也是堆的特性
 
def heap_sort(arr):
    build_heap(arr)
     
    arrlen = len(arr)
    for i in reversed(range(1, arrlen)):
        # 把堆跟(最大的值)放到最后面去
        swap(arr, 0, i)
        # 重新调整堆
        heapify(arr, 0, i - 1)
         
def swap(arr, index1, index2):
    tmp = arr[index1]
    arr[index1] = arr[index2]
    arr[index2] = tmp
     
def build_heap(arr):
    """ 以arr[0]到arr[(arrlen / 2)]为根的这些子树是需要调整的子树
    其他的都是叶子节点
    """
    arrlen = len(arr)
    for i in reversed(range(0, (arrlen - 1) / 2)):
        heapify(arr, i, arrlen - 1)
     
def heapify(arr, low, high):
    left = low * 2 + 1
    right = left + 1
    current = low
     
    # 暂存这个“假根”的值
    tmp = arr[low]
     
    # 如果当前节点还有子树
    while left <= high:
        if right <= high:
            if arr[left] < arr[right]:
                next = right
            else:
                next = left
        else:
            next = left
         
        # 确实有个孩子的值比他大
        if tmp < arr[next]:
            # 把这个大的值上移到父亲节点
            arr[current] = arr[next]
            # 更新current
            current = next
            left = current * 2 + 1
            right = left + 1
        else:
            # 这个堆已经完成
            break
         
    # 把假根把到这个正确的位置
    arr[current] = tmp
     
arr = [3,9,8,4,5,2,10,18,4]
heap_sort(arr)
print arr
