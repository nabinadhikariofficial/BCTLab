#include<stdio.h>

int main()
{
    int n,i,j;
    float x[20],y[20],xp,yp,t;
    printf("Enter no of observation:");
    scanf("%d",&n);
    printf("Enter the %d datas:\n",n);
    for(i=1 ;i<=n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    printf("\nEnter value of X(p) where Y(p) is to be calculated:");
    scanf("%f",&xp);
    yp=0;
    for(i=1;i<=n;i++)
    {
        t=1;
        for(j=1;j<=n;j++)
        {
            if(i!=j)
                t=t*(xp-x[i])/(x[i]-x[j]);
        }
        yp=yp+(t*y[i]);
    }
    printf("\nX(%f)=%f\n",xp,yp);
    return 0;
}
