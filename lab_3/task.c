#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#include "task.h"

float average(int **arr, int counter, int pos)
{
  float average = 0;
  int i;

  for (i = 0; i < counter; i++)
  {
    average += arr[i][pos];
  }
  average /= counter;
  return average;
}

#ifndef TESTING

int main()
{
  int counter;
  int **arr;
  int i;
  int j;
  float average_s = 0;
  float average_h = 0;
  float average_v = 0;
  double usage = 0;
  int temp;

  scanf("%d", &counter);

  arr = (int **)malloc(counter * sizeof(int *));
  {
    for (i = 0; i < counter; i++)
    {
      arr[i] = (int *)malloc(3 * sizeof(int));
    }
  }

  for (i = 0; i < counter; i++)
  {
    for (j = 0; j < 3; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  average_s = average(arr, counter, 0);

  average_h = average(arr, counter, 1);

  average_v = average(arr, counter, 2);

  usage = (average_h * average_s * average_v);
  printf("water consumption %f", usage);
}

#endif
