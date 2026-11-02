#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
#include<string.h>
struct node{
    struct node *pre;
    char data[20];
    struct node *next;
};
struct node *start=NULL;
void insertAtFirst();
void insertAtLast();
void insertAtMid();
void delAtFirst();
void delAtLast();
void delAtMid();
struct node *search(char[]);
void modify();
void display();
int main()
{
    int ch;
    while(1)
    {
    system("cls");
    printf("\n1-insert From Start");
    printf("\n2-insert From End");
    printf("\n3-insert From Middle");
    printf("\n4-delete From Start");
    printf("\n5-delete From End");
    printf("\n6-delete From Middle");
    printf("\n7-Display");
    printf("\n8-Exit");
    printf("\n9-Search record");
    printf("\n10-Modify record");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            insertAtFirst();
            break;
        }
        case 2:
        {
            insertAtLast();
            break;
        }
        case 3:
        {
            insertAtMid();
            break;
        }
        case 4:
        {
            delAtFirst();
            break;
        }
        case 5:
        {
            delAtLast();
            break;
        }
        case 6:
        {
            delAtMid();
            break;
        }
        case 7:
        {
            display();
            break;
        }
        case 8:
        {
            exit(0);
        }
        case 9:
        {
            char na[20];
            struct node *val;
            printf("Enter name that you want to search:");
            scanf("%s",na);
            val=search(na);
            if(val!=NULL){
                printf("\nName found!!");
                getch();
            }
            else{
                printf("\nName not found!");
            }
            break;
        }
        case 10:
        {
            modify();
            break;
        }
        default:
        printf("\nInvalid choice");
    }
}
    
}
struct node *createNode()
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter your name:- ");
   scanf("%s",tmp->data);
    tmp->pre=NULL;
    tmp->next=NULL;
    return tmp;  
}
void insertAtFirst()
{
    struct node *newNode, *t;
    newNode=createNode();
    t=start;
    if(start==NULL)
    {
        start=newNode;
    }
    else
    {
        t->pre=newNode;
        newNode->next=t;
        start=newNode;
    }
}
void insertAtLast()
{
    struct node *newNode, *t;
    newNode=createNode();
    if(start==NULL)
    {
        start=newNode;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newNode;
        newNode->pre=t;
        newNode->next=NULL;
    }

}
void insertAtMid()
{
    struct node *newNode, *t, *p;
    t=start;
    int f=0;
    char name[20];
    printf("\nEnter name that you want to insert in middle:-");
    scanf(" %s",name);
    while(t!=NULL)
    {
        if(strcmpi(t->data,name)==0)
        {
            f=1;
            break;
        }
        t=t->next;
    }
    if(f==1)
    {
    newNode=createNode();
    newNode->next=t->next;
    newNode->pre=t;
    if(t->next!=NULL){
    t->next->pre=newNode;
    }
    t->next=newNode;
    }

    if(f==0)
    printf("\nName not found!!");
    getch();
}
void delAtFirst()
{
    struct node *t;
   
    if(t==NULL)
    {
        printf("\nThere is no any node to delete");
        getch();
    }
    else{
    t=start;
    start=start->next;
    if(start!=NULL){
    start->pre=NULL;
      }
    t->next=NULL;
    free(t);
    }
    printf("\nDelete from first successfully");
    getch();

}
void delAtLast()
{
    struct node *t;
    if(start==NULL){
        printf("\nThere is no any node to delete");
        getch();
    }
    else if (start->next==NULL)
    {
        t=start;
        start=NULL;
        free(t);

    }
    else{
        t=start;
        while(t->next!=NULL){
            t=t->next;
        }
        if(t!=NULL){
        t->pre->next=NULL;
        }
        t->pre=NULL;
        free(t);
    }
    printf("\nDelete from Last successfully");
    getch();

}
void delAtMid()
{
    struct node *t, *p;
    char na[20];
    int f=0;
    if(start==NULL)
    {
        printf("\nThere is no any node to Delete");
        return;
    }
    t=start;
        printf("\nEnter name that you want to remove : ");
        scanf("%s",na);
        while(t!=NULL && strcmpi(t->data,na)!=0){
            t=t->next;
        }
        if(t==NULL){
            printf("\n%s is Not found in the list",na);
            getch();
            return;
        }
        //delete first node;
        if(t==start)
        {   
            start=start->next;
            if(t!=NULL)
            {
                t->pre = NULL;
            }
            t->next = NULL;
            free(t);
            printf("\n%s is deleted successfully!",na);
            getch();
            return;
        }
         // delete middle and last node
            t->pre->next=t->next;
            if(t->next!=NULL){
            t->next->pre=t->pre;
            }
            t->pre=NULL;
            t->next=NULL;
            free(t);
            printf("%s is deleted successfully!",na);
            getch();
            

}
void display()
{
    struct node *t;
    t=start;
    if(start==NULL)
    {
        printf("Node is Empty");
        getch();
    }
    else{
        printf("\nTotal Node is\n");
        while(t!=NULL)
        {
            printf(" %s,",t->data);
            t=t->next;
        }
    }
    getch();

}
struct node* search(char name[])
{
    struct node *t;
    t=start;
    while(t!=NULL){
        if(strcmpi(t->data,name)==0){
            return t;
        }
        t=t->next;
    }
    return NULL;
}
void modify()
{
    struct node *t;
    int f=0;
    char na[20];
    printf("\nEnter Name that you want to Update : ");
    scanf("%s",na);
    t=start;
    while(t!=NULL)
    {
        if(strcmpi(t->data, na)==0)
        {
            printf("\nEnter new Name :");
            scanf("%s",t->data);
            f=1;
            break;
        }
        t=t->next;
    }
    if(f==1){
    printf("Name modified successfully");
    getch();
    }
    else{
    printf("\nName not found!!");
    getch();
    }
}