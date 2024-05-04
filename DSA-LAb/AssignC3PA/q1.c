#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100

struct Node {
    int label;
    bool visited;
    int num_neighbors;
    struct Node* neighbors[MAX_NODES];
};

struct Graph {
    int num_nodes;
    struct Node* nodes[MAX_NODES];
    int visited[MAX_NODES];
};

struct Node* createNode(int label) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->label = label;
    newNode->visited = false;
    newNode->num_neighbors = 0;
    return newNode;
}

void addEdge(struct Node* source, struct Node* dest) {
    source->neighbors[source->num_neighbors++] = dest;
    dest->neighbors[dest->num_neighbors++] = source;
}

 
 

void DFS(int ind, struct Graph* graph) {
    graph->visited[ind] = true;
    printf("Node %d is visited\n", graph->nodes[ind]->label);
    for (int i = 0; i < graph->nodes[ind]->num_neighbors; i++) {
        // printf("Checking neighbor %d\n", graph->nodes[ind]->neighbors[i]->label);
        if (!(graph->visited[graph->nodes[ind]->neighbors[i]->label])) {
            DFS(i , graph);
        }
    }
}

int noOfConnectedComponents(struct Graph* graph) {
    int count = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (!(graph->visited[i])) {
            printf("Node %d is not visited\n", graph->nodes[i]->label);
            DFS(i, graph);
            count++;
            printf("\tEnd of component%d\n", count);
        }
    }
    // Resetting visited flags for future use
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->visited[i] = false;
    }
    return count;
}

void componentDFS(struct Node* node, int* size) {
    node->visited = true;
    (*size)++;
    for (int i = 0; i < node->num_neighbors; i++) {
        if (!(node->neighbors[i]->visited)) {
            componentDFS(node->neighbors[i], size);
        }
    }
}

void sizeOfComponents(struct Graph* graph) {
    int component_sizes[MAX_NODES] = {0};
    int component_count = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (!(graph->nodes[i]->visited)) {
            int size = 0;
            componentDFS(graph->nodes[i], &size);
            component_sizes[component_count++] = size;
        }
    }
    // Sorting component sizes in increasing order
    for (int i = 0; i < component_count - 1; i++) {
        for (int j = 0; j < component_count - i - 1; j++) {
            if (component_sizes[j] > component_sizes[j + 1]) {
                int temp = component_sizes[j];
                component_sizes[j] = component_sizes[j + 1];
                component_sizes[j + 1] = temp;
            }
        }
    }
    // Printing sizes of components
    for (int i = 0; i < component_count; i++) {
        printf("%d ", component_sizes[i]);
    }
    printf("\n");
    // Resetting visited flags for future use
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->nodes[i]->visited = false;
    }
}

void bridgeDFS(struct Node* node, struct Node* parent, int* time, int* disc, int* low, int* bridges) {
    node->visited = true;
    disc[node->label] = low[node->label] = ++(*time);
    for (int i = 0; i < node->num_neighbors; i++) {
        struct Node* neighbor = node->neighbors[i];
        if (!(neighbor->visited)) {
            bridgeDFS(neighbor, node, time, disc, low, bridges);
            low[node->label] = (low[node->label] < low[neighbor->label]) ? low[node->label] : low[neighbor->label];
            if (low[neighbor->label] > disc[node->label]) {
                (*bridges)++;
            }
        } else if (neighbor != parent) {
            low[node->label] = (low[node->label] < disc[neighbor->label]) ? low[node->label] : disc[neighbor->label];
        }
    }
}

int noOfBridges(struct Graph* graph) {
    int bridges = 0;
    int time = 0;
    int disc[MAX_NODES], low[MAX_NODES];
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->nodes[i]->visited = false;
        disc[i] = low[i] = 0;
    }
    for (int i = 0; i < graph->num_nodes; i++) {
        if (!(graph->nodes[i]->visited)) {
            bridgeDFS(graph->nodes[i], NULL, &time, disc, low, &bridges);
        }
    }
    if (bridges == 0) return -1;
    return bridges;
}

void APUtil(struct Node* node, int* disc, int* low, int* parent, bool* ap, int* time) {
    int children = 0;
    node->visited = true;
    disc[node->label] = low[node->label] = ++(*time);
    for (int i = 0; i < node->num_neighbors; i++) {
        struct Node* neighbor = node->neighbors[i];
        if (!(neighbor->visited)) {
            children++;
            parent[neighbor->label] = node->label;
            APUtil(neighbor, disc, low, parent, ap, time);
            low[node->label] = (low[node->label] < low[neighbor->label]) ? low[node->label] : low[neighbor->label];
            if (parent[node->label] == -1 && children > 1)
                ap[node->label] = true;
            if (parent[node->label] != -1 && low[neighbor->label] >= disc[node->label])
                ap[node->label] = true;
        } else if (neighbor->label != parent[node->label]) {
            low[node->label] = (low[node->label] < disc[neighbor->label]) ? low[node->label] : disc[neighbor->label];
        }
    }
}

int noOfArticulationPoints(struct Graph* graph) {
    int articulation_points = 0;
    int time = 0;
    int disc[MAX_NODES], low[MAX_NODES], parent[MAX_NODES];
    bool ap[MAX_NODES] = {false};
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->nodes[i]->visited = false;
        disc[i] = low[i] = parent[i] = -1;
    }
    for (int i = 0; i < graph->num_nodes; i++) {
        if (!(graph->nodes[i]->visited)) {
            APUtil(graph->nodes[i], disc, low, parent, ap, &time);
        }
    }
    for (int i = 0; i < graph->num_nodes; i++)
        if (ap[i]) articulation_points++;
    if (articulation_points == 0) return -1;
    return articulation_points;
}


int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (!graph) {
    printf("Memory allocation failed!\n");
    return -1;
    }
    scanf("%d", &graph->num_nodes);
    for (int i = 0; i < graph->num_nodes; i++) {
        graph->visited[i] = 0;
    }

   for (int i = 0; i < graph->num_nodes; i++) {
        // Given a string s, extract numbers from it
        char s[1000];
        // Scan until new line
        scanf(" %[^\n]%*c", s);
        int j = 0;
        int flag = 0;
        int cur_node_label;
        while (j < strlen(s)) {
            int num = 0;
            while (s[j] >= '0' && s[j] <= '9') {
                num = num * 10 + (s[j] - '0');
                j++;
            }
            // printf("num = %d\n", num);
            num -= 1;
            if (flag == 0) {
                // printf("Creating node %d\n", num);
                cur_node_label = num;
                graph->nodes[i] = createNode(cur_node_label);
                flag = 1;
            } else {
                // printf("Adding edge between %d and %d\n", cur_node_label, num);
                struct Node* dest = createNode(num);
                addEdge(graph->nodes[cur_node_label], dest); // Adjusting indices to start from 0
            }
            j++;
        }
    }

 

    // for(int i = 0; i < graph->num_nodes; i++) {
    //     printf("Node %d: ", graph->nodes[i]->label);
    //     for (int j = 0; j < graph->nodes[i]->num_neighbors; j++) {
    //         printf("%d ", graph->nodes[i]->neighbors[j]->label);
    //     }
    //     printf("\n");
    // }

    char option;
    do {
        scanf(" %c", &option);
        switch (option) {
            case 'n':
                printf("%d\n", noOfConnectedComponents(graph));
                break;
            case 's':
                sizeOfComponents(graph);
                break;
            case 'b':
                printf("%d\n", noOfBridges(graph));
                break;
            case 'a':
                printf("%d\n", noOfArticulationPoints(graph));
                break;
            case 't':
                return 0;
                break;
        }
    } while (option != 't');

 

    return 0;
}