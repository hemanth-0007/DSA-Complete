#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

struct Node {
    int label;
    struct Node* next;
};

struct Graph {
    int num_nodes;
    struct Node* adjacency_list[MAX_NODES];
    int visited[MAX_NODES];
};

struct Graph* createGraph(int num_nodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;

    for (int i = 0; i < num_nodes; ++i) {
        graph->adjacency_list[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->label = dest;
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->label = src;
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}

void DFS(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    struct Node* adjNode = graph->adjacency_list[vertex];
    while (adjNode != NULL) {
        if (!graph->visited[adjNode->label]) {
            DFS(graph, adjNode->label);
        }
        adjNode = adjNode->next;
    }
}

int noOfConnectedComponents(struct Graph* graph) {
    int count = 0;
    for (int i = 0; i < graph->num_nodes; ++i) {
        if (!graph->visited[i]) {
            DFS(graph, i);
            count++;
        }
    }
    return count;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sizeOfComponents(struct Graph* graph) {
    int component_sizes[MAX_NODES] = {0};
    int count = 0;
    for (int i = 0; i < graph->num_nodes; ++i) {
        graph->visited[i] = 0;
    }
    for (int i = 0; i < graph->num_nodes; ++i) {
        if (!graph->visited[i]) {
            int size = 0;
            DFS(graph, i);
            for (int j = 0; j < graph->num_nodes; ++j) {
                if (graph->visited[j]) {
                    size++;
                }
            }
            component_sizes[count++] = size;
        }
    }
    sort(component_sizes, count);
    for (int i = 0; i < count; ++i) {
        printf("%d ", component_sizes[i]);
    }
    printf("\n");
}
void bridgeUtil(struct Graph* graph, int u, int visited[], int disc[], int low[], int parent[], int* bridge_count) {
    visited[u] = 1;
    disc[u] = low[u] = ++(*bridge_count);
    struct Node* adjNode = graph->adjacency_list[u];
    while (adjNode != NULL) {
        int v = adjNode->label;
        if (!visited[v]) {
            parent[v] = u;
            bridgeUtil(graph, v, visited, disc, low, parent, bridge_count);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if (low[v] > disc[u]) {
                printf("%d %d\n", u + 1, v + 1); // This line prints the bridge edge
            }
        } else if (v != parent[u]) {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
        adjNode = adjNode->next;
    }
}

void noOfBridges(struct Graph* graph) {
    int visited[MAX_NODES] = {0};
    int disc[MAX_NODES] = {0};
    int low[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};
    int bridge_count = 0;
    for (int i = 0; i < graph->num_nodes; ++i) {
        if (!visited[i]) {
            bridgeUtil(graph, i, visited, disc, low, parent, &bridge_count);
        }
    }
}


void APUtil(struct Graph* graph, int u, int visited[], int disc[], int low[], int parent[], int ap[], int* ap_count) {
    visited[u] = 1;
    int children = 0;
    disc[u] = low[u] = ++(*ap_count);
    struct Node* adjNode = graph->adjacency_list[u];
    while (adjNode != NULL) {
        int v = adjNode->label;
        if (!visited[v]) {
            children++;
            parent[v] = u;
            APUtil(graph, v, visited, disc, low, parent, ap, ap_count);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if (parent[u] == -1 && children > 1) {
                ap[u] = 1;
            }
            if (parent[u] != -1 && low[v] >= disc[u]) {
                ap[u] = 1;
            }
        } else if (v != parent[u]) {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
        adjNode = adjNode->next;
    }
}

void noOfArticulationPoints(struct Graph* graph) {
    int visited[MAX_NODES] = {0};
    int disc[MAX_NODES] = {0};
    int low[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};
    int ap[MAX_NODES] = {0};
    int ap_count = 0;
    for (int i = 0; i < graph->num_nodes; ++i) {
        if (!visited[i]) {
            APUtil(graph, i, visited, disc, low, parent, ap, &ap_count);
        }
    }
    int count = 0;
    for (int i = 0; i < graph->num_nodes; ++i) {
        if (ap[i]) {
            count++;
        }
    }
    if (count == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", count);
    }
}

int main() {
    int num_nodes;
    scanf("%d", &num_nodes);

    struct Graph* graph = createGraph(num_nodes);
    int label, num_adjacent;
    for (int i = 0; i < num_nodes; ++i) {
        scanf("%d", &label);
        scanf("%d", &num_adjacent);
        for (int j = 0; j < num_adjacent; ++j) {
            int adj_node;
            scanf("%d", &adj_node);
            addEdge(graph, label - 1, adj_node - 1);
        }
    }

    char choice;
    while (1) {
        scanf(" %c", &choice);
        if (choice == 'n') {
            int connected_components = noOfConnectedComponents(graph);
            printf("%d\n", connected_components);
        } else if (choice == 's') {
            sizeOfComponents(graph);
        } else if (choice == 'b') {
            noOfBridges(graph);
        } else if (choice == 'a') {
            noOfArticulationPoints(graph);
        } else if (choice == 't') {
            break;
        }
    }

    return 0;
}