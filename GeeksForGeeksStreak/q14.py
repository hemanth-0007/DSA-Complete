
class Solution:
    def topologicalSortUtil(self, v, visited, stack, graph):
        visited[v] = True
        for i in graph[v]:
            if not visited[i]:
                self.topologicalSortUtil(i, visited, stack, graph)
        stack.insert(0, v)

    def findOrder(self, n,m, prerequisites):
        graph = {}
        for i in range(n):
            graph[i] = []
        for i in range(len(prerequisites)):
            graph[prerequisites[i][1]].append(prerequisites[i][0])
        # print(graph)
        visited = [False] * n
        stack = []
        for i in range(n):
            if not visited[i]:
                self.topologicalSortUtil(i, visited, stack, graph)
        # print(stack)
        return stack



n = 4
m = 4
prerequisites = [[1, 0],[2, 0],[3, 1], [3, 2]]
solution = Solution()
print(solution.findOrder(n, prerequisites))
