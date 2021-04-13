#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "task_2.h"

int fact(int i)
{
  if(i==1) return(i);
  return i * fact(i - 1);
}

#ifndef TESTING

int main(){

float e, x;
int n;
double comparition, talor;

scanf("%f", &x);
scanf("%f", &e);

n=1;

do 
{
    talor+=pow((-1),n-1)*(pow(x,2*n-1)/fact(2*n-1));
    comparition=fabs(sin(x)-talor);
    n++;
}  while(comparition>e);
n -= 1;
printf("%d",n);

}
#endif
