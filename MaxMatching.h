#ifndef Max_Matching
#define Max_Matching

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BiGraph.h"
#include "Adj.h"

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
int maxmatching(BiGraph* BG){
    int* match_to = (int*)calloc(BG->NodeNum+1,sizeof(int));
    int result = 0;
    int v;
    for(int u = 1;u <= BG->NodeNum; u++){
        bool* visited = (bool*)calloc((BG->NodeNum+1),sizeof(bool));
        if (dfs(BG,u,visited,match_to)){
            result++;
        }
        free(visited);
    }
    free(match_to);

    return result;        
}

void placeMagicBalls(ListGraph* LG) {
    int n = LG->vertex; // 球的数量
    int* poleTop = (int*)calloc(n + 1, sizeof(int)); // 每根柱子的顶部球编号，初始为 0（表示无球）
    int* poleLength = (int*)calloc(n + 1, sizeof(int)); // 每根柱子的球数量
    int**poles = (int**)malloc(n * sizeof(int*)); // 存储每根柱子的球序列
    for (int i = 0; i < n; i++) {
        poles[i] = (int*)malloc(n * sizeof(int));
    }
    int poleCount = 0; // 当前使用的柱子数量

    // 遍历每个球，尝试放置
    for (int ball = 1; ball <= n; ball++) {
        bool placed = false;
        // 尝试放在已有柱子上
        for (int i = 0; i < poleCount; i++) {
            int top = poleTop[i];
            // 检查当前柱子顶部球 top 和当前球 ball 的和是否为完全平方数
            if (top != 0) {
                int sum = top + ball;
                int s = (int)sqrt(sum);
                if (s * s == sum) {
                    // 可以放置在该柱子上
                    poles[i][poleLength[i]++] = ball;
                    poleTop[i] = ball;
                    placed = true;
                    break;
                }
            } else {
                // 柱子为空，直接放置
                poles[i][poleLength[i]++] = ball;
                poleTop[i] = ball;
                placed = true;
                break;
            }
        }
        // 如果没放在已有柱子上，使用新柱子
        if (!placed) {
            poles[poleCount][poleLength[poleCount]++] = ball;
            poleTop[poleCount] = ball;
            poleCount++;
        }
    }

    // 输出每根柱子的球序列
    printf("需要 %d 根柱子\n", poleCount);
    for (int i = 0; i < poleCount; i++) {
        printf("柱子 %d: ", i + 1);
        for (int j = 0; j < poleLength[i]; j++) {
            printf("%d ", poles[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(poles[i]);
    }
    free(poles);
    free(poleTop);
    free(poleLength);
}

#endif
