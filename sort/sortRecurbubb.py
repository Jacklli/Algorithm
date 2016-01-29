def sortByRecursion(testarray, n):
    if(n == 1):
        return
    i = 0
    while i < n-1:
        if(testarray[i] > testarray[i+1]):
	    tmp = testarray[i]
            testarray[i] = testarray[i+1]
            testarray[i+1] = tmp
            sortByRecursion(testarray, n-1)
        i += 1
testarray = [3,8,1,3,7]
sortByRecursion(testarray, 5)
print testarray
