#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX_LEN  40
#define LINE_MAX 100
#define MAX_NUM  100 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//print ����

void print (int result[])
{
	int j, k, length;
		for(j = 2*MAX_LEN - 1;j >= 0 ; j--)
			if(result[j] != 0)
				break;
		for (k = j;k >= 0;k--)  //������� 
			printf("%d",result[k]);
		printf("\n");
}

//add����

void addition (int arra[], int arrb[]) 
{
	int j, result[ 2*MAX_LEN ] = {0} ;
	for(j=0;j< MAX_LEN ;j++)
	{
		result[j] += (arra[j] + arrb[j]) % 10 ;
		result[j+1] += (arra[j] + arrb[j]) /10 ;
	}
	print(result);
}

//minus����

void minus (int arra[], int arrb[]) 
{
	int j, result[2*MAX_LEN] = {0};
	for(j=0;j< MAX_LEN ;j++)
	{
		if((arra[j] - arrb[j]) < 0)
		{
			arra[j + 1]--;
			arra[j] += 10;
			result[j] = arra[j] - arrb[j];
		}
		else 
			result[j] = arra[j] - arrb[j];
		//printf("%d",result[j]);
	}
	print(result);
}

//�ж�j��(MAX_LEN-1)�Ĵ�С��ϵ*

int min2 (int j)
{
	if (j <= (MAX_LEN-1) )
		return j ;
	else
		return (MAX_LEN-1);
}

int min1(int j)
{
	if (j >= MAX_LEN )
		return (j+1- MAX_LEN);
	else
		return 0;
}

//multiply ����
 
void multiply (int arra[],int arrb[])
{
	int j, p, result[2*MAX_LEN] = {0};
	for (j = 0;j < MAX_LEN; j++)
	{
		for (p = 0;p < MAX_LEN; p++)
		{
			result[j + p] += (arra[j] * arrb[p]) % 10 ;
			result[j + p + 1] += (arra[j] * arrb[p]) / 10 ;
		}
	}
	for(j = 1;j < 2*MAX_LEN - 1 ;j++)
	{
		if (result[j] > 9)
		{
			result[j] %= 10 ;
			result[j + 1] ++ ;
		}
	}
	print(result);
} 

//judge�������ж������Ĵ�С��ϵ
 
int judge( int *p1, int *p2, int len1, int len2 )
{
    int i;
    if( len1 < len2 )
        return -1;
    if( len1 == len2 )
    {                        //�ж�p1 > p2
        for( i=len1-1; i>=0; i-- )
        {
            if( p1[i] > p2[i] )   //������������������������
                break;
            else if( p1[i] < p2[i] ) //���򷵻�-1
                return -1;
        }
    }
    return 1;
}

//����SubStract
//�ó���Ϊlen1�Ĵ�����p1��ȥ����Ϊlen2�Ĵ�����p2
//�������p1�У�����ֵ�������ĳ���
//������ ����-1 ���ù� ����0  

int SubStract( int *p1, int *p2, int len1, int len2 )
{
    int i, j;
    if( len1 < len2 )
        return -1;
    if( len1 == len2 )
    {                        //�ж�p1 > p2
        for( i=len1-1; i>=0; i-- )
        {
            if( p1[i] > p2[i] )   //������������������������
                break;
            else if( p1[i] < p2[i] ) //���򷵻�-1
                return -1;
        }
    }
    for( i=0; i<=len1-1; i++ )  //�ӵ�λ��ʼ������
    {
        p1[i] -= p2[i];
        if( p1[i] < 0 )          //��p1<0������Ҫ��λ
        {
            p1[i] += 10;         //��1��10
            p1[i+1]--;           //��λ��1
        }
    }
    for( i=len1-1; i>=0; i-- )       //���ҽ�������λ
        if( p1[i] )                  //���λ��һ����Ϊ0
            return (i+1);       //�õ�λ��������
    return 0;                  //������ȵ�ʱ�򷵻�0
}

//divide����

void divide (char inputstore_a[], char inputstore_b[]) 
{
	int j, k, l, nTemp;
	int lena , lenb ; //a,b�ĳ��� 
	int lenDif; //a,b�ĳ��Ȳ� 
	int dividend[MAX_LEN] = {0}; //�������������� 
	int divisor[MAX_LEN] = {0}; //������������ 
	int quotients[MAX_LEN] = {0}; //�̴洢���� 
	lenDif = lena - lenb ;
	lena = strlen(inputstore_a);
	lenb = strlen(inputstore_b);
	if(lenDif < 0)
		printf("0......%s",inputstore_b);
	else
	{
		//�ַ���������ת�� 
		for (j = 0;j < MAX_LEN+1 ;j++)
		{
			if(inputstore_a[j] !='\0')
			{
				dividend[j] = inputstore_a[j]-'0';
			}
			else
				break;
		}
		for (j = 0;j < MAX_LEN+1 ;j++)
		{
			if(inputstore_b[j] !='\0')
			{
				divisor[j] = inputstore_b[j]-'0';
			}
			else
				break;
		}

	
		if(judge(dividend, divisor, lena, lenb) == -1)
			printf("0......%s",inputstore_b);
		else if(judge(dividend, divisor, lena, lenb) == 0)
			printf("1......0");
		else
		{
			for ( k=lena-1; k>=0; k-- )    //����������ʹ�ó����ͱ�����λ�����
		   {
		        if ( k>=lenDif )
		            dividend[k] = divisor[k-lenDif];
		        else                     //��λ��0
		            divisor[k] = 0;
		    }
		    lenb = lena;
		    for( j=0; j<=lenDif; j++ )      //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��
		    {
		        while((nTemp = SubStract(dividend, divisor + j, lena, lenb - j)) >= 0)
		        {
		            lena = nTemp;      //�������
		            quotients[lenDif-j]++;     //ÿ�ɹ���һ�Σ����̵���Ӧλ��1
		        }
			}
			}
			for( l=MAX_LEN-1; quotients[l]==0 && l>=0; l-- );//������λ0
	        if( l>=0 )
	            for( ; l>=0; l-- )
	                printf("%d", quotients[l]);
	        else
	            printf("0");
	        printf("......");
	        for( l=MAX_LEN-1; dividend[l]==0 && l>=0; l-- );//������λ0
	        if( l>=0 )
	            for( ; l>=0; l-- )
	                printf("%d", dividend[l]);
	        else
	            printf("0");
	        printf("\n");
	}
}

//main ����
 
int main() 

{
/*	int number = 0;
	char* arra = {"1"};
	char* arrb = {"1"};
	int a[MAX_LEN] = {0}, b[MAX_LEN] = {0};
	arra[0] = 1;arrb[0] = 1;
/*	arra[19] = 9;
	arra[1] = 2;
	arra[0] = 1;
	arrb[19] = 9;
	arrb[1] = 7;
	arrb[0] = 5;

	divide(arra,arrb);*/


	int number, i, j, k, flag ;
	int input_a[ MAX_NUM ][ MAX_LEN ]={0}, input_b[ MAX_NUM ][ MAX_LEN ]={0} ;
	char operate[ MAX_NUM ] ;
	char inputstore[LINE_MAX], output[MAX_NUM][LINE_MAX];
	char inputstore_a[ MAX_NUM ][ MAX_LEN+1 ] , inputstore_b[ MAX_NUM ][ MAX_LEN+1 ], inputstore_b2[ MAX_NUM ][ MAX_LEN+1 ];
	scanf("%d",&number);
	fgets(inputstore, LINE_MAX, stdin);	
	
	//�������벢���򴢴����ַ�����

	for(i=0;i<number;i++)
	{
		gets(inputstore);
	//	fgets(inputstore, LINE_MAX, stdin);
		for (j = 0; j < LINE_MAX ; j++)
			output[i][j] = inputstore[j]; 		
		for (j=0; j<LINE_MAX && isdigit(inputstore[j]); j++);
		flag = j-1 ;
		for(j = 0;j <= flag; j++)
			inputstore_a[i][j] = inputstore[flag-j] ;
		inputstore_a[i][j] = '\0';
		for(j = flag+1;;j++)
			if(inputstore[j] == '+' ||inputstore[j] == '+' ||inputstore[j] == '*' ||inputstore[j] == '/')
				break;
		operate[i] = inputstore[j];
		for(j++;isspace(inputstore[j]); j++);
		flag = j;
		for(j = strlen(inputstore) - 1, k = 0;j >= flag ; j--, k++)
			inputstore_b[i][k] = inputstore[j] ;
		inputstore_b[i][k] = '\0';

		}

	//�ַ���������ת��
	
	for (i = 0;i < number;i++)
	{
		for (j = 0; j < strlen(inputstore_a[i]) ; j++)
			input_a[i][j] = inputstore_a[i][j]-'0';
		for (j = 0; j< strlen(inputstore_b[i]);j++)
			input_b[i][j] = inputstore_b[i][j]-'0';	

	}

	// ������жϲ�ִ�к���
	
	for(i=0;i<number;i++)
	{
		if (operate[i]=='+')
		{
			printf("%s = ",output[i]);
			addition(input_a[i], input_b[i]);
		}
		if (operate[i]=='-') 
		{
			printf("%s = ",output[i]);
			minus(input_a[i], input_b[i]);
		}
		if (operate[i]=='*') 
		{
			printf("%s = ",output[i]);
			multiply(input_a[i], input_b[i]);
		}
		if (operate[i]=='/')
		{
			printf("%s = ",output[i]);
			divide(inputstore_a[i], inputstore_b[i]);
		}
	}
	
	scanf("%d",&number);
	
	return 0;
}
