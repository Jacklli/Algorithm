if __name__ =='__main__':
    l = [4,4,9,13,34,26,10,7,1]

#=========================insert_sort=========================
    def insert_sort(l):
        for i in range(len(l)):
            min_index = i
            for j in range(i+1,len(l)):
                if l[min_index] > l[j]:
                    min_index = j
            tmp = l[i]
            l[i] = l[min_index]
            l[min_index] = tmp
            print(str(l))
        print("result: " + str(l))

    insert_sort(l)
    print("insert_sort success!!!")
