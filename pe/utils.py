from functools import cache
from math import gcd, lcm, sqrt, isqrt, inf, ceil, prod
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
from fractions import Fraction
from copy import deepcopy
from time import perf_counter
import math
import sys
import random

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
        self.p = [-1]*n
    def find(self, i):
        if self.p[i] < 0: return i
        self.p[i] = self.find(self.p[i])
        return self.p[i]
    def unite(self, i, j):
        i, j = self.find(i), self.find(j)
        if i == j: return False
        if self.p[i] > self.p[j]: i, j = j, i
        self.p[i] += self.p[j]
        self.p[j] = i
        return True
    def size(self, i):
        return -self.p[self.find(i)]
    def sizes(self):
        return [-s for s in self.p if s < 0]

@cache
def factor(num):
    if num == 1: return []
    for i in range(2, int(sqrt(num))+1):
        if num%i == 0:
            return [i]+factor(num//i)
    return [num]

def phi(num):
    res = num
    for p in set(factor(num)):
        res = res*(p-1)//p
    return res

def choose2(n, k, mod=MOD):
    res = 1
    for i in range(1, k+1):
        res = res*i % mod
    res = pow(res, mod-2, mod)
    for i in range(n, n-k, -1):
        res = res*i % mod
    return res

def precompute(N, mod=MOD):
    global fac, inv
    fac, inv = [0]*(N+1), [0]*(N+1)
    fac[0] = 1
    for i in range(1, N+1):
        fac[i] = i*fac[i-1] % mod
    inv[N] = pow(fac[N], mod-2, mod)
    for i in range(N)[::-1]:
        inv[i] = (i+1)*inv[i+1] % mod
    return fac, inv

def choose(n, k, mod=MOD):
    return fac[n]*inv[k] % mod * inv[n-k] % mod

def sieve(N):
    P = [True]*(N+1)
    P[0] = P[1] = False
    for i in range(2, int(N**.5)+1):
        if not P[i]: continue
        for j in range(i*i, N+1, i):
            P[j] = False
    return P

def rref(A) -> list[list[Fraction]]:
    '''For large integer systems'''
    R, C = len(A), len(A[0])
    A = [[Fraction(num) for num in row] for row in A]
    for r in range(R):
        r2, c = None, None
        for j in range(C)[::-1]:
            for i in range(r, R)[::-1]:
                if A[i][j] != 0:
                    r2, c = i, j
        if r2 is None: break
        A[r], A[r2] = A[r2], A[r]
        for j in range(C)[::-1]:
            A[r][j] /= A[r][c]
        for i in range(R):
            if i == r: continue
            f = -A[i][c]/A[r][c]
            for j in range(C):
                A[i][j] += f*A[r][j]
    return A

def rref2(A):
    import sympy as sp
    return sp.Matrix(A).rref()[0].tolist()

def read(file):
    from pathlib import Path
    p = Path(__file__).with_name(file)
    with p.open() as f:
        return f.read().strip()

def readlines(file):
    return read(file).splitlines()

class Trie(dict):
    def __init__(self, A=()):
        super().__init__()
        for s in A: self.insert(s)
    def insert(t, s):
        for c in s:
            t[c] = t = t.get(c, Trie())
        t[None] = True

class RabinKarp:
    def __init__(self, A):
        if isinstance(A, str):
            A = (ord(c)-ord('a')+7 for c in A)
        self.MOD = MOD = 344555666677777
        self.pre = pre = [0]
        self.pinvs = pinvs = [1]
        pwr = 1
        P = 37
        Pinv = pow(P, MOD-2, MOD)
        for x in A:
            pwr = pwr*P % MOD
            pre.append((pre[-1] + x*pwr) % MOD)
            pinvs.append(pinvs[-1]*Pinv % MOD)
    def query(self, i, j):
        return (self.pre[j] - self.pre[i]) * self.pinvs[i] % self.MOD

class KMP:
    def __init__(self, A):
        N = len(A)
        self.P = [0]*N
        j = 0
        for i in range(1, N):
            while j and A[i] != A[j]: j = self.P[j-1]
            j = self.P[i] = j + (A[i] == A[j])
        self.Z = [0]*N
        l = r = -1
        for i in range(1, N):
            j = 0 if i >= r else min(r-i, self.Z[i-l])
            while i+j < N and A[i+j] == A[j]: j += 1
            if i+j > r: l, r = i, i+j
            self.z[i] = j
        self.Z[0] = N

class mint(int):
    def __new__(cls, value): return super().__new__(cls, value % MOD)
    def __add__(self, other): return mint(int(self) + other)
    def __sub__(self, other): return mint(int(self) - other)
    def __mul__(self, other): return mint(int(self) * other)
    def __neg__(self): return mint(-int(self))
    def __truediv__(self, other): return self * mint(other)**(MOD-2)
    def __rtruediv__(self, other): return mint(other) / self
    def __pow__(self, other): return mint(pow(int(self), other, MOD))
    def __str__(self): return f'{int(self)}'
    def __repr__(self): return f'mint({self})'
