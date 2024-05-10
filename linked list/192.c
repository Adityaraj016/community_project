#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
int count(struct Node *p){
    int count=0;
    while(p != NULL){
        count++;
        p=p->next;
    }
    return count;
}
int Delete(struct Node *p,int index)
{
 struct Node *q=NULL;
 int x=0,i;

 if(index < 1 || index > count(p))
 return -1;
 if(index==1)
 {
 q=first;
 x=first->data;
 first=first->next;
 free(q);
 return x;
 }
 else
 {
 for(i=0;i<index-1;i++)
 {
 q=p;
 p=p->next;
 }
 q->next=p->next;
 x=p->data;
 free(p);
 return x;

 }
}

void sorted(struct Node *p,int x){
    struct Node *q=NULL;
    //int x=count(first);
    int y=1;
    for(int i=0;i<x-1;i++){
        q=p;
        p=p->next;
        if(q->data <= p->data){
            y++;
        }

    }
    printf("%d %d\n",x,y);
    if(x == y){
        printf("list is sorted\n");
    }
    else{
        printf("list is not sorted\n");
    }
}


int main()
{

 int A[]={10,20,25,30,40,50};
 create(A,6);
 int x=count(first);

 //printf("%d\n",Delete(first,3));
 sorted(first,x);
 Display(first);

 return 0;
}