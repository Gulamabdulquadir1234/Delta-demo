#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <malloc.h>
struct node
{
    int roll;
    struct node *next;
};
struct node *start=NULL;
void insertAtfirst();
void insertAtlast();
void insertAtmid();
void delAtfirst();
void delAtlast();
void delAtmid();
void disp();
struct node *search(int);
void modify();
void sort();
int main()
{
    int ch;
    while(1){
    system("cls");
    printf("\n1-Insert from Start");
    printf("\n2-Insert from End");
    printf("\n3-Insert from Middle");
    printf("\n4-Delete from Start");
    printf("\n5-Delete from End");
    printf("\n6-Delete from Middle");
    printf("\n7-Display");
    printf("\n8-Exit");
    printf("\n9-Search Record");
    printf("\n10-Modify Record");
    printf("\n11-Sort Record");
    printf("\nEnter your choice:- ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            insertAtfirst();
            break;
        }
        case 2:
        {
            insertAtlast();
            break;
        }
        case 3:
        {
           insertAtmid();
           break; 
        }
        case 4:
        {
            delAtfirst();
            break;
        }
        case 5:
        {
            delAtlast();
            break;
        }
        case 6:
        {
            delAtmid();
            break;
        }
        case 7:
        {
            disp();
            break;
        }
        case 8:
        {
            exit(0);
        }
        case 9:
        {
            int n;
            struct node *val;
            printf("\nEnter roll that you want to search:");
            scanf("%d",&n);
            val=search(n);
            if(val!=NULL)
            {
                printf("\nRoll found!");
                getch();
            }
            else{
                    printf("\nRoll not found!!");
                    getch();
            }
            break;
        }
        case 10:
        {
            modify();
            break;
        }
        case 11:
        {
            sort();
            break;
        }
        default:
        printf("\nInvalid Choice");

    }   
}
}
struct node *createNode()
{
    struct node *h1;
    h1=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter roll :");
    scanf("%d",&h1->roll);
    h1->next=NULL;
    return h1;
}
void insertAtfirst()
{
    struct node *newnode;
    newnode=createNode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
void insertAtlast()
{
    struct node *newnode, *t;
    newnode=createNode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newnode;
        printf("\nrecord inserted successfully");
        getch();
        
    }

}
void insertAtmid()
{
    struct node *newnode,*t;
    int n,f=0;
    if(start==NULL)
    {
        printf("\nList is empty please insert at least Two node");
        getch();
        return;
    }
    else{
    t=start;
    printf("\nEnter roll you want to insert in the middle :- ");
    scanf("%d",&n);
    while(t!=NULL)
    {
        if(t->roll==n)
        {
            f=1;
            break;
        }
        t=t->next;
    }
    if(f==1)
    {
        newnode=createNode();
        newnode->next=t->next;
        t->next=newnode;
        printf("\nInsert from Middle successfully");
        getch();
    }
    else{
    printf("\nThere is no roll where you want to insert");
    getch();
    }   
}
}
void delAtfirst()
{
    struct node *t;
    t=start;
    if(t==NULL)
    {
        printf("\nThere is no any node to Delete");
        return;
    }
    start=start->next;
    t->next=NULL;
    free(t);
    printf("\nDelete from first Successfully");
    getch();
    
}
void delAtlast()
{
    struct node *pre, *nextnode;
    nextnode=start;
    if(start==NULL)
    {
        printf("\nThere is no Any Node to Delete");
        getch();
        return;
    }
    else{
        pre=start;
        while(nextnode->next!=NULL)
        {
            pre=nextnode;
            nextnode=nextnode->next;
        }
        pre->next=nextnode->next;
        free(nextnode);
        printf("\nDelete from End successfully");
        getch();
    }


}
void delAtmid()
{
    int target;
    printf("\nEnter roll that you want to remove: ");
    scanf("%d",&target);
    struct node *tmp;
    tmp=search(target);

    if(tmp==NULL)
    {
        printf("\nNode with value %d not found!",target);
        getch();
        return;
    }
    // Only one Node to delete
    if(tmp==start){
        start=start->next;
        free(tmp);
        printf("\nNode Deleted successfully");
        getch();
        return;
    }
    //multiple Node to delete
    struct node *pre;
    pre=start;
    while(pre->next!=tmp){

        pre=pre->next;
    }
        pre->next=tmp->next;
        free(tmp);
        printf("\nNode Deleted successfully");
        getch();
}
void disp()
{
    struct node *t;
    t=start;
    if(t==NULL)
    {
        printf("\nNode is Empty");
        getch();
        return ;
    }
    printf("\ntotal Node is:\n");
    while(t!=NULL)
    {

        printf(" %d",t->roll);
        t=t->next;
    }
    getch();
    
}
struct node* search(int roll)
{
    struct node *t;
    t=start;
    while(t!=NULL){
        if(t->roll==roll){
        return t;
        }
         t=t->next;
    }
    return NULL;
}
void modify()
{
    struct node *t;
    int n,f=0;
    printf("\nEnter Roll that you want to Update: ");
    scanf("%d",&n);
    t=start;
    while(t!=NULL)
    {
        if(t->roll==n)
        {
            printf("\nEnter New Roll: ");
            scanf("%d",&t->roll);
            f=1;
            break;
        }
        t=t->next;
    }
    if(f==1){
    printf("Roll modified successfully ");
    getch();
    }
    else{
    printf("Roll Not Found");
    getch();
    }
}
void sort()
{
    struct node *t, *p;
    t=start;
    int temp;
    while(t!=NULL){
            p=t->next;
        while(p!=NULL){

            if(t->roll>p->roll){
                temp=t->roll;
                t->roll=p->roll;
                p->roll=temp;

            }
            p=p->next;
        }
        t=t->next;
    }
    printf("\nAll record Sorted!!");
    getch();
}