# write the function to find the fibonacci number

def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n-1) + fib(n-2)

# write the another function to find the largest among the given array
def largest(arr):
    max = arr[0]
    for i in arr:
        if i > max:
            max = i
    return max

print(largest([1,2,3,4,5]))

print(fib(10))