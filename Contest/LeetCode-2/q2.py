
import heapq
import string

def add_node(nodes, edges, value):
    nodes.add(value)
    edges[value] = []
    
def add_edge( edges, from_node, to_node, weight):
    edges[from_node].append((to_node, weight))
        
        
def dijkstra(nodes, edges, start, end):
    priority_queue = [(0, start)]
    visited = set()
    distances = {node: float('infinity') for node in nodes}
    distances[start] = 0
    
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        if current_node in visited:
            continue
        
        visited.add(current_node)
        
        for neighbor, weight in edges[current_node]:
            distance = current_distance + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances[end]

nodes = set()
edges = {}


original = ["a","b","c","c","e","d"]
changed = ["b","c","b","e","b","e"]
cost = [2,5,5,1,2,20]
source = "abcd"
target = "acbe"

for node in string.ascii_lowercase:
    add_node(nodes, edges, node)
for i in range(len(cost)):
    add_edge(edges, original[i], changed[i], cost[i])
min_cost = 0
for i in range(len(source)):
    if source[i] != target[i]:
        min_cost += dijkstra(nodes, edges,source[i], target[i])
print(min_cost)


