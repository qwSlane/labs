#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "task.h"

int test_average()
{

    int i, j;
    int **arr = (int **)malloc(3 * sizeof(int *));
    {
        for (i = 0; i < 3; i++)
        {
            arr[i] = (int *)malloc(3 * sizeof(int));
        }
    }

    for (i = 0; i < 3; i++)
     {
         for(j = 0; j < 3; j++)
         {
            if(j == 1)
             arr[i][j]=2;  
            arr[i][j]=3;
         }
     }

        assert(average(arr, 3, 0) == 3);
        assert(average(arr, 3, 1) == 2);
        
}

#undef main

int main()
{
    test_average();
    printf("Test succesfully completed");
    return 0;
}