def bubble_sort(l):
    for i in range(len(l),0,-1):
        for j in range(len(l)-1):
            if l[j] > l[j+1]:
                tmp = l[j]
                l[j] = l[j+1]
                l[j+1] = tmp

    print("result: " + str(l))
l = [2,5,8,1,878,22,125]
bubble_sort(l)
print("bubble_sort success!!!")
