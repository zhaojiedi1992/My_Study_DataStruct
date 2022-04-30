#include <stdio.h>
#include <string.h>

#define  MaxV  9999999

const int N=510;

int g[N][N];    //稠密图所以用邻接矩阵存储，表示i点和j点之间边的长度
int dist[N][N];    //i = > j 的距离
char*  path[N][N];    // i => j 经过路径。
int s[N];     //记录该点的最短距离是否已经确定

int n;



int findMinDist(){
    int minV = MaxV ;
    for (int i = 0; i <n ; ++i) {
        if (s[i]==0 && dist[i] <minV){
            return i ;
        }
    }
    return -1 ;
}


int Floyd()
{
    // 根据邻接矩阵填充dist ,path
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <n ; ++j) {
            dist[i][j] = g[i][j] ;
            if (dist[i][j] !=MaxV){
                //path[i][j] = char('0' +i ) + char('0' +j )
            }else{
                path[i][j]= "" ;
            }
        }

    }

    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j <n ; ++j) {
            for (int k = 0; k <n  ; ++k) {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j] ;
                    //path[i][j] = path[i][k] + path[k][j] ;
                }
            }
        }
    }

}




void InitDemo(){

    n = 5 ;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <n ; ++j) {
            g[i][j] = MaxV ;
        }
    }

    for (int i = 0; i < n; ++i) {
            g[i][i] = 0;
    }

    g[0][1] = 10 ;
    g[0][3] = 30 ;
    g[0][4] = 100 ;

    g[1][0] = 10 ;
    g[1][2]=50 ;

    g[2][1] =50 ;
    g[2][3]=20 ;
    g[2][4]= 10 ;

    g[3][0]=30 ;
    g[3][2]= 20 ;
    g[3][4]= 60 ;

    g[4][0] =100 ;
    g[4][2]= 10 ;
    g[4][3]=60 ;


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
    Floyd() ;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j <n ; ++j) {
            if (i==j){
                continue;
            }
            printf("%d=>%d %d\n",i,j,dist[i][j]) ;
        }

    }

    return 0;
}
