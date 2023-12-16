from functools import cache
from math import gcd, lcm, sqrt
from collections import Counter
import math
import sys

sys.setrecursionlimit(10**6)

MOD = 10**9+7

class SizedCounter(dict):
    def __init__(self, iterator=None):
        if iterator is None: return
        for obj in iterator:
            self[obj] += 1
    def __setitem__(self, key, value):
        value = max(value, 0)
        if not value:
            if key in self: del self[key]
            return
        super().__setitem__(key, value)
    def __getitem__(self, key):
        return super().get(key, 0)

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n
    def find(self, i):
        if self.parent[i] == i: return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    def union(self, i, j):
        a, b = self.find(i), self.find(j)
        if a == b: return
        if self.rank[a] > self.rank[b]: a, b = b, a
        self.parent[a] = b
        self.rank[a] += self.rank[a] == self.rank[b]
    @property
    def connected(self):
        return all(self.find(i) == self.find(0) for i in range(len(self.rank)))

@cache
def factor(num):
    if num == 1: return []
    for i in range(2, int(sqrt(num))+1):
        if num%i > 0: continue
        return [i]+factor(num//i)
    return [num]

def choose(n, k, mod=MOD):
    res = 1
    for i in range(1, k+1):
        res = res*i % mod
    res = pow(res, mod-2, mod)
    for i in range(n, n-k, -1):
        res = res*i % mod
    return res

def pow(n, p, mod=MOD):
    return math.pow(n, p, mod)

def sieve(N):
    N += 1
    P = [True]*N
    P[0] = P[1] = False
    i = 1
    while i*i < N:
        if P[i]:
            j = i*i
            while j < N:
                P[j] = False
                j += i
        i += 1
    return P