from functools import cache
from math import gcd, lcm, sqrt, isqrt, inf, ceil, prod, factorial
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
from fractions import Fraction
from itertools import combinations, permutations, product
from copy import deepcopy
from time import perf_counter
import math
import sys
import random

MOD = 10**9+7

class SizedCounter(Counter):
    def __setitem__(self, key, value):
        if value <= 0:
            if key in self: del self[key]
            return
        super().__setitem__(key, value)

class mint(int):
    MOD = 10**9+7
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

class CF:
    @staticmethod
    def sqrt(n):
        '''Find fraction expansion for sqrt(n)'''
        A = [isqrt(n)]
        if isqrt(n)**2 == n: return A
        V = set()
        a = 1
        b = -isqrt(n)
        while (a, b) not in V:
            V.add((a, b))
            t = int(a/(n**.5+b))
            A.append(t)
            a = (n-b**2)//a
            b = -b - a*t
        return A
    @staticmethod
    def approx(A):
        '''Find continued fraction given a list'''
        A = list(A)
        f = Fraction(A[-1], 1)
        for a in A[:-1][::-1]:
            f = a + Fraction(1, f)
        return f

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

def choose(n, k, mod=MOD):
    res = 1
    for i in range(1, k+1):
        res = res*i % mod
    res = pow(res, mod-2, mod)
    for i in range(n, n-k, -1):
        res = res*i % mod
    return res

def read(file):
    from pathlib import Path
    p = Path(__file__).with_name(file)
    with p.open() as f:
        return f.read().strip()

def readlines(file):
    return read(file).splitlines()

def sieve(N):
    P = [True]*(N+1)
    P[0] = P[1] = False
    for i in range(2, int(N**.5)+1):
        if not P[i]: continue
        for j in range(i*i, N+1, i):
            P[j] = False
    return P

class Roman():
    ord = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    inv = {v: c for c, v in ord.items()}

    def __init__(self, x: int | str):
        if isinstance(x, str):
            A, x = map(Roman.ord.__getitem__, x[::-1]), 0
            p = 0
            for a in A:
                p = max(p, a)
                x += a if p <= a else -a
        self.val = x

    def __repr__(self):
        res = ''
        p = 1
        while p*10 <= self.val: p *= 10
        while p:
            d = self.val//p%10
            if p >= 1000:
                res += p//1000*d*'M'
            else:
                if d%5 >= 4: res += (5-d%5)*Roman.inv[p]
                if d > 3: res += Roman.inv[((d-3)//5*5+5)*p]
                if d%5 < 4: res += d%5*Roman.inv[p]
            p //= 10
        return res

def quadratic(a, b, c):
    d = (b*b-4*a*c)**.5
    p, q = (-b-d)/(2*a), (-b+d)/(2*a)
    # if not isinstance(p, complex) and p.is_integer(): p = int(p)
    # if not isinstance(q, complex) and q.is_integer(): q = int(q)
    return p, q