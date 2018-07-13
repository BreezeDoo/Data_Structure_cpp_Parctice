#include<stdio.h>
#include<malloc.h>

typedef struct Node{
	float coef;
	int exp;
	struct Node *next;
}PolyNode, *LPolyNode ;

void Createpoly(LPolyNode &L, int n){
	PolyNode *r, *s;
	float coef;
	int exp, i = 0;
	L = (LPolyNode)malloc(sizeof(PolyNode));
	L->next = NULL;
	printf("Please input coefficient and exponent of the polynomial and separate the coef and exp with '^',\n");
	printf("Separate each term with space. Please make sure that the exponent of each term is in a greater sequence : \n");
	while(i++ < n){
		scanf("%f^%d",&coef,&exp);
		if (coef == 0){
			printf("coefficient can not be zero, please input again: \n");
			i--;
			continue;
		}
		s = (LPolyNode)malloc(sizeof(PolyNode));
		s->coef = coef;
		s->exp = exp;
		if (L->next == NULL)
			L->next = s;
		else
			r->next = s;
		r = s;
	}
	r->next = NULL;
}

void AddPoly(LPolyNode &La, LPolyNode &Lb, LPolyNode &Lc){
	PolyNode *pa, *pb, *pc, *tmp;
	Lc = pc = La;
	pa = La->next;
	pb = Lb->next;
	while (pa && pb){
		if (pa->exp < pb->exp){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->exp > pb->exp){
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else {
			if(pa->coef + pb->coef == 0){
				tmp = pa;
				pa = pa->next;
				free(tmp);
				tmp = pb;
				pb = pb->next;
				free(tmp);
			}
			else{
				pc->next = pa;
				pc = pa;
				pa->coef = pa->coef + pb->coef;
				pa = pa->next;
				tmp = pb;
				pb = pb->next;
				free(tmp);
			}
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}

int main(){
	LPolyNode La, Lb, Lc;
	PolyNode *pc;
	int La_length, Lb_length;
	printf("Please input the length of polynomial Pa, and press enter to finish.\n");
	scanf("%d",&La_length);
	printf("Please input the length of polynomial Pb, and press enter to finish.\n");
	scanf("%d",&Lb_length);
	Createpoly(La, La_length);
	Createpoly(Lb, Lb_length);

	AddPoly(La, Lb, Lc);

	printf("Polynomial Pa + Pb = ");
	pc = Lc->next;
	while(pc){
		printf("%fx^%d",pc->coef, pc->exp);
		pc = pc->next;
		if(pc)
			printf(" + ");
	}
	return 0;
}
