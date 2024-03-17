# n = int(input())
# a = list(map(int, input().split()))
# count = {}

# for i in a:
#     if i in count:
#         count[i] += 1
#     else:
#         count[i] = 1

# max_values = max(count.values())

# max_of_max = [key for key, values in count.items() if values == max_values]

# print(max(max_of_max))


# def test(_a):
#     _a = 2
#     print(_a)

# a = 4
# test(a)
# print(a)

A = [23,12,7,43,51]

i = 1

A[2] = A[i] + 2*A[i-1] + A[2*i+1]

print(A[2] + A[4])
# for i in range(5):
#     A[i] = A[i]*A[i]

# print(A)