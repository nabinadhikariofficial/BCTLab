#include "stdio.h"
#include "math.h"

void main() {
  float a,b,fa,fb,x,fx;
  int count=1;
  while(1){
    printf("Enter two intial guesses:");
    scanf("%f%f",&a,&b);
    fa=pow(a,5)-3*pow(a,3)-1;
    fb=pow(b,5)-3*pow(b,3)-1;
    if(fa*fb>0)
      printf("Wrong intial guesses\n");
    else
      break;
  }
  printf("N\ta\t\tb\t\tf(a)\t\tf(b)\t\tx\t\tf(x)\n");
  do {
    x=b-fb*((b-a)/(fb-fa));
    fx=pow(x,5)-3*pow(x,3)-1;
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
    if (count>10){
      break;
    }
  } while(1);
  printf("Root is %.5f\n",x);
}
