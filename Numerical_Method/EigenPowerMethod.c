#include <stdio.h>
float a[20][20],x[40],sum=0,error,lambda_old,lambda_new;
int i,j,n,count=1;

void pri()
{

    printf("\nIteration:%d\n\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%.2f\t",a[i][j]);
        }
            printf("\t|%.4f\t|=\t|%.4f|",x[i],x[n+i]);
            printf("\n");
    }
    printf("\nlambda is %f\n",lambda_new);
    count++;
}

int main()
{
    printf("Enter Order of matrix:");
    scanf("%d",&n);
    printf("Enter tolerance error:");
    scanf("%f",&error);
    printf("\nEnter Initial guess:\n");
    for(i=1;i<=n;i++)
    {
        printf("X[%d]=",i);
        scanf("%f",&x[i]);
    }
    printf("\nEnter Matrix element row wise:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("A[%d][%d]=",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    lambda_old=1.0;
    while(1)
    {
        for(i=1;i<=n;i++)
        {
            sum=0.0;
            for(j=1;j<=n;j++)
            {
                sum=sum+a[i][j]*x[j];
            }
            x[n+i]=sum;
        }
        lambda_new=x[n+1];
        for(i=1;i<=n;i++)
        {
            if(lambda_new<x[n+i])
                lambda_new=x[n+i];
        }
        pri();
        for(i=1;i<=n;i++)
        {
            x[i]=x[n+i]/lambda_new;
        }
        if(fabs(lambda_old-lambda_new)>error)
            lambda_old=lambda_new;
        else
            break;
    }
    return 0;
}
