#include <stdio.h>
#include <stdlib.h>
int* f(int *BST)
{
//	int *p = BST;
	int *p = (int*)malloc(sizeof(int));
	//BST = (int*)malloc(sizeof(int));
	*p = 10;	
BST=p;	
	printf("%s,p  =%p\n",__FUNCTION__,p);
	printf("%s,BST=%p\n",__FUNCTION__,BST);
//	BST = p;
	printf("%s,p  =%d\n",__FUNCTION__,*p);
	printf("%s,BST=%d\n",__FUNCTION__,*BST);
	return BST;
}


void main()
{
	int *B=NULL;
	B=f(B);
	printf("%p\n",B);
	printf("%d\n",*B);
}


