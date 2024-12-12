def bellman_ford(V, edges, src):
    dist = [float('inf')] * V
    dist[src] = 0

    for _ in range(V - 1):
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    if any(dist[u] + w < dist[v] for u, v, w in edges):
        print("Graph contains a negative-weight cycle")
        return
    print("Vertex\tDistance")
    for i, d in enumerate(dist):
        print(f"{i}\t{d}")

# Input Reading
V = int(input("Vertices: "))
edges = [tuple(map(int, input("Edge (src, dest, weight): ").split())) 
for _ in range(int(input("Edges: ")))]
bellman_ford(V, edges, int(input("Source: ")))