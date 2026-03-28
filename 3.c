#include <stdio.h>

#define MAXN 100
#define MAXM 1000
#define MAXE (2 * MAXM)
#define INF 1000000000

typedef struct {
    int n;

    int head[MAXN];
    int to[MAXE];
    int next[MAXE];
    int edge_cnt;

    int visited[MAXN];

    int cur_path[MAXN];
    int cur_len;

    int best_path[MAXN];
    int best_len;
} GraphCtx;

static void init_graph(GraphCtx *g, int n) {
    g->n = n;
    g->edge_cnt = 0;
    for (int i = 0; i < n; i++) {
        g->head[i] = -1;
        g->visited[i] = 0;
    }
    g->cur_len = 0;
    g->best_len = INF;
}

static void add_edge(GraphCtx *g, int u, int v) {
    int e = g->edge_cnt++;
    g->to[e] = v;
    g->next[e] = g->head[u];
    g->head[u] = e;
}

static void save_best(GraphCtx *g) {
    for (int i = 0; i < g->cur_len; i++) g->best_path[i] = g->cur_path[i];
    g->best_len = g->cur_len;
}

static void dfs_shortest(GraphCtx *g, int v, int target) {
    if (g->cur_len >= g->best_len) return;

    if (v == target) {
        save_best(g);
        return;
    }

    for (int e = g->head[v]; e != -1; e = g->next[e]) {
        int u = g->to[e];
        if (!g->visited[u]) {
            g->visited[u] = 1;
            g->cur_path[g->cur_len++] = u;

            dfs_shortest(g, u, target);

            g->cur_len--;
            g->visited[u] = 0;
        }
    }
}

int main(void) {
    int n, m;

    printf("Введите количество вершин и рёбер (n m): ");
    if (scanf("%d %d", &n, &m) != 2) return 0;
    if (n <= 0 || n > MAXN) return 0;
    if (m < 0 || m > MAXM) return 0;

    GraphCtx g;
    init_graph(&g, n);

    printf("Введите %d ребра/ребер (u v):\n", m);
    printf("(нумерация вершин: 0..%d)\n", n - 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Ребро %d: ", i + 1);
        if (scanf("%d %d", &u, &v) != 2) return 0;
        if (u < 0 || u >= n || v < 0 || v >= n) return 0;

        add_edge(&g, u, v);
        add_edge(&g, v, u); // убрать для ориентированного
    }

    int s, t;
    printf("Введите начальную и конечную вершины (s t): ");
    if (scanf("%d %d", &s, &t) != 2) return 0;
    if (s < 0 || s >= n || t < 0 || t >= n) return 0;

    g.visited[s] = 1;
    g.cur_path[0] = s;
    g.cur_len = 1;

    dfs_shortest(&g, s, t);

    if (g.best_len == INF) {
        printf("Путь не найден\n");
        return 0;
    }

    printf("Кратчайший путь (в рёбрах): %d\n", g.best_len - 1);
    printf("Путь: ");
    for (int i = 0; i < g.best_len; i++) {
        if (i) printf(" ");
        printf("%d", g.best_path[i]);
    }
    printf("\n");

    return 0;
}