#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

struct Vertex {
    int identification;
    struct Vertex* next_vertex;
};

struct Network {
    int total_nodes;
    struct Vertex* node_adjacency_list[MAX_NODES];
    int is_visited[MAX_NODES];
};

struct Network* initializeNetwork(int total_nodes) {
    struct Network* network = (struct Network*)malloc(sizeof(struct Network));
    network->total_nodes = total_nodes;

    for (int i = 0; i < total_nodes; ++i) {
        network->node_adjacency_list[i] = NULL;
        network->is_visited[i] = 0;
    }

    return network;
}

void addConnection(struct Network* network, int source, int destination) {
    struct Vertex* newVertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    newVertex->identification = destination;
    newVertex->next_vertex = network->node_adjacency_list[source];
    network->node_adjacency_list[source] = newVertex;

    newVertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    newVertex->identification = source;
    newVertex->next_vertex = network->node_adjacency_list[destination];
    network->node_adjacency_list[destination] = newVertex;
}

void depthFirstSearch(struct Network* network, int vertex) {
    network->is_visited[vertex] = 1;
    struct Vertex* adjVertex = network->node_adjacency_list[vertex];
    while (adjVertex != NULL) {
        if (!network->is_visited[adjVertex->identification]) {
            depthFirstSearch(network, adjVertex->identification);
        }
        adjVertex = adjVertex->next_vertex;
    }
}

int numberOfConnectedComponents(struct Network* network) {
    int count = 0;
    for (int i = 0; i < network->total_nodes; ++i) {
        if (!network->is_visited[i]) {
            depthFirstSearch(network, i);
            count++;
        }
    }
    return count;
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void calculateComponentSizes(struct Network* network) {
    int component_sizes[MAX_NODES] = {0};
    int count = 0;
    for (int i = 0; i < network->total_nodes; ++i) {
        network->is_visited[i] = 0;
    }
    for (int i = 0; i < network->total_nodes; ++i) {
        if (!network->is_visited[i]) {
            for (int i = 0; i < network->total_nodes; ++i) network->is_visited[i] = 0;
            int size = 0;
            depthFirstSearch(network, i);
            for (int j = 0; j < network->total_nodes; ++j) {
                if (network->is_visited[j]) {
                    size++;
                }
            }
            component_sizes[count++] = size;
        }
    }
    bubbleSort(component_sizes, count);
    for (int i = 0; i < count; ++i) {
        printf("%d ", component_sizes[i]);
    }
    printf("\n");
}

int timer = 1;
void findBridgesUtil(struct Network* network, int u, int visited[], int disc[], int low[], int parent[], int* bridge_count) {
    visited[u] = 1;
    disc[u] = low[u] = timer;
    timer++;
    struct Vertex* adjVertex = network->node_adjacency_list[u];
    while (adjVertex != NULL) {
        int v = adjVertex->identification;
        if(v == parent[u]){
            adjVertex = adjVertex->next_vertex;
            continue;
        }
        if (visited[v] == 0) {
            parent[v] = u;
            findBridgesUtil(network, v, visited, disc, low, parent, bridge_count);
            low[u] = low[u] < low[v] ? low[u] : low[v];
            if (low[v] > disc[u]) {
                (*bridge_count)++;
                // printf("%d %d\n", u + 1, v + 1); // This line prints the bridge edge
            }
        } 
        else {
           low[u] = low[u] < low[v] ? low[u] : low[v];
        }
        adjVertex = adjVertex->next_vertex;
    }
}

void numberOfBridges(struct Network* network) {
    int visited[MAX_NODES] = {0};
    int disc[MAX_NODES] = {0};
    int low[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};
    int bridge_count = 0;
    int count = 0;
    for (int i = 0; i < network->total_nodes; ++i) {
        if (!visited[i]) {
            timer = 1;
            findBridgesUtil(network, i, visited, disc, low, parent, &bridge_count);
            count += bridge_count;
        }
    }
    printf("%d\n", count);
    // if(bridge_count == 0)
    //     printf("-1\n");
    // else{
    //     if(bridge_count%2 == 0) printf("%d\n", bridge_count/2);
    //     else printf("%d\n", (bridge_count/2)+1);
    // }
    
}

void findArticulationPointsUtil(struct Network* network, int u, int visited[], int disc[], int low[], int parent[], int ap[], int* ap_count) {
    visited[u] = 1;
    int children = 0;
    disc[u] = low[u] = ++(*ap_count);
    struct Vertex* adjVertex = network->node_adjacency_list[u];
    while (adjVertex != NULL) {
        int v = adjVertex->identification;
        if (!visited[v]) {
            children++;
            parent[v] = u;
            findArticulationPointsUtil(network, v, visited, disc, low, parent, ap, ap_count);
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
        adjVertex = adjVertex->next_vertex;
    }
}

void numberOfArticulationPoints(struct Network* network) {
    int visited[MAX_NODES] = {0};
    int disc[MAX_NODES] = {0};
    int low[MAX_NODES] = {0};
    int parent[MAX_NODES] = {-1};
    int ap[MAX_NODES] = {0};
    int ap_count = 0;
    for (int i = 0; i < network->total_nodes; ++i) {
        if (!visited[i]) {
            findArticulationPointsUtil(network, i, visited, disc, low, parent, ap, &ap_count);
        }
    }
    int count = 0;
    for (int i = 0; i < network->total_nodes; ++i) {
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

int main()
{
    int total_nodes;
    scanf("%d", &total_nodes);

    struct Network* network = initializeNetwork(total_nodes);
    int node_id, num_adjacent;
    for (int i = 0; i < total_nodes; ++i) {
        scanf("%d", &node_id);
        scanf("%d", &num_adjacent);
        for (int j = 0; j < num_adjacent; ++j) {
            int adj_node;
            scanf("%d", &adj_node);
            addConnection(network, node_id - 1, adj_node - 1);
        }
    }

   


    char option;
    do {
        scanf(" %c", &option);
        switch (option) {
            case 'n':
                printf("%d\n", numberOfConnectedComponents(network));
                break;
            case 's':
                calculateComponentSizes(network);
                break;
            case 'b':
                numberOfBridges(network);
                break;
            case 'a':
                numberOfArticulationPoints(network);
                break;
            case 't':
                return 0;
                break;
        }
    } while (option != 't');


    return 0;
}
