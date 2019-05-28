#include<stdio.h>
#include<conio.h>
#define maxsize 3
void enq();
void deq();
void dis();
int head,tail,queue[maxsize];//head means front and tail means rear

void main() {
    int ch;
    head=0;
    tail=0;
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
    if(head==(tail+1)%maxsize)
        printf("\n\tQueue is FULL");
    else
    {
        printf("\n\tEnter data :- ");
        scanf("%d",&data);
        queue[tail]=data;
        tail=(tail+1)%maxsize;
        printf("\n\tDATA ENQUEUED");
    }
}



void deq() {
    int data;
    if(head==tail)
        printf("\n\tQueue is EMPTY");
    else
    {
        data=queue[head];
        head=(head+1)%maxsize;
        printf("\n\tData = %d",data);
        printf("\n\n\tDATA DEQUEUED");
    }
}

void dis() {
    int i;
    if(head==tail)
        printf("\n\tQueue is EMPTY");
    else
    {
        i=head;
        printf("\n(HEAD)\t\t");
        while(i!=tail)
            {
                printf("%d\t",queue[i]);
                i=(i+1)%maxsize;
            }
        printf("(TAIL)");
        if(head==(tail+1)%maxsize)
            printf("\n\n\tQueue is FULL");
    }
}
