#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Queue
{
    int customers[MAX];
    int front,rear;
};

void initial(struct Queue *q)
{
    q->front=-1;
    q->rear=-1;
}
bool isEmpty(struct Queue *q)
{
    return q->front==-1;
}
bool isFull(struct Queue *q)
{
    return q->rear==MAX-1;
}
void enqueue(struct Queue *q,int ID)
{
    if(isFull(q))
    {
        printf("Queue is full ");
        return;
    }
    if(isEmpty(q))
    {
        q->front=0;
    }
    q->customers[++q->rear]=ID;
    printf("Customer ID  %d Added\n",ID);
}

void dequeue(struct Queue *q)
{
    if(isFull(q))
    {
        printf("Queue is empty ");
        return;
    }
    printf("Serving customer %d\n",q->customers[q->front]);
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;

    }
    else{
        q->front++;
    }
}

void display(struct Queue *q)
{
    if(isFull(q))
    {
        printf("No customers ");
        return;
    }
    printf("Current Queue\n");
    for(int i=0;i<q->rear;i++)
    {
        printf("Customer : %d\n",q->customers[i]);
    }
}
int main()
{
    struct Queue q;
    initial(&q);
    int choice,ID;
    while (1)
    {
        printf("\n1.Add Customer\n2.Serve next customer\n3.Display queue\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter ID : ");
            scanf("%d",&ID);
            enqueue(&q,ID);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            return 0;       
        default:
            printf("Invalid choice");
            break;
        }
    }
    return 0;
    
}
