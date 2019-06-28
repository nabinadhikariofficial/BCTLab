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
  sumY = sumY + y[i];
  sumXY = sumXY + x[i]*y[i];
 }

 B = (n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
 A = (sumY - B*sumX)/n;

 //a = exp(A);
 //b = exp(B);

 printf("Values are: A=%0.2f and B=%0.2f",A,B);

 getch();
 return(0);
}
