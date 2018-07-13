#include <stdio.h>
#define MAX_LEN 100
typedef int KeyType; 


typedef struct
{
    KeyType Key;
}RedType;


typedef struct
{
    RedType r[MAX_LEN];
    int length;
}Sqlist;


void switchele(Sqlist &L, int i, int j)
{
    RedType tmp;
    tmp = L.r[i];
    L.r[i] = L.r[j];
    L.r[j] = tmp;
}


void Bubble_Sort(Sqlist &L)
{
    int i, flag;
    flag = 1;
    while (flag == 1)
    {
        flag = 0;
        for(i = 0; i < L.length - 1; i++)
        {
            if (L.r[i].Key > L.r[i + 1].Key)
            {
                switchele(L, i, i + 1);
                flag = 1;
            }
        }
    }
    printf("Result of Bubble_Sort is as folowing: \n");
    for (i = 0; i < L.length; i++)
        printf("%d ",L.r[i].Key);
    printf("\n");
}


int Quick_Switch(Sqlist &L, int high, int low)
{
    RedType tmp;
    tmp = L.r[low];
    while (high != low)
    {
        while (L.r[high].Key >= tmp.Key && high > low)
            high--;
        L.r[low] = L.r[high];
        while (L.r[low].Key <= tmp.Key && high > low)
            low++;
        L.r[high] = L.r[low];
    }
    L.r[high] = tmp;
    return high;
}


void Quick_Sort(Sqlist &L, int high, int low)
{
    if (high == low)
        return;
    int pivot;
    pivot = Quick_Switch(L, high, low);
    
    if (pivot != low)
    	Quick_Sort(L, pivot - 1, low);
    if (pivot != high)
    Quick_Sort(L, high, pivot + 1);
}


int main()
{
    int i;
    Sqlist L1, L2;
    printf("Please input the length of the sequent list: ");
    scanf("%d",&L1.length);
    for(i = 0; i < L1.length; i++)
        scanf("%d",&L1.r[i].Key);
    L2 = L1;
    Bubble_Sort(L1);
    Quick_Sort(L2, L2.length - 1, 0);
    printf("Result of Quick_Switch_Sort is as folowing: \n");
    for (i = 0; i < L2.length; i++)
    	printf("%d ",L2.r[i].Key);
    printf("\n");
    return 0;
}
