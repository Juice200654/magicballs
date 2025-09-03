#include <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>
#include "Adj.h"
#include "BiGraph.h"
#include "MaxMatching.h"

void balls_input(int n) {
    ListGraph* LG;
    BiGraph* BG;
    int max, min;
    
    LG = creatLG(n, 1);
    BG = creatBG(LG);
    max = maxmatching(BG);
    min = n - max;
    placeMagicBalls(LG);
    
    // 释放内存
    freeBiGraph(BG);
    freeGraph(LG);
}

void columns_input(int m) {
    int n = 1;
    while (1) {
        ListGraph* LG;
        LG = creatLG(n, 1);
        for (int i = 1;i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if (is_sqrt(i+j)){
                    AddEdge(i,j,LG);
                }
            }
    }
        BiGraph* BG;
        int max, min;
        
        
        BG = creatBG(LG);
        max = maxmatching(BG);
        min = n - max;
        
        if (min < m) {
            n++;
        } else {
            // 找到满足条件的n，可以在这里处理结果
            printf("%d\n", n);
            placeMagicBalls(LG);
            freeBiGraph(BG);
            freeGraph(LG);
            break;
        }
        
        // 释放当前循环的内存
        freeBiGraph(BG);
        freeGraph(LG);
    }
}
