#include<stdio.h>
#include<stdlib.h>
struct Treenode;
typedef struct Treenode *Position;
typedef struct Treenode *SearchTree;
SearchTree Insert(int X,SearchTree T);
SearchTree Delete(int X,SearchTree T);
Position Find(int X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
void Display(SearchTree T);
struct Treenode
{
int Element;
SearchTree Left;
SearchTree Right;
};
Position T,P;
void main()
{
int X,op=1;
T=NULL;

do
{

printf("\n\n\t\t\t BST :MAIN MENU");
printf("\n\n\n\t1.INSERTION\n\t2.DELETE\n\t3.SEARCH\n\t4.SEARCH MINIMUM VALUE\n\t5.FIND MAXIMUM VALUE\n\t6.DISPLAY\n\t7.EXIT\n");
printf("\n\n\tENTER YOUR CHOICE :");
scanf("%d",&op);
switch(op)
{
case 1:printf("\n\n\tEnter the element:\n");
scanf("%d",&X);
T=Insert(X,T);
printf("\n\n\tNew element is inserted\n ");
break;
case 2:printf("\n\n\tEnter the element to delete:");
scanf("%d",&X);
P=Delete(X,T);
printf("\n\n\tElement at position %d is deleted:\n",P);
break;
case 3:printf("\n\n\tEnter the element to find:");
scanf("%d",&X);
P=Find(X,T);
if(P==NULL)
printf("\n\n\tThe element is not found\n");
else
printf("\n\n\tThe element is found at position %d\n",P);
break;
case 4:P=FindMin(T);
printf("\n\n\tThe minimum element in the tree is %d and it is found at position %d\n",P->Element,P);
break;
case 5:P=FindMax(T);
printf("\n\n\tThe maximum element in the tree is %d and it is found at position %d\n",P->Element,P);
break;
case 6:Display(T);
break;
case 7:exit(0);
break;
} 
}while(op!=7);
}
SearchTree Insert(int X,SearchTree T)
{
if(T==NULL)
{
T=(SearchTree)malloc(sizeof(struct Treenode));
T->Element=X;
T->Left=T->Right=NULL;
}
else if(X<T->Element)
T->Left=Insert(X,T->Left);
else if(X>T->Element)
T->Right=Insert(X,T->Right);
return T;
}
Position Find(int X,SearchTree T)
{
if(T==NULL)
return NULL;
if(X<T->Element)
return Find(X,T->Left);
else if(X>T->Element)
return Find(X,T->Right);
else
return T;
}
Position FindMin(SearchTree T)
{
if(T==NULL)
return NULL;
else if(T->Left==NULL)
return T;
else
return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
if(T==NULL)
return NULL;
else if(T->Right==NULL)
return T;
else
return FindMax(T->Right);
}
SearchTree Delete(int X, SearchTree T)
{
Position TmpCell;
if(T==NULL)
printf("Element not found\n");
else if(X<T->Element)
T->Left=Delete(X,T->Left);
else if(X>T->Element)
T->Right=Delete(X,T->Right);
else if(T->Left && T->Right)
{
TmpCell=FindMin(T->Right);
T->Element=TmpCell->Element;
T->Right=Delete(T->Element,T->Right);
}
else
{
TmpCell=T;
if(T->Left==NULL)
T=T->Right;
else if(T->Right==NULL)
T=T->Left;
free(TmpCell);
}
return T;
}
void Display(SearchTree T)
{
//printf("\nADD\tVALUE\n");
if(T!=NULL)
{
Display(T->Left);
printf("%d\t%d\n",T,T->Element);
Display(T->Right);
}
}