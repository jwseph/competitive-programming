from functools import cache, cached_property
from math import gcd, lcm, sqrt, isqrt, inf, ceil, prod, factorial
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop
from bisect import bisect_left, bisect_right
from fractions import Fraction
from itertools import combinations, permutations
from operator import add, mul
from copy import deepcopy
from time import perf_counter
import math
import sys
from random import randint
from typing import List, NamedTuple, Optional, Tuple, cast

from utils_ext import *

sys.setrecursionlimit(10**6)

MOD = 10**9+7

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

class Mod:
    def __init__(self, N, mod=MOD):
        self.fac = fac = [0]*(N+1)
        self.inv = inv = [0]*(N+1)
        self.mod = mod
        fac[0] = 1
        for i in range(1, N+1):
            fac[i] = i*fac[i-1] % mod
        inv[N] = pow(fac[N], mod-2, mod)
        for i in range(N)[::-1]:
            inv[i] = (i+1)*inv[i+1] % mod
        return fac, inv

    def choose(self, n, k):
        return self.fac[n]*self.inv[k] % self.mod * self.inv[n-k] % self.mod

class Trie(dict):
    def __init__(self, A=()):
        super().__init__()
        self.end = False
        for s in A: self.add(s)
    def add(t, s):
        for c in s:
            t[c] = t = t.get(c, Trie())
        t.end = True
    def find(t, s):
        if t.end: yield 0
        for i, c in enumerate(s):
            if c not in t: return
            t = t[c]
            if t.end: yield i+1

class RabinKarp:
    mod = 344555666677777
    base = randint(mod//10, mod*9//10)
    @staticmethod
    @cache
    def pow(w):
        if w == 0: return 1
        return RabinKarp.pow(w-1) * RabinKarp.base % RabinKarp.mod
    def __init__(self, s=[]):
        self.s = []
        self.pre = [0]
        for c in s: self.add(c)
    def add(self, c):
        self.s.append(c)
        self.pre.append((self.pre[-1]*RabinKarp.base + hash(c)+2**63) % RabinKarp.mod)
    def query(self, l, r):
        return (self.pre[r] - self.pre[l]*RabinKarp.pow(r-l)) % RabinKarp.mod
    def pop(self):
        self.s.pop()
        self.pre.pop()

class RabinKarp:
    mod = 344555666677777
    base = randint(mod//10, mod*9//10)
    pows = [1]
    def __init__(self, s=[]):
        self.s = s
        self.pre = pre = [0]
        self.l = self.r = 0
        for c in s:
            pre.append((pre[-1]*RabinKarp.base + hash(c)+2**63) % RabinKarp.mod)
            self.r += 1
    def query(self, l, r):
        pows = RabinKarp.pows
        while r-l >= len(pows):
            pows.append(pows[-1] * RabinKarp.base % RabinKarp.mod)
        return (self.pre[r+self.l] - self.pre[l+self.l]*pows[r-l]) % RabinKarp.mod
    def __getitem__(self, w):  # O(1) but costly
        if isinstance(w, int): return self.s[w+self.l]
        assert isinstance(w, slice)
        rk = RabinKarp()
        rk.s = self.s
        rk.pre = self.pre
        l, r, _ = w.indices(len(self))
        rk.l, rk.r = l+self.l, r+self.l
        return rk
    def __repr__(a): return f'RabinKarp({repr(a.s[a.l:a.r])})'
    def __len__(a): return a.r-a.l
    def __hash__(a): return a.query(0, len(a))
    def __eq__(a, b): return hash(a) == hash(b)
    def __le__(a, b): return a == b or a < b
    def __lt__(a, b):  # O(log n)
        lcp = a.lcp(b)
        if lcp == min(len(a), len(b)): return len(a) < len(b)
        return a[lcp] < b[lcp]
    def lcp(a, b):
        l, r = 0, min(len(a), len(b))
        while l < r:
            h = (l+r+1)//2
            if a.query(0, h) == b.query(0, h): l = h
            else: r = h-1
        return l

class Tree:
    def __init__(self, n, f=add, z=0):
        self.t = [z for _ in range(2*n)]
        self.n, self.f, self.z = n, f, z
    def update(self, i, v):
        i += self.n
        self.t[i] = v
        while i > 1:
            i //= 2
            self.t[i] = self.f(self.t[i*2], self.t[i*2+1])
    def query(self, l, r):
        L, R = self.z, self.z
        l += self.n
        r += self.n
        while l < r:
            if l&1:
                L = self.f(L, self.t[l])
                l += 1
            if r&1:
                r -= 1
                R = self.f(self.t[r], R)
            l //= 2
            r //= 2
        return self.f(L, R)

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
            self.Z[i] = j
        self.Z[0] = N

class Primes:  # ty 小羊肖恩, https://codeforces.com/blog/entry/54090
    def __init__(self, n):  # O(N)
        self.n = n
        self.primes = primes = []
        self.lp = lp = [0]*(n+1)
        self.phi = phi = [0]*(n+1)

        lp[1] = phi[1] = 1  # sig[1] = 1
        for i in range(2, n+1):
            if lp[i] == 0:
                lp[i] = i
                primes.append(i)
                phi[i] = i-1  # sig[i] = i+1
            for p in primes:
                if i*p > n: break
                lp[i*p] = p
                if p == lp[i]:
                    phi[i*p] = phi[i]*p  # sig[i*p] = sig[i]*(1+p) - sig[i//p]*p
                    break
                phi[i*p] = phi[i]*phi[p]

    def __getitem__(self, x):
        if isinstance(x, slice):  # O((W+sqR)lglgR)
            l, r = x.start or 0, x.stop
            P = [True]*(r-l)
            for i in range(2-l): P[i] = False
            for p in self.primes:
                if p*p > r: break
                for j in range(max(p*p, (l+p-1)//p*p), r, p):
                    P[j-l] = False
            return P
        if x < 2: return False
        if x <= self.n: return self.lp[x] == x  # O(1)
        for p in self.primes:  # O(sqX)
            if p*p > x: break
            if x%p == 0: return False
        return True

    def factorization(self, x):
        for p in self.primes:
            if p*p > x: break
            if x <= self.n: break
            if x%p == 0:
                cnt = 0
                while x%p == 0: cnt += 1; x //= p
                yield p, cnt
        while 1 < x <= self.n:
            p, cnt = self.lp[x], 0
            while x%p == 0: cnt += 1; x //= p
            yield p, cnt
        if x >= self.n and x > 1:
            yield x, 1

    def factors(self, x):
        res = [1]
        for p, b in self.factorization(x):
            n = len(res)
            for j in range(1, b+1):
                for d in res[:n]:
                    res.append(d * p**j)
        return res

    # def phi2(self, x, n):
    #     # Count integers <= x relatively prime to n
    #     # O(2^distinct_pf * distinct_pf)
    #     P = [p for p, k in self.factorization(n)]
    #     res = 0
    #     for k in range(0, len(P)+1):
    #         for pf in combinations(P, k):
    #             res += x//prod(pf) * (-1)**k
    #     return res

class TreeGraph:
    def __init__(self, E):
        self.A = defaultdict(list)
        for i, j in E:
            self.A[i].append(j)
            self.A[j].append(i)
    def farthest(self, i, p=-1):
        res = 0, i
        for j in self.A[i]:
            if j == p: continue
            d, k = self.farthest(j, i)
            res = max(res, (d+1, k))
        return res
    def diameter(self):
        if not self.A: return 0
        return self.farthest(self.farthest(0)[1])[0]
    # def dfs(self, i, p=None):
    #     yield i
    #     for j in self.A[i]:
    #         if j == p: continue
    #         yield from self.dfs(j, i)

# ORDERED SET
# from sortedcontainers import SortedList
# sl = SortedList(); sl.add(5); sl.index(5) == 1; sl.discard(5)

class WeightedGraph:
    def __init__(self, edges, weights, bi=False):
        self.a = defaultdict(list)
        for (i, j), w in zip(edges, weights):
            self.a[i].append((j, w))
            if bi: self.a[j].append((i, w))
    def dijkstra(self, i):
        d = {}
        q = [(0, i)]
        while q:
            t, i = heappop(q)
            if i in d: continue
            d[i] = t
            for j, w in self.a[i]:
                if j in d: continue
                heappush(q, (t+w, j))
        return d

class WeightedGraph:
    def __init__(self, edges, bi=False):
        self.a = defaultdict(list)
        for i, j, w in edges:
            self.a[i].append((j, w))
            if bi: self.a[j].append((i, w))
    def dijkstra(self, i):
        d = {}
        q = [(0, i)]
        while q:
            t, i = heappop(q)
            if i in d: continue
            d[i] = t
            for j, w in self.a[i]:
                if j in d: continue
                heappush(q, (t+w, j))
        return d

class MCFGraph:  # yawn sean
    class Edge(NamedTuple):
        src: int
        dst: int
        cap: int
        flow: int
        cost: int

    class _Edge:
        def __init__(self, dst: int, cap: int, cost: int) -> None:
            self.dst = dst
            self.cap = cap
            self.cost = cost
            self.rev: Optional[MCFGraph._Edge] = None

    def __init__(self, n: int) -> None:
        self._n = n
        self._g: List[List[MCFGraph._Edge]] = [[] for _ in range(n)]
        self._edges: List[MCFGraph._Edge] = []

    def add_edge(self, src: int, dst: int, cap: int, cost: int) -> int:
        assert 0 <= src < self._n
        assert 0 <= dst < self._n
        assert 0 <= cap
        m = len(self._edges)
        e = MCFGraph._Edge(dst, cap, cost)
        re = MCFGraph._Edge(src, 0, -cost)
        e.rev = re
        re.rev = e
        self._g[src].append(e)
        self._g[dst].append(re)
        self._edges.append(e)
        return m

    def get_edge(self, i: int) -> Edge:
        assert 0 <= i < len(self._edges)
        e = self._edges[i]
        re = cast(MCFGraph._Edge, e.rev)
        return MCFGraph.Edge(
            re.dst,
            e.dst,
            e.cap + re.cap,
            re.cap,
            e.cost
        )

    def edges(self) -> List[Edge]:
        return [self.get_edge(i) for i in range(len(self._edges))]

    def flow(self, s: int, t: int,
             flow_limit: Optional[int] = None) -> Tuple[int, int]:
        return self.slope(s, t, flow_limit)[-1]

    def slope(self, s: int, t: int,
              flow_limit: Optional[int] = None) -> List[Tuple[int, int]]:
        assert 0 <= s < self._n
        assert 0 <= t < self._n
        assert s != t
        if flow_limit is None:
            flow_limit = cast(int, sum(e.cap for e in self._g[s]))

        dual = [0] * self._n
        prev: List[Optional[Tuple[int, MCFGraph._Edge]]] = [None] * self._n

        def refine_dual() -> bool:
            pq = [(0, s)]
            visited = [False] * self._n
            dist: List[Optional[int]] = [None] * self._n
            dist[s] = 0
            while pq:
                dist_v, v = heappop(pq)
                if visited[v]:
                    continue
                visited[v] = True
                if v == t:
                    break
                dual_v = dual[v]
                for e in self._g[v]:
                    w = e.dst
                    if visited[w] or e.cap == 0:
                        continue
                    reduced_cost = e.cost - dual[w] + dual_v
                    new_dist = dist_v + reduced_cost
                    dist_w = dist[w]
                    if dist_w is None or new_dist < dist_w:
                        dist[w] = new_dist
                        prev[w] = v, e
                        heappush(pq, (new_dist, w))
            else:
                return False
            dist_t = dist[t]
            for v in range(self._n):
                if visited[v]:
                    dual[v] -= cast(int, dist_t) - cast(int, dist[v])
            return True

        flow = 0
        cost = 0
        prev_cost_per_flow: Optional[int] = None
        result = [(flow, cost)]
        while flow < flow_limit:
            if not refine_dual():
                break
            f = flow_limit - flow
            v = t
            while prev[v] is not None:
                u, e = cast(Tuple[int, MCFGraph._Edge], prev[v])
                f = min(f, e.cap)
                v = u
            v = t
            while prev[v] is not None:
                u, e = cast(Tuple[int, MCFGraph._Edge], prev[v])
                e.cap -= f
                assert e.rev is not None
                e.rev.cap += f
                v = u
            c = -dual[s]
            flow += f
            cost += f * c
            if c == prev_cost_per_flow:
                result.pop()
            result.append((flow, cost))
            prev_cost_per_flow = c
        return result