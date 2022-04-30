#include <stdio.h>
#include <string.h>

#define  MaxV  9999999

const int N=510;

int g[N][N];    //稠密图所以用邻接矩阵存储，表示i点和j点之间边的长度
int dist[N];    //每一个点到源点的距离
int path[N];    //记录路径。到到第N个点前一个点是什么点位。
int s[N];     //记录该点的最短距离是否已经确定

int n,m, startN;



int findMinDist(){
    int minV = MaxV ;
    for (int i = 0; i <n ; ++i) {
        if (s[i]==0 && dist[i] <minV){
            return i ;
        }
    }
    return -1 ;
}


int Dijkstra()
{
    // 根据邻接矩阵填充dist ,path
    for (int i = 0; i < n; ++i) {
        dist[i] = g[startN][i] ;
        if (dist[i] !=MaxV){
            path[i] = startN ;
        }else{
            path[i]= -1;
        }
    }
    // 初始化s , 开始的时候只是将初始节点标记为S.
    for (int  i = 0; i <n ; ++i) {
        s[i] = 0 ;
    }
    s[startN] = 1 ;

    int sCount = 1;
    while (sCount < n ){
        int minN = findMinDist ();
        s[minN] = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i]==0 && dist[i] > dist[minN]+g[minN][i]){
                dist[i] = dist[minN]+g[minN][i] ;
                path[i] = minN;
            }
        }
        sCount +=1;
    }

}




void InitDemo(){

    n = 7 ;
    startN = 0 ;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <n ; ++j) {
            g[i][j] = MaxV ;
        }
    }

    for (int i = 0; i < n; ++i) {
            g[i][i] = 0;
    }

    g[0][1] = 4;
    g[0][2] = 6;
    g[0][3]= 6;

    g[1][2]= 1;
    g[1][4]= 7 ;

    g[2][4]=6;
    g[2][5]=4;

    g[3][2] = 2;
    g[3][5]= 5;

    g[4][6]= 6;

    g[5][4] = 1;
    g[5][6] = 8 ;


}



int main()
{
    printf("start \n");
    InitDemo() ;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<n; ++j) {
            printf("%d\t", g[i][j]);
        }
        printf("\n");
    }
    Dijkstra() ;
    for (int i = 0; i<n; ++i) {
        printf("%d=>%d %d\n",startN,i,dist[i]) ;
    }

    return 0;
}
