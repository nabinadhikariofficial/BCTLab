#include<stdio.h>
#include<math.h>
float f(float x)
{
    return(log(x));
}

int main()
{
    int i,n;
    float a,b,result,h,k;
    printf("Enter lower limit(a), Upper Limit(b) and subintervals(n):");
    scanf("%f%f%d",&a,&b,&n);
    h=(b-a)/n;
    result=f(a)+f(b);
    for(i=1;i<n;i++)
    {
        k=a+i*h;
        result=result+2*f(k);
    }
    result=(h/2)*result;
    printf("Answer is :%f",result);
    return(0);
}
