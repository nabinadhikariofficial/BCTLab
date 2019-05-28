#include<stdio.h>
float A[20][20];
int n;

void pri()
{
    int i,j;
    printf("\nS.No:\t");
    for(i=1;i<=n;i++){
        printf("x[%d]\t",i);
    }
    printf("B\n");
    for(i=1;i<=n;i++)
    {
        printf("%d)\t",i);
        for(j=1;j<=(n+1);j++)
        {
            printf("%.1f\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------------------\n");
}

int main()
{
    int i,j,k;
    float pivot;
    printf("Enter order of matrix:");
    scanf("%d",&n);
    printf("\nEnter augmented matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
            printf("A[%d][%d]:",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++){
           if(i==j)
           {
               pri();
               pivot=A[i][i];
               for(k=1;k<=(n+1);k++)
               {
                   A[j][k]=A[i][k]/pivot;
               }
               pri();
           }
           else
           {
               pivot=A[j][i]/A[i][i];
               for(k=1;k<=(n+1);k++)
               {
                   A[j][k]=A[j][k]-pivot*A[i][k];
               }
           }
        }
    }
    printf("\n");
    pri();
    printf("\nSolution is:\n");
    for(i=1;i<=n;i++)
    {
        printf("x[%d]=%.2f\n",i,A[i][n+1]);
    }
    return 0;
}
