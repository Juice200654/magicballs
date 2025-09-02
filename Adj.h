#ifndef _GRAPH_H_  
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxVertices 100

typedef struct Node{
    int vertex;
    struct Node* next;
}Node;

typedef struct ListGraph{
    int vertex;
    bool is_directed;
    Node* List[MaxVertices];
}ListGraph;

Node* creatNode(int vertex){
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}
ListGraph* creatLG(int vertex,bool is_directed){
    ListGraph* LG = (ListGraph*)malloc(sizeof(ListGraph));
    LG->vertex = vertex;
    LG->is_directed = is_directed;
    for (int i=1; i<=vertex; i++){
        LG->List[i] = creatNode(i);
    }
    return LG;
}

void AddEdge(int from, int to,ListGraph* LG){
    if (from < 0 || from > LG->vertex || to < 0 || to > LG->vertex){
        printf("数组索引越界");
        return;
    }
    Node* current = LG->List[from];
    Node* newnode = creatNode(to);
    while (current->next){
        current = current->next;
    }
    current->next = newnode;
    /*头插法
    Node* newnode = creatNode(to);
    newnode->next = LG->List[from]->next;
    LG->List[from]->next = newnode;
    }
    */
    if (!LG->is_directed){
    Node* reNode = creatNode(from);
    reNode->next = LG->List[to]->next;
    LG->List[to]->next = reNode;
    }
}

void printLG(ListGraph* LG){
    printf("邻接表表示:\n");
    for (int i = 1; i <= LG->vertex; i++) {
        Node* current = LG->List[i];
        printf("顶点 %d: ", current->vertex);
        
        current = current->next;  // 跳过头节点
        while (current) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(ListGraph* LG) {
    if (!LG) return;
    
    // 释放每个顶点的邻接表
    for (int i = 1; i <= LG->vertex; i++) {
        Node* current = LG->List[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    // 释放图结构本身
    free(LG);
}

#endif