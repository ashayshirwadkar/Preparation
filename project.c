#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

typedef struct node {
  int flag;
  char str[10];
  struct node *next;
}node;


node list[MAX];
int tot_index=0;
void insert(char *,char *);
int search(char *str);
void read();

void main()
{
  int n,i,e,j;
  char str1[10],str2[10];
  printf("Enter number of packages");
  scanf("%d",&n);
  printf("Enter number of dependecies ");
  scanf("%d",&e);
  printf("Enter dependencies");
  for(i=0;i<e;i++){
    scanf("%s%s",str1,str2);
    insert(str1,str2);
  }
  read();
}

int search(char *str)
{
  int i=0;
  if(tot_index==0)
    return -1;
  while(strcmp(list[i].str,str)!=0 && i<=tot_index) 
      i++;
  if(i<=tot_index)
      return i;
  return -1;
}

void read()
{
  int i;
  node *p;
  for(i=0;i<tot_index;i++) {
    p=&list[i];
    printf("\n%s->",p->str);
    p=p->next;
    while(p!=NULL){
      printf(" %s ",p->str);
      p=p->next;
    }
    printf("\n");
  }
}


void insert(char *str1,char *str2)
{
  int index=0;
  node *p,*q;
  p=(node*)malloc(sizeof(node));
  p->flag=0;
  strcpy(p->str,str2);
  p->next=NULL;
  index=search(str1);
  printf("%d",index);
  if(index==-1) {
    list[tot_index].flag=0;
    list[tot_index].next=p;
    strcpy(list[tot_index].str,str1);
    printf("%d",tot_index);
    tot_index++;
  }
  else{
   q=&list[index];
    while(q->next!=NULL)
      q=q->next;
    q->next=p;
    }
}
