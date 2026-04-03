#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vert_num;
    struct Node *next;
} Node;

Node ** make_graph (int v) {
    Node **graph;

    if((graph = (Node**)malloc(sizeof(Node*)*v)) == NULL) {
        printf("malloc returns NULL");
        return NULL; 
    }
    for(int i = 0; i < v; ++i) {  // обнуляю граф вначале
        graph[i] = NULL;
    }
    return graph;
}

Node * find_last(Node * head) {
    Node * temp = head;

    while(temp != NULL && temp->next != NULL) {
        temp = temp->next;     
    }    
    return temp;
}

void add_vertex(Node ** graph, int v ) {

    int vert1, vert2;

    for(int i = 0; i < v; ++i) {

        printf("Ребро №%d", i+1);

        if(scanf("%d %d", &vert1, &vert2)!= 2 && !((vert1 || vert2)<0) && !((vert1 || vert2)>v)) {
            printf("n/a");
            free_graph(graph, v); 
            return 0;
        }

        Node *new_node = malloc(sizeof(Node));
        
        if(graph[vert1 -1] ==NULL) graph[vert1-1] = new_node;

        Node *ptr = graph[vert1 - 1]->next;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->vert_num = vert2;
        new_node->next = NULL;

    }
    

}

int main(void) {

    int v, e;
    printf("Введите кол-во вершин:\n");
    scanf("%d", &v);
    printf("Введите кол-во ребер:\n");
    scanf("%d", &e);

    Node **graph = make_graph(v);
    printf("Перечислите точки, которые связывает ребро");
    add_vertex(graph, v);









}