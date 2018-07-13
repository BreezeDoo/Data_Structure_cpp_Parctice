#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct{
        int * elem ;
        int length ;
        int listsize ;
}Sqlist;

int InitList_Sq(Sqlist &L){
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.elem) return 0;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 1;
}

void MergeList_Sq(Sqlist La , Sqlist Lb , Sqlist &Lc) {
    int *pa, *pb, *pc, *pa_last, *pb_last ;
    Lc.listsize = Lc.length = La.length + Lb.length ;
    pa = La.elem ; pb = Lb.elem ;
    pc = Lc.elem = (int*)malloc(Lc.listsize * sizeof(int));
    if (pc == NULL) exit(1);
    pa_last = La.elem + La.length - 1 ;
    pb_last = Lb.elem + Lb.length - 1 ;
    while (pa <= pa_last && pb <= pb_last){
        if (*pa < *pb)
            *pc++ = *pa++ ;
        else if (*pa == *pb){
            *pc++ = *pa++;
            pb++; Lc.length-- ;
        }
        else *pc++ = *pb++ ;
    }
    while (pa <= pa_last) *pc++ = *pa++ ;
    while (pb <= pb_last) *pc++ = *pb++ ;
}

int  main(){
     Sqlist La, Lb, Lc ;
     int *pa, *pb, *pc, *pa_last, *pb_last ;
     InitList_Sq(La);
     InitList_Sq(Lb);
     printf("Please input the length of List 1 and List 2 ,and separate them with space :");
     scanf("%d %d",&La.length, &Lb.length);
     pa = La.elem ; pb = Lb.elem ;
     pa_last = La.elem + La.length - 1 ;
     pb_last = Lb.elem + Lb.length - 1 ;
     printf ("plesae input element in List 1 by a greater sequence :");
     while(pa <= pa_last) scanf ("%d",pa++);
     printf ("plesae input element in List 2 by a greater sequence :");
     while(pb <= pb_last) scanf ("%d",pb++);
     MergeList_Sq(La, Lb, Lc);
     printf("The merged list is :");
     for (pc = Lc.elem ; pc <= Lc.elem + Lc.length -1 ;)
        printf ("%d ", *pc++);
     return 0;
}
