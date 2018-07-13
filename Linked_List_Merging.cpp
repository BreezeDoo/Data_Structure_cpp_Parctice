#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

int GetElem_L(LinkList L, int i, int &e){
    LinkList p ;
    int j = 1 ;
    p = L ->next;
    while (p && j < i){
        p = p ->next; j++ ;
    }
    if (!p) return 0 ;
    else e = p ->data ;
    return 1 ;
}

void CreataList_L (LinkList &L , int n){
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r ;
    int i = 1, d ;
    L = NULL ;
    r = NULL ;
    while (i++ <= n){
        scanf ("%d", &d);
        s = (LNode *)malloc (sizeof (LNode));
        s ->data = d;
        if (L == NULL)
            L-> = s;
        else
            r ->next = s;
        r = s;
    }
    if (r != NULL)
        r ->next = NULL ;
}

void MergeList_L (LinkList &La, LinkList &Lb, LinkList &Lc){
	LNode *pa, *pb, *pc, *pbb ;
	pa = La ->next ;
	pb = Lb ->next ;
	Lc = pc = La ;
	while (pa && pb){
		if (pa->data < pb->data){
			pc->next = pa ;
			pc = pa ;
			pa = pa->next;
			}
		else if (pa->next == pb->next){
			pc->next = pa;
			pc = pa ;
			pa = pa->next ;
			pbb = pb ;
			pb = pb->next ;
			free(pbb) ;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb ;
	free (Lb);
}

int main()
{
	LNode *pc;
	LinkList La, Lb, Lc ;
	int length_a, length_b ;
	printf ("Please input the length of La and Lb and separate them with space :");
	scanf ("%d %d", &length_a, &length_b);
	CreataList_L(La, length_a);
	CreataList_L(Lb, length_b);
	MergeList_L(La, Lb, Lc);
	pc = Lc->next;
	while (pc){
		printf ("%d ",pc->data);
		pc = pc->next;
	}
    return 0;
}
