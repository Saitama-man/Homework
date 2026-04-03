#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Node {
    int v_num;
    int weight;
    struct Node *next;
} Node;

Node* create_node(int v, int w) {
    Node* new = malloc(sizeof(Node));
    if (!new) return NULL;
    new->v_num = v;
    new->weight = w;
    new->next = NULL;
    return new;
}

// очистка графа
void free_graph(Node **graph, int v_count) {
    for (int i = 0; i < v_count; i++) {
        Node *temp = graph[i];
        while (temp) {
            Node *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(graph);
}

// добавление ребра
void add_edge(Node **graph, int start, int end, int w) {
    Node *new = create_node(end, w);
    new->next = graph[start - 1];
    graph[start - 1] = new;
}

// рекурсивный вывод пути
void print_path(int *parent, int j) {
    if (j == -1) return;
    print_path(parent, parent[j]);
    if (parent[j] != -1) printf(" -> ");
    printf("%d", j + 1);
}

// релаксация ребер
void relax(Node **graph, int *dist, int *parent, int u) {
    Node *tmp = graph[u];
    while (tmp) {
        int v = tmp->v_num - 1;
        if (dist[u] != INF && dist[u] + tmp->weight < dist[v]) {
            dist[v] = dist[u] + tmp->weight;
            parent[v] = u;
        }
        tmp = tmp->next;
    }
}

void dijkstra(Node **graph, int v_count, int start) {
    int *dist = malloc(sizeof(int) * v_count);
    int *parent = malloc(sizeof(int) * v_count);
    int *vis = calloc(v_count, sizeof(int));
    for (int i = 0; i < v_count; i++) { dist[i] = INF; parent[i] = -1; }
    dist[start - 1] = 0;

    for (int i = 0; i < v_count; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < v_count; j++)
            if (!vis[j] && dist[j] < min) { min = dist[j]; u = j; }
        if (u == -1) break;
        vis[u] = 1;
        relax(graph, dist, parent, u);
    }
    for (int i = 0; i < v_count; i++) {
        if (i == start - 1) continue;
        printf("До %d (вес %d): ", i + 1, dist[i]);
        if (dist[i] == INF) printf("нет пути\n");
        else { print_path(parent, i); printf("\n"); }
    }
    free(dist); free(parent); free(vis);
}

int main() {
    int v, e, dir, v1, v2, w, start;
    printf("Ориентированный? (1-да, 0-нет): "); scanf("%d", &dir);
    printf("Вершин и ребер: "); scanf("%d %d", &v, &e);
    Node **graph = calloc(v, sizeof(Node*));
    printf("Введите ребра (откуда куда вес):\n");
    for (int i = 0; i < e; i++) {
        if (scanf("%d %d %d", &v1, &v2, &w) == 3) {
            add_edge(graph, v1, v2, w);
            if (!dir) add_edge(graph, v2, v1, w);
        }
    }
    printf("Старт: "); scanf("%d", &start);
    if (start > 0 && start <= v) dijkstra(graph, v, start);
    free_graph(graph, v);
    return 0;
}