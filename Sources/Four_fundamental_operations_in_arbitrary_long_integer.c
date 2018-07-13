#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX_LEN  40
#define LINE_MAX 100
#define MAX_NUM  100 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//print 函数

void print (int result[])
{
	int j, k, length;
		for(j = 2*MAX_LEN - 1;j >= 0 ; j--)
			if(result[j] != 0)
				break;
		for (k = j;k >= 0;k--)  //逆序输出 
			printf("%d",result[k]);
		printf("\n");
}

//add函数

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

//minus函数

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

//判断j与(MAX_LEN-1)的大小关系*

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

//multiply 函数
 
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

//judge函数，判断两数的大小关系
 
int judge( int *p1, int *p2, int len1, int len2 )
{
    int i;
    if( len1 < len2 )
        return -1;
    if( len1 == len2 )
    {                        //判断p1 > p2
        for( i=len1-1; i>=0; i-- )
        {
            if( p1[i] > p2[i] )   //若大，则满足条件，可做减法
                break;
            else if( p1[i] < p2[i] ) //否则返回-1
                return -1;
        }
    }
    return 1;
}

//函数SubStract
//用长度为len1的大整数p1减去长度为len2的大整数p2
//结果存在p1中，返回值代表结果的长度
//不够减 返回-1 正好够 返回0  

int SubStract( int *p1, int *p2, int len1, int len2 )
{
    int i, j;
    if( len1 < len2 )
        return -1;
    if( len1 == len2 )
    {                        //判断p1 > p2
        for( i=len1-1; i>=0; i-- )
        {
            if( p1[i] > p2[i] )   //若大，则满足条件，可做减法
                break;
            else if( p1[i] < p2[i] ) //否则返回-1
                return -1;
        }
    }
    for( i=0; i<=len1-1; i++ )  //从低位开始做减法
    {
        p1[i] -= p2[i];
        if( p1[i] < 0 )          //若p1<0，则需要借位
        {
            p1[i] += 10;         //借1当10
            p1[i+1]--;           //高位减1
        }
    }
    for( i=len1-1; i>=0; i-- )       //查找结果的最高位
        if( p1[i] )                  //最高位第一个不为0
            return (i+1);       //得到位数并返回
    return 0;                  //两数相等的时候返回0
}

//divide函数

void divide (char inputstore_a[], char inputstore_b[]) 
{
	int j, k, l, nTemp;
	int lena , lenb ; //a,b的长度 
	int lenDif; //a,b的长度差 
	int dividend[MAX_LEN] = {0}; //被除数运算数组 
	int divisor[MAX_LEN] = {0}; //除数运算数组 
	int quotients[MAX_LEN] = {0}; //商存储数组 
	lenDif = lena - lenb ;
	lena = strlen(inputstore_a);
	lenb = strlen(inputstore_b);
	if(lenDif < 0)
		printf("0......%s",inputstore_b);
	else
	{
		//字符串向数组转换 
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
			for ( k=lena-1; k>=0; k-- )    //将除数扩大，使得除数和被除数位数相等
		   {
		        if ( k>=lenDif )
		            dividend[k] = divisor[k-lenDif];
		        else                     //低位置0
		            divisor[k] = 0;
		    }
		    lenb = lena;
		    for( j=0; j<=lenDif; j++ )      //重复调用，同时记录减成功的次数，即为商
		    {
		        while((nTemp = SubStract(dividend, divisor + j, lena, lenb - j)) >= 0)
		        {
		            lena = nTemp;      //结果长度
		            quotients[lenDif-j]++;     //每成功减一次，将商的相应位加1
		        }
			}
			}
			for( l=MAX_LEN-1; quotients[l]==0 && l>=0; l-- );//跳过高位0
	        if( l>=0 )
	            for( ; l>=0; l-- )
	                printf("%d", quotients[l]);
	        else
	            printf("0");
	        printf("......");
	        for( l=MAX_LEN-1; dividend[l]==0 && l>=0; l-- );//跳过高位0
	        if( l>=0 )
	            for( ; l>=0; l-- )
	                printf("%d", dividend[l]);
	        else
	            printf("0");
	        printf("\n");
	}
}

//main 函数
 
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
	
	//数据输入并逆序储存在字符串中

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

	//字符串向数组转化
	
	for (i = 0;i < number;i++)
	{
		for (j = 0; j < strlen(inputstore_a[i]) ; j++)
			input_a[i][j] = inputstore_a[i][j]-'0';
		for (j = 0; j< strlen(inputstore_b[i]);j++)
			input_b[i][j] = inputstore_b[i][j]-'0';	

	}

	// 运算符判断并执行函数
	
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
