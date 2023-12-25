from utils import *
import networkx as nx

lines = readlines('25.in')

V = set()
G = nx.Graph()
for e, line in enumerate(lines):
    i, rest = line.split(': ')
    for j in rest.split(' '):
        G.add_edge(i, j, capacity=1)
        V |= {i, j}

V = list(V)
N = len(V)
for j in range(N):
    for i in range(j):
        cut, groups = nx.minimum_cut(G, V[i], V[j])
        if cut != 3: continue
        assert len(groups) == 2
        print(prod(map(len, groups)))