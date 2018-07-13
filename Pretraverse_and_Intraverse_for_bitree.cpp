#include<stdio.h>
#include<stdlib.h> 
#include<iostream>

using namespace std;

typedef char ElemType;

typedef struct BinaryTreeNode
{
    ElemType m_nValue;
    struct BinaryTreeNode* m_pLeft;
    struct BinaryTreeNode* m_pRight;
}BinaryTreeNode, *PBTN;


int PreTraverse(PBTN &proot)
{
  char ch;
  cin>>ch;
  if (ch == '#')
  {
    proot = NULL;
    return 1;
  }
	else
  {
    if (!(proot = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode))))
      exit (1);
    proot->m_nValue = ch;
    cout<<ch<<' ';
    PreTraverse (proot->m_pLeft);
    PreTraverse (proot->m_pRight);
    return 1;
  }
}


void InTraverse(PBTN proot)
{
	if (proot == NULL)
    	return;
    InTraverse(proot->m_pLeft);
    cout<<proot->m_nValue<<' ';
    InTraverse(proot->m_pRight);
}


int main()
{
  PBTN proot;
  cout<<"Please input some interger in a BinaryTree by a PreTraverse order ,use '#'to present a empty BinaryTreeNode:"<<endl;
  PreTraverse(proot);
  cout<<endl;
  InTraverse(proot);
  return 0;
}
