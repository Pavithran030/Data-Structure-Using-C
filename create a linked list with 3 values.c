
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int d;
    struct node *l;
    
};

struct node* create()
{
    struct node *h,*n1,*n2,*t;

    h=malloc(sizeof(struct node));           // 1st node
    h->d=50;
    h->l=NULL;
    
    n1=malloc(sizeof(struct node));          // 2nd node
    n1->d=60;
    n1->l=NULL;
    h->l=n1;
    
    n2=malloc(sizeof(struct node));          // 3rd node
    n2->d=70;
    n2->l=NULL;
    n1->l=n2;

    struct node *t1=malloc(sizeof(struct node));   // adding at end
    t1->d=100;
    t1->l=NULL;

    printf("1st 3 nodes\n");

    t=h;                              // assign the head to the new variable for traversing 
    
    while(t!=NULL)
    {
        printf("%d\n",t->d);
        t=t->l;
    }

    n2->l=t1;   // assign the new node address to the NULL part in the 3rd node

    return h;

}

int position(struct node *h,int nu,int va)
{
    int c=1;
    struct node *tr,*p2;
    p2=malloc(sizeof(struct node));
    p2->d=va;
    p2->l=NULL;
    tr=h;

    while(c!=nu)
    {
        c++;
        tr=tr->l;
    }

    p2->l=tr->l; // assign the 3rd node address to the newly created node (see in the line 55 )

    tr->l=p2;  // now assign the new node address to the 2nd node

}


void print(struct node *h)
{
    if(h==NULL)
    {
        printf("The node is empty");
    }
    
    printf("\nAll nodes after inserting \n");

    while(h!=NULL)
    {
        printf("%d\n",h->d);
        h=h->l;
    }

}

int main() {
    struct node *h=create();
    print(h);
    position(h,2,200);
    print(h);
}
