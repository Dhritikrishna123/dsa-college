#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void bfs(struct Graph* graph, int startVertex) {
    int queue[100], front = 0, rear = 0;
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = graph->adjLists[curr];
        while (temp) {
            int neighbor = temp->vertex;
            if (!graph->visited[neighbor]) {
                graph->visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("BFS: ");
    bfs(graph, 0);
    printf("\n");

    return 0;
}
// Updated on 2026-04-22
