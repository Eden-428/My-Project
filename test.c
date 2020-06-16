#include <stdio.h>

void  fct(int *px,int *py,int *pz){

*px = 10;
*py = 20;
*pz = 30;

}

int main(){
int x,y,z;
int *px = &x;
int *py = &y;
int *pz = &z;

fct(&x, &y, &z);
fct(px, py, pz);
printf("x=%d, y=%d, z=%d \n",x,y,z);
printf("px=%d, py=%d, pz=%d \n",*px,*py,*pz);

}
