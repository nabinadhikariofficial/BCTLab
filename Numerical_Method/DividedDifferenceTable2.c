#include "stdio.h"

int main() {
  int i,j,count=0;
  float x[5]={10,20,30,40,50},y[5]={0.1736,0.342,0.5,0.6428,0.766},fd[4],sd[3],td[2],fod,temp[9][6];
  for ( i = 0; i < 4; i++) {
    fd[i]=(y[i+1]-y[i]);
  }
  for ( i = 0; i < 3; i++) {
    sd[i]=(fd[i+1]-fd[i]);
  }
  for ( i = 0; i < 2; i++) {
    td[i]=(sd[i+1]-sd[i]);
  }
  fod=(td[1]-td[0]);

  for ( i = 0; i < 9; i++) {
    for ( j = 0; j < 6; j++) {
      temp[i][j]=32;
    }
  }

  for ( i = 0; i < 9; i++) {
    for ( j = 0; j < 2; j++) {
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
  for ( i = 1; i < 8; i++) {
    if (i%2!=0) {
      temp[i][2]=fd[count];
      count++;
    }
  }

  count=0;
  for ( i = 2; i < 7; i++) {
    if (i%2==0) {
      temp[i][3]=sd[count];
      count++;
    }
  }

  count=0;
  for ( i = 3; i < 6; i++) {
    if (i%2!=0) {
      temp[i][4]=td[count];
      count++;
    }
  }
  temp[4][5]=fod;
  printf("angle\tSin(ang) I\tII\tIII\tIV\n");
  for ( i = 0; i < 9; i++) {
    for ( j = 0; j < 6; j++) {
      if (temp[i][j]==32) {
        printf("%c\t",temp[i][j]);
      }
      else{
        printf("%.4f\t",temp[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
