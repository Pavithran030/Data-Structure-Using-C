#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void InsertAtEnd(int val){

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newnode==NULL){
        printf("\nout of memory.\n");
    }

    newnode->data=val;
    newnode->next=NULL;

    if (head==NULL){
        head=newnode;
    }
    else{

        struct Node *temp=head;

        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }

    
}

void insert(int pos,int val)
{
    struct Node *tr=head,*new;
    new=malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    int c=1;
    while (pos-1!=c )
    {
        c++;
        tr=tr->next;
    }
    new->next=tr->next;
    tr->next=new;
    
}

void delete(int val)
{
    struct Node *pr,*ne;
    pr=NULL;
    ne=head;
    while (val!=ne->data)
    {
        pr=ne;
        ne=ne->next;
    }
    pr->next=ne->next;
    free(ne);
    ne=NULL;
    
}

void display(){

    struct Node *temp=head;
    
    if (head==NULL){
        printf("\nThe linked list is empty.\n");
    }

    while (temp!=NULL){
        
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}

int main(){

    while (1){
        printf("\nLinked Insertion Operations :\n");
        printf("1.Insert at end.\n");
        
        printf("2.Insert at Any Position.\n");
        printf("3.Deletion at Any position.\n");
        printf("4.Display.\n");
        printf("5.exit.\n");

        printf("Enter the option :");
        int choice,val,pos;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data :");
            scanf("%d",&val);
            InsertAtEnd(val);
            break;

        case 2:
            printf("Enter the Position :");
            scanf("%d",&pos);
            printf("Enter the data :");
            scanf("%d",&val);
            insert(pos,val);
            break;

        case 3:
            printf("\nEnter the element to delete : ");
            scanf("%d",&val);
            delete(val);
            break;
        
        case 4:
            printf("\nDisplay the linked list \n");
            display();
            break;
        case 5:
            printf("\nexited from the operations.\n");
            exit(0);
        
        default:
            printf("\nInvalid option, please give correctly.\n");
            break;
        }
    }
}
