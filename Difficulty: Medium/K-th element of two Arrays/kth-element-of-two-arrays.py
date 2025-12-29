#User function Template for python3


class Solution:

    def kthElement(self, a, b, k):
        for i in b:
            a.append(i)
        a.sort()
        return a[k-1]



