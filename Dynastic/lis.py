import numpy as np
from bisect import bisect_left

e = []
n = 8
x = [6, 3, 4, 2, 7, 1, 8, 5]
p = -1 * np.ones(n, dtype=np.int32)
for i in range(n):
    j = bisect_left(e, x[i])
    if j == len(e):  # 二分查找的结果等于e的长度 即v大于e的末位元素
        if j > 0:
            p[i] = e[-1]
        e.append(x[i])
    else:
        e[j] = x[i]
        p[i] = e[j-1]
    print("iteration %d: e = %s" % (i+1, e))

dict = {key: value for key, value in zip(x, range(n))}
lis = []
pre = e[-1]
for i in range(len(e)):
    lis.append(pre)
    pre = p[dict[pre]]

lis.reverse()
print('LIS: %s' % lis)