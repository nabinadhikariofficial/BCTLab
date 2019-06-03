#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 10
struct node
{
    int info,next;
}node[MAXSIZE];

int avail=0,head=-1;

int getnode()
{
    int p;
    if(avail==-1)
        p=avail;
    else
    {
        p=avail;
        avail=node[avail].next;
    }
    return p;
}

void freenode(int p)
{
    if(p>=0 && p<=MAXSIZE-1)
    {
        node[p].next=avail;
        avail=p;
    }
    else
        printf("\n\n\t\tInvalid Deletion !!! ");
}

void ins()
{
    int np, p, ch, key, item, flag=0, i, temp;
    np=getnode();
    if(np==-1)
        printf("\n\n\t\tMemory Cannot be Allocated. ( OVERFLOW )");
    else
    {
        printf("\n\nEnter data :- ");
        scanf("%d",&item);
        node[np].info=item;
        node[np].next=-1;
        if(head==-1)
            head=np;
        else
        {
            printf("\n\nINSERT WHERE:\n\n\t1. FRONT\n\n\t2. LAST\n\n\t3. AFTER\n\n\t4.BEFORE");
            printf("\n-------------------------------");
            printf("\n\nSelect Location :- ");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    node[np].next=head;
                    head=np;
                    break;

                case 2:
                    p=head;
                    while(node[p].next!=-1)
                    {
                        p=node[p].next;
                    }
                    node[p].next=np;
                    break;

                case 3:
                    printf("\n\n\tEnter nth key :- ");
                    scanf("%d",&key);
                    p=head;
                    for(i=0;i<key-1;i++)
                    {
                        if(p!=-1)
                            p=node[p].next;
                    }
                    if(p==-1)
                    {
                        printf("\n\n\tINVALID INSERTION.");
                        freenode(np);
                        flag=1;
                    }
                    else
                    {
                        node[np].next=node[p].next;
                        node[p].next=np;
                    }
                    break;
                case 4:
                    printf("\n\n\tEnter nth key :- ");
                    scanf("%d",&key);
                    p=head;
                    for(i=0;i<key-1;i++)
                    {
                        if(p!=-1)
                        {
                            temp=p;
                            p=node[p].next;
                        }

                    }
                    if(p==-1)
                    {
                        printf("\n\n\tINVALID INSERTION.");
                        freenode(np);
                        flag=1;
                    }
                    else if(key==1)
                    {
                        node[np].next=head;
                        head=np;
                    }
                    else
                    {
                        node[np].next=node[temp].next;
                        node[temp].next=np;
                    }
                    break;
                default:
                    printf("\n\n\tEnter correct choice..........");
                    freenode(np);
                    flag=1;

            }
            if(flag!=1)
                printf("\n\n\tDATA INSERTED !!!");

        }
    }
}

void del()
{
    int p, ch, key, item, i, flag=0, temp;
    p=head;
    if(head==-1)
        printf("\n\n\tList is EMPTY !!! ");
    else
    {
        printf("\n\nDELETE WHERE:\n\n\t1. FRONT\n\n\t2. LAST\n\n\t3. AFTER\n\n\t4.BEFORE");
        printf("\n-------------------------------");
        printf("\n\nSelect Location :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head=node[p].next;
                item=node[p].info;
                freenode(p);
                break;
            case 2:
                if(node[p].next==-1)
                    head=-1;
                else
                {
                    while(node[p].next!=-1)
                    {
                        temp=p;
                        p=node[p].next;
                    }
                    node[temp].next=-1;
                }
                item=node[p].info;
                freenode(p);
                break;
            case 3:
                printf("\n\n\tEnter nth key :- ");
                scanf("%d",&key);
                p=head;
                for(i=0;i<key;i++)
                {
                    if(p!=-1)
                    {
                        temp=p;
                        p=node[p].next;
                    }
                }
                if(p==-1)
                {
                    printf("\n\n\tINVALID DELETION.");
                    flag=1;
                }
                else
                {
                    node[temp].next=node[p].next;
                    item=node[p].info;
                    freenode(p);
                }
                break;
            case 4:
                printf("\n\n\tEnter nth key :- ");
                scanf("%d",&key);
                p=head;
                for(i=0;i<key-2;i++)
                {
                    if(p!=-1)
                    {
                        temp=p;
                        p=node[p].next;
                    }
                }
                if(key==1 || node[p].next==-1)
                {
                    printf("\n\n\tINVALID DELETION.");
                    flag=1;
                }
                else if(key==2)
                {
                    head=node[p].next;
                    item=node[p].info;
                    freenode(p);
                }
                else
                {
                    node[temp].next=node[p].next;
                    item=node[p].info;
                    freenode(p);
                }
                break;
            default:
                printf("\n\n\tEnter correct choice..........");
                flag=1;
        }
        if(flag!=1)
            printf("\n\n\tDATA DELETED = %d. !!!",item);
    }
}

void dis()
{
    int ch, p, i;
    printf("\n\nDISPLAY HOW:\n\n\t1. LINEAR\n\n\t2. ARRAY");
    printf("\n-------------------------------");
    printf("\n\nSelect Choice :- ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            p=head;
            if(head==-1)
                printf("\n\n\tList is EMPTY !!! ");
            else
            {
                printf("\n\nData On The List :-");
                printf("\n--------------------\n\n");
                printf(" ( HEAD ) --> ");
                while(p!=-1)
                {
                    printf("%d  ->  ",node[p].info);
                    p=node[p].next;
                }
                printf("( NULL )");

            }
            break;
        case 2:
            p=head;
            if(head==-1)
                printf("\n\n\tList is EMPTY !!! ");
            else
            {
                printf("\n\n\tINDEX\tINFO\tNEXT\n");
                printf("\t----------------------\n");
                for(i=0;i<MAXSIZE;i++)
                {
                    printf("\t %d\t %d\t %d",i,node[i].info,node[i].next);
                    if(i==p)
                        printf("\t( HEAD )");
                    printf("\n");
                }
            }
            break;
        default:
            printf("\n\n\tEnter correct choice..........");
    }
}

int main()
{
    int i,ch;
    for(i=0;i<MAXSIZE-1;i++)
    {
        node[i].next=i+1;
    }
    node[MAXSIZE-1].next=-1;
    while(1)
    {
        printf("\n\nStatic Linear Linked List:\n\n\t1. INSERT\n\n\t2. DELETE\n\n\t3. DISPLAY\n\n\t4. EXIT");
        printf("\n-------------------------------");
        printf("\n\nEnter your choice :- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                ins();
                break;
            case 2:
                del();
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
    return 0;
}
