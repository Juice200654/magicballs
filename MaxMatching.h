#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BiGraph.h"


//深度优先算法求二分图的增广路径
bool dfs(BiGraph* BG,int u,bool* visited,int* match_to){
    //遍历当前左侧节点的所有右侧节点
    for (int i = 0; i<BG->adjSize[u];i++){
        int v = BG->adj[u][i];
        if (!visited[v]){
            visited[v] = 1;
            if(!match_to[v] || dfs(BG,match_to[v],visited,match_to)){
                match_to[v] = u;
                return true;
            }
        }
    }
    return false;

}

//匈牙利算法求二分图最大匹配
int maxmatching(BiGraph* BG,int* match_to){
    int result = 0;
    int v;
    for (int i = 0; i <= BG->NodeNum; i++){
        match_to[i] = 0;  
    }
    for(int u = 0;u <= BG->NodeNum; u++){
        bool* visited = (bool*)calloc(BG->NodeNum,sizeof(bool*));
        if (dfs(BG,u,visited,match_to)){
            result++;
        }
        free(visited);
    }
    return result;        
}
