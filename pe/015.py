# (2n)!/(n!)^2

MOD = 344555666677777

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

N = 20

res = mint(1)
for i in range(N+1, 2*N+1): res *= i
for i in range(1, N+1): res /= i

print(res)