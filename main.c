#include <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>
#include "Adj.h"
#include "BiGraph.h"
#include "MaxMatching.h"
#include "io.h"

int main(void){
    int Num;
    scanf("%d", &Num);
    //balls_input(Num);
    columns_input(Num);
/*
    int mh;
    ListGraph* Gp;
    scanf("%d", &Num);
    //构建有向图，顶点为1到Num的整数
    Gp = creatLG(Num,1);
    for (int i = 1;i <= Num; i++){
        for(int j = i+1; j <= Num; j++){
            if (is_sqrt(i+j)){
                AddEdge(i,j,Gp);
            }
        }
    }
    //printLG(Gp);
    BiGraph* Bg = creatBG(Gp);//创建二分图
    //printBG(Bg);//打印二分图
    //求LG的最小路径覆盖
    mh = maxmatching(Bg);
    printf("%d\n",Num-mh);
    placeMagicBalls(Gp);

    freeGraph(Gp);
    freeBiGraph(Bg);
*/
    return 0;
}