#include<stdio.h>
#include<conio.h>
#define maxsize 3
void enq();
void deq();
void dis();
int front,rear,queue[maxsize];

void main() {
    int ch;
    front=0;
    rear=-1;
    while(1)
    {
        printf("\n\nQueue:\n\n\t1. ENQUEUE\n\n\t2. DEQUEUE\n\n\t3. DISPLAY\n\n\t4.EXIT");
        printf("\n-------------------------------");
        printf("\n\nEnter your choice :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enq();
                break;
            case 2:
                deq();
                break;
            case 3:
                dis();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\n\tEnter correct choice..........");
        }
    }
}

void enq() {
    int data;
    if(rear>=maxsize-1)
        printf("\n\tQueue is FULL");
    else
    {
        printf("\n\tEnter data :- ");
        scanf("%d",&data);
        rear++;
        queue[rear]=data;
        printf("\n\tDATA ENQUEUED");
    }

}
void deq() {
    int data,i;
    if(front>rear)
        printf("\n\tQueue is EMPTY");
    else
    {
        data=queue[front];
        for(i=0;i<=rear;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
        printf("\n\tData=%d",data);
        printf("\n\n\tDATADEQUEUED");
    }
}

void dis() {
    int i;
    if(front>rear)
        printf("\n\tQueue is EMPTY");
    else
    {
        printf("\n(FRONT)\t\t");
        for(i=front;i<=rear;i++) {
                printf("%d\t",queue[i]);
        }
        printf("(REAR)");
        if(rear>=maxsize-1)
            printf("\n\n\tQueue FULL");
    }

}
