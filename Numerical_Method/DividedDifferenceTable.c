#include "stdio.h"

int main() {
  int x[5]={5,7,11,13,17},y[5]={150,392,1452,2366,5202};
  int i,j,count=0,fd[4],sd[3],td[2],fod,temp[9][6];
  for (size_t i = 0; i < 4; i++) {
    fd[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
  }
  for (size_t i = 0; i < 3; i++) {
    sd[i]=(fd[i+1]-fd[i])/(x[i+2]-x[i]);
  }
  for (size_t i = 0; i < 2; i++) {
    td[i]=(sd[i+1]-sd[i])/(x[i+3]-x[i]);
  }
  fod=(td[1]-td[0])/(x[4]-x[0]);

  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 6; j++) {
      temp[i][j]=32;
    }
  }

  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 2; j++) {
        if (i%2==0){
          if (j==0) {
            temp[i][j]=x[count];
          }
          if (j==1) {
            temp[i][j]=y[count];
            count++;
          }
        }
    }
  }
  count=0;
  for (size_t i = 1; i < 8; i++) {
    if (i%2!=0) {
      temp[i][2]=fd[count];
      count++;
    }
  }

  count=0;
  for (size_t i = 2; i < 7; i++) {
    if (i%2==0) {
      temp[i][3]=sd[count];
      count++;
    }
  }

  count=0;
  for (size_t i = 3; i < 6; i++) {
    if (i%2!=0) {
      temp[i][4]=td[count];
      count++;
    }
  }
  temp[4][5]=fod;
  printf("x\ty\tI DD\tII DD\tIII DD\tIV D\n");

  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0;j<6; j++) {
      if(i==4 && j==3){
        printf("%d\t",temp[i][j]);
      }
      else if (temp[i][j]==32) {
        printf("%c\t",temp[i][j]);
      }
      else{
        printf("%d\t",temp[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
