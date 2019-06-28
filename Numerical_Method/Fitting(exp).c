#include<stdio.h>
#include<math.h>

#define S 50

int main()
{
 int n, i;
 float x[S], y[S], sumX=0, sumX2=0, sumY=0, sumXY=0, a, b, A, B;


 printf("How many data points?\n");
 scanf("%d", &n);
 for(i=1;i<=n;i++)
 {
  printf("x[%d]=",i);
  scanf("%f", &x[i]);
  printf("y[%d]=",i);
  scanf("%f", &y[i]);
 }

 for(i=1;i<=n;i++)
 {
  sumX = sumX + x[i];
  sumX2 = sumX2 + x[i]*x[i];
  sumY = sumY + log(y[i]);
  sumXY = sumXY + x[i]*log(y[i]);
 }

 B = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
 A = (sumY - B*sumX)/n;

 a = exp(A);
 b = exp(B);

 printf("Values are: a=%0.2f and b=%0.2f",a,b);

 getch();
 return(0);
}
