#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100 //最大节点数
#define Infinite 1000 //无穷距离


//树结构定义
typedef struct
{
    int vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
}Mgraph;


//临近节点数组定义
struct
{
    int adjvex;
    int lowcost;
}closedge[MAX_VERTEX_NUM];


//定位节点编号函数
int LocateVex(Mgraph G, int i)
{
    int number ;
    for (number = 0; G.vexs[number] != i && number < G.vexnum; number++){
        if (number >= G.vexnum)
        {
            printf("Invalid Input\n");
            exit (0);
        }//防止错误输入
    }
    return number;
}


//创建树
void CreateUDN(Mgraph &G)
{
    int vex1, vex2, i, j, w;
    printf("Please input the number of vexs and arcs in this graph,and separate them with space:\n");
    scanf("%d %d",&G.vexnum, &G.arcnum);
    printf("Please give each vex a name (in interger):\n");
    for(i = 0; i < G.vexnum; i++)
        scanf("%d",&G.vexs[i]);//输入节点的名称，用整数代表
    printf("Please input weight of each arc in this graph:\n");
    for(i = 0; i < G.arcnum; i++)
    {
        scanf ("%d %d %d", &vex1, &vex2, &w);
        vex1 = LocateVex(G, vex1);
        vex2 = LocateVex(G, vex2);
        G.arcs[vex2][vex1] = w;
        G.arcs[vex1][vex2] = w;
    }//输入邻接矩阵中节点之间的权重，并使矩阵成为对称方阵
    printf("The adjacent matrix is:\n");
    for (i = 0;i < G.vexnum; i++)
    {
        for (j = 0;j < G.vexnum; j++)
            printf("%d ",G.arcs[i][j]);
        printf("\n");
    }//输出创建成功的邻接矩阵
    printf("Succeeded set up adjacent matrix.\n");
}//完成创建树


//求最小距离函数
void Mincost(Mgraph G, int k)
{
    int i;
    for (i = 0; i <= G.vexnum - 1 ; i++)
        {
        if (closedge[i].lowcost == 0)
        {
            if (G.arcs[i][k] < closedge[k].lowcost)
            {
                closedge[k].lowcost = G.arcs[i][k];
                closedge[k].adjvex = i;
            }
        }
    }
}


//求最小生成树
void MiNiSpanTree_PRIM(Mgraph G)
{
    int i, k, start, lowcost, vex;
    printf("Please input the point where we start: \n");
    scanf("%d", &start);
    closedge[LocateVex(G, start)].lowcost = 0;
    printf("The MiNiSpanTree is: \n");
    for(i = 0; i < G.vexnum - 1; i++)
    {
        lowcost = Infinite;
        for (k = 0; k <= G.vexnum -1; k++)
        {
            if (closedge[k].lowcost != 0)
            {
                Mincost(G, k);
                if (lowcost > closedge[k].lowcost)
                {
                    lowcost = closedge[k].lowcost;
                    vex = k;
                }
            }
        }//将不在U中的节点的closedge数组进行更新
        if (lowcost == Infinite)
        {
            printf ("This graph is not a connected graph.\n");
        }//判断图是否为连通图
        else
        {
            printf("%d %d\n",G.vexs[vex], G.vexs[closedge[vex].adjvex]);//输出最小权重的两条边
            closedge[vex].lowcost = 0;//将第vex个节点加入集合U中
        }
    }//遍历G.vexnum -1次，求最小生成树
    printf("Finished creating a minispantree.\n");
}


//主函数
int main()
{
    int i, j;
    Mgraph G;
    for (i = 0;i < MAX_VERTEX_NUM; i++)
    {
        for (j = 0;j < MAX_VERTEX_NUM; j++)
        {
            if (i == j)
                G.arcs[i][j] = 0;
            else
                G.arcs[i][j] = Infinite;
        }
    }//初始化邻接矩阵
    CreateUDN(G);
    for(i = 0; i < MAX_VERTEX_NUM; i++)
        closedge[i].lowcost = Infinite;//初始化closedge表
    MiNiSpanTree_PRIM(G);
    return 0;
}
