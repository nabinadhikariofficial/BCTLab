#include "stdio.h"
#include "math.h"

void main() {
  float a,b,fa,fb,fx,x;
  int count=1;
  while(1){
    printf("Enter two intial guesses:");
    scanf("%f%f",&a,&b);
    fa=exp(2.8*a)+cos(a)-(3*a*a);
    fb=exp(2.8*b)+cos(b)-(3*b*b);
    //fa=cos(a)-3*a+1;
    //fb=cos(b)-3*b+1;
    if(fa*fb>0)
      printf("Wrong intial guesses\n");
    else
      break;
  }
  printf("N\ta\t\tb\t\tf(a)\t\tf(b)\t\tx\t\tf(x)\n");
  do {
    x=a-fa*((b-a)/(fb-fa));
    fx=exp(2.8*x)+cos(x)-(3*x*x);
    //fx=cos(x)-3*x+1;
    printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n",count,a,b,fa,fb,x,fx);
    count++;
    if (fx*fa>0) {
      a=x;
      fa=fx;
    }
    else{
      b=x;
      fb=fx;
    }
    if (fx<=0.00001){
      break;
    }
  } while(1);
  printf("Root is %.5f\n",x);
}
