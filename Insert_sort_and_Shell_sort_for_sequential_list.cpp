#include <stdio.h>
#include <math.h>
#define MaxLength 1000
typedef int KeyType;

//数据结构体定义
typedef struct
{
    KeyType Key;
}RedType;

//排序表结构体定义
typedef struct
{
    RedType r[MaxLength];
    int length;
}Sqlist;


//直接插入排序函数
void InsertSort(Sqlist &L)
{
    int i, j;
    for (i = 2; i <= L.length; i++)
    {
        if (L.r[i].Key < L.r[i - 1].Key)
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i - 1];
            for (j = i - 2; L.r[j].Key > L.r[0].Key; j--)
                L.r[j + 1] = L.r[j];
            L.r[j + 1] = L.r[0];
        }
    }
    for (i = 1; i <= L.length; i++)
        printf ("%d ",L.r[i].Key);
    printf("\n");
}


//希尔单次排序函数
void ShellInsert(Sqlist &L, int dk)
{
    int i, times, j, k, l;
    for (i = 1; i <= dk; i++)
    {
        for (times = 0; i + dk * times <= L.length; times++);
        for (j = 1; j < times ; j++)
        {
            if (L.r[i + j * dk].Key < L.r[i + (j - 1) * dk].Key)
            {
                L.r[0] = L.r[i + j * dk];
                L.r[i + j * dk] = L.r[i + (j - 1) * dk];
                    for (k = j - 2; (i + dk * k) > 0 && L.r[i + dk * k].Key > L.r[0].Key; k--)
                        L.r[i + dk * (k + 1)] = L.r[i + dk * k];
                    L.r[i + dk * (k + 1)] = L.r[0];
            }
        }
    }
}


//希尔排序函数
void ShellSort(Sqlist &L)
{
    int i, dk;
    dk = L.length / 2;
    while (dk >= 1)
    {
        ShellInsert(L, dk);
        dk /= 2;
    }
    for (i = 1; i <= L.length; i++)
        printf ("%d ",L.r[i].Key);
    printf("\n");
}


//main函数实现线性表输入和两个排序函数调用
int main()
{
    int i;
    Sqlist L1, L2;
    printf ("Please input length of the List:\n");
    scanf("%d", &L1.length);
    printf("Please input each element in the list and separate them with space:\n");
    for (i = 1; i <= L1.length; i++)
        scanf ("%d", &L1.r[i].Key);
    L2 = L1;
    printf("The result of InsertSort is as folowing:\n");
    InsertSort(L1);
    printf("The backups of this List is:\n");
    for (i = 1; i <= L2.length; i++)
        printf ("%d ",L2.r[i].Key);
    printf("\n");
    printf("The result of ShellSort is as folowing:\n");
    ShellSort(L2);
    return 0;
}
