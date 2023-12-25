from utils import *

lines = readlines('25.in')

start = perf_counter()

edges = []
idx = {}
for line in lines:
    tmp = line.replace(': ', ' ')
    for word in tmp.split(' '):
        if word in idx: continue
        idx[word] = len(idx)

for e, line in enumerate(lines):
    i, rest = line.split(': ')
    i = idx[i]
    for j in rest.split(' '):
        j = idx[j]
        edges.append((i, j))

def sol(edges):
    N = len(idx)
    dsu = DSU(N)
    joined = 0
    for i, j in edges:
        # print(i, j)
        if dsu.find(i) != dsu.find(j): joined += 1
        dsu.union(i, j)
        if joined == N-1: break
    cnt = Counter()
    for i in range(N):
        cnt[dsu.find(i)] += 1
    print(cnt)
    if len(cnt) == 2:
        a, b = list(cnt.values())
        print(a*b)

res = []

# Source: https://www.geeksforgeeks.org/bridge-in-a-graph/

# Python program to find bridges in a given undirected graph
#Complexity : O(V+E)

from collections import defaultdict

#This class represents an undirected graph using adjacency list representation
class Graph:

    def __init__(self,vertices):
        self.V= vertices #No. of vertices
        self.graph = defaultdict(list) # default dictionary to store graph
        self.Time = 0

    # function to add an edge to graph
    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    '''A recursive function that finds and prints bridges
    using DFS traversal
    u --> The vertex to be visited next
    visited[] --> keeps track of visited vertices
    disc[] --> Stores discovery times of visited vertices
    parent[] --> Stores parent vertices in DFS tree'''
    def bridgeUtil(self,u, visited, parent, low, disc):

        # Mark the current node as visited and print it
        visited[u]= True

        # Initialize discovery time and low value
        disc[u] = self.Time
        low[u] = self.Time
        self.Time += 1

        #Recur for all the vertices adjacent to this vertex
        for v in self.graph[u]:
            # If v is not visited yet, then make it a child of u
            # in DFS tree and recur for it
            if visited[v] == False :
                parent[v] = u
                self.bridgeUtil(v, visited, parent, low, disc)

                # Check if the subtree rooted with v has a connection to
                # one of the ancestors of u
                low[u] = min(low[u], low[v])


                ''' If the lowest vertex reachable from subtree
                under v is below u in DFS tree, then u-v is
                a bridge'''
                if low[v] > disc[u]:
                    res.append((u, v))


            elif v != parent[u]: # Update low value of u for parent function calls.
                low[u] = min(low[u], disc[v])


    # DFS based function to find all bridges. It uses recursive
    # function bridgeUtil()
    def bridge(self):

        # Mark all the vertices as not visited and Initialize parent and visited,
        # and ap(articulation point) arrays
        visited = [False] * (self.V)
        disc = [float("Inf")] * (self.V)
        low = [float("Inf")] * (self.V)
        parent = [-1] * (self.V)

        # Call the recursive helper function to find bridges
        # in DFS tree rooted with vertex 'i'
        for i in range(self.V):
            if visited[i] == False:
                self.bridgeUtil(i, visited, parent, low, disc)

print(len(edges), 'edges')
N = len(idx)

for c in range(len(edges)):
    for b in range(c):
        g = Graph(N)
        for e, (i, j) in enumerate(edges):
            if e == b or e == c: continue
            g.addEdge(i, j)
        g.bridge()
        if not res: continue
        for e, edge in enumerate(edges):
            if sorted(edge) == sorted(res[0]):
                a = e
        a, b, c = sorted([a, b, c])
        del edges[c], edges[b], edges[a]
        sol(edges)
        print(f'Finished in {perf_counter()-start:.3f}s')
        exit()