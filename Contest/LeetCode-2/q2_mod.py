
INF = float('inf')

def floyd_warshall(graph):
    num_vertices = len(graph)
    dist = {[INF] * num_vertices for _ in range(num_vertices)}

    # Initialize distance matrix with edge weights
    for i in range(num_vertices):
        for j in range(num_vertices):
            if i == j:
                dist[i][j] = 0
            elif graph[i][j] != 0:
                dist[i][j] = graph[i][j]

    # Perform the Floyd-Warshall algorithm
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if dist[i][k] != INF and dist[k][j] != INF and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    return dist

# Example usage:
graph = [
    [0, 3, 0, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 7, 0],
    [0, 2, 0, 0, 0],
    [0, 0, 0, 1, 0]
]


original = ["a","b","c","c","e","d"]
changed = ["b","c","b","e","b","e"]
cost = [2,5,5,1,2,20]
source = "abcd"
target = "acbe"
result_dist = floyd_warshall(graph)
 
