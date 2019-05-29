#include "stdio.h"

int main() {
  int i,j,count=0;
  float x[7]={7.47,7.48,7.49,7.5,7.51,7.52,7.53},y[7]={0.193,0.195,0.198,0.201,0.203,0.206,0.208},fd[6],sd[5],td[4],fod[3],fid[2],sid,temp[13][8];
  for ( i = 0; i < 6; i++) {
    fd[i]=(y[i+1]-y[i]);
  }
  for ( i = 0; i < 5; i++) {
    sd[i]=(fd[i+1]-fd[i]);
  }
  for ( i = 0; i < 4; i++) {
    td[i]=(sd[i+1]-sd[i]);
  }
  for ( i = 0; i < 3; i++) {
    fod[i]=(td[i+1]-td[i]);
  }
  for ( i = 0; i < 2; i++) {
    fid[i]=fod[i+1]-fod[i];
  }
  sid=(fid[1]-fid[0]);

  for ( i = 0; i < 13; i++) {
    for ( j = 0; j < 8; j++) {
      temp[i][j]=32;
    }
  }

  for ( i = 0; i < 13; i++) {
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
  for ( i = 1; i < 12; i++) {
    if (i%2!=0) {
      temp[i][2]=fd[count];
      count++;
    }
  }

  count=0;
  for ( i = 2; i < 11; i++) {
    if (i%2==0) {
      temp[i][3]=sd[count];
      count++;
    }
  }

  count=0;
  for ( i = 3; i < 10; i++) {
    if (i%2!=0) {
      temp[i][4]=td[count];
      count++;
    }
  }

  count=0;
  for ( i = 4; i < 9; i++) {
    if (i%2==0) {
      temp[i][5]=fod[count];
      count++;
    }
  }

  count=0;
  for ( i = 4; i < 8; i++) {
    if (i%2!=0) {
      temp[i][6]=fid[count];
      count++;
    }
  }

  temp[6][7]=sid;
  printf("x\ty\tI\tII\tIII\tIV\tV\tVI\n");

  for (i = 0; i < 13; i++) {
    for (j = 0; j < 8; j++) {
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
