#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10

typedef struct node {
        int flag;
        int link_no;
        char str[10];
        struct node *link[5];
}node;


node list[MAX];
int tot_index=0;
int insert(char *);
int search(char *str);
void read();
void install_package(int);
void join (int,int);
void show_package();
void main()
{
        FILE *fp;
        int n,i,e,no1,no2;
        char str1[10],str2[10],*p;
        fp=fopen("ip.txt","r");
        while(!feof(fp)) {
                fscanf(fp,"%s%s",str1,str2);
                no1=insert(str1);
                p=strtok(str2,",");
                no2=insert(p);
                join(no1,no2);
                while(p!=NULL) {                     
                        p=strtok(NULL,",");
                        if(p!=NULL){
                                no2=insert(p);
                                join(no1,no2);
                        }
                }
        }
        fclose(fp);
        read();
        while(strcmp(str1,"ok")!=0) {
                printf("\nEnter package ");
                scanf("%s",str1);
                n=search(str1);
                if(list[n].flag==1)  
                        printf("Package Already Installed!!\n");
                else if(n!=-1)
                        install_package(n);
                else
                        printf("\nPackage doesnt exist..Do you want to add?");
                show_package();
        }
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

void show_package()
{
        node *p;
        int i;
        for(i=0;i<tot_index;i++) {
                p=&list[i];
                printf("%s %d",p->str,p->flag);
        }
}

void read()
{
        int i,j=0;
        node *q;
        for(i=0;i<tot_index;i++) {
                j=0; 
                printf("\n%s->",list[i].str);
                while(j<list[i].link_no){
                        printf(" %s ",list[i].link[j]->str);
                        j++;
                }
                printf("\n");
        }
}


void install_package(int pack_no)
{
        node *p;
        int i=0;
        p=&list[pack_no];
        p->flag=1;
        while(p->link[i]!=NULL) {
                pack_no=search(p->link[i]->str);
                if(list[pack_no].flag==0)
                        install_package(pack_no);
                i++;
        }
}


void join(int no1,int no2)
{
        list[no1].link[list[no1].link_no]=&list[no2];
        list[no1].link_no=  list[no1].link_no + 1;
        list[no1].link[list[no1].link_no]=NULL;
}

int insert(char *str1)
{
        int index=0;
        index=search(str1);
        if(index==-1) {
                list[tot_index].flag=0;
                list[tot_index].link_no=0;
                list[tot_index].link[list[tot_index].link_no]=NULL;
                strcpy(list[tot_index].str,str1);
                tot_index++;
                return tot_index-1;
        }
        else
                return index;
}
