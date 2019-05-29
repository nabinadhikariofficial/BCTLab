#include "stdio.h"
#include "math.h"

void main() {
  float a,b,fa,fb,x,fx;
  int count=1;
  while(1){
    printf("Enter two intial guesses:");
    scanf("%f%f",&a,&b);
    fa=((1-pow((1+a),4))/a)-1;
    fb=((1-pow((1+b),4))/b)-1;
    if(fa*fb>0)
      printf("Wrong intial guesses\n");
    else
      break;
  }
  printf("N\ta\t\tb\t\tf(a)\t\tf(b)\t\tx\t\tf(x)\n");
  do {
    x=(a+b)/2;
    fx=((1-pow((1+x),4))/x)-1;
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
    if ((fabs((a-b)/x))<0.00001){
      break;
    }
  } while(1);
  printf("Root is %.5f\n",x);
}
