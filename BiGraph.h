#ifndef BIGRAPH
#define BIGRAPH

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Adj.h"

bool is_sqrt(int a){
    int m = sqrt(a);
    return  m*m == a;
}

//二分图结构
typedef struct {
    int NodeNum;
    int** adj;
    int* adjSize;
}BiGraph;

//由邻接表创建二分图
BiGraph* creatBG(ListGraph* LG){
    BiGraph* BG = (BiGraph*)malloc(sizeof(BiGraph));
    int num = LG->vertex;
    BG-> NodeNum = num;
    BG->adj = (int**)malloc((num+1)*sizeof(int*));
    BG->adjSize = (int*)calloc(num+1,sizeof(int));
    BG->adj[0] = NULL;
    for (int u = 1; u <= num; u++){
        BG->adj[u] = (int*)malloc(num*sizeof(int));     
    }
    for (int u = 1; u <= num; u++){
        Node* current;
        current = LG->List[u]->next;
        while (current){
            int v = current->vertex;
            BG->adj[u][BG->adjSize[u]++] = v;
            current = current->next;
        }
    } 
    return BG;  
}

//打印二分图
void printBG(BiGraph* Bg){
    printf("二分图结构\n");
    for (int i = 1; i <= Bg->NodeNum; i++){
        printf("顶点 %d:",i);
        printf("[");
        for(int j = 0; j<Bg->adjSize[i]; j++){
            if (j < Bg->adjSize[i]-1){
                printf("%d,",Bg->adj[i][j]);  
            }else{
                printf("%d",Bg->adj[i][j]); 
            }
       
        }
        printf("]\n");
    }
}

//释放二分图
void freeBiGraph(BiGraph* BG){
    for (int u = 0; u <= BG->NodeNum; u++) {
        free(BG->adj[u]);
    }
    free(BG->adj);
    free(BG->adjSize);
    free(BG);
}

#endif