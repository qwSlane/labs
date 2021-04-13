#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "task_1.h"

int nod(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return nod(b, a % b);
}

void Input(int *arr)
{
    int i;
    char str[25];
    wprintf(L"Введите 2 дробных числа\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%s", str);
        if (atoi(str))
        {
            arr[i] = atoi(str);
            memset(str, 0, sizeof(str));
        }
        else
        {
            wprintf(L"Неверный тип данных\n");
            scanf("%s", str);
        }
    }
}

void Plus(int *arr)
{ /* + */

    int chres, znres, NOD, NOD2;
    NOD = nod(arr[1], arr[3]);
    znres = arr[1] * arr[3] / NOD;
    chres = arr[0] * arr[3] / NOD + arr[2] * arr[1] / NOD;

    NOD2 = nod(chres, znres);
    chres /= NOD2;
    znres /= NOD2;
    printf("%d\n", chres);
    printf("---\n");
    printf("%d\n", znres);
}

void Minus(int *arr)
{ /* -  */
 
    int chres, znres, NOD;
    NOD = nod(arr[1], arr[3]);
    znres = arr[1] * arr[3] / NOD;
    chres = arr[0] * arr[3] / NOD - arr[2] * arr[1] / NOD;

    NOD = nod(chres, znres);
    chres /= NOD;
    znres /= NOD;
    printf("%d\n", chres);
    printf("---\n");
    printf("%d\n", znres);
}

void Harmony(int *arr)
{ /*harmony */

    float harmony;
    int NOD, chres, znres;

    NOD = nod(arr[0], arr[2]);
    znres = arr[0] * arr[2] / NOD;
    chres = arr[1] * arr[2] / NOD + arr[3] * arr[0] / NOD;

    znres *= 2;
    NOD = nod(chres, znres);
    chres /= NOD;
    znres /= NOD;
    printf("%d\n", znres);
    printf("---\n");
    printf("%d\n", chres);

    harmony = (float)znres / (float)chres;

    printf("%f\n", harmony);
}

void Multiplying(int *arr)
{ /*  *   */

    int chres, znres, NOD;

    chres = arr[0] * arr[2];
    znres = arr[1] * arr[3];

    NOD = nod(chres, znres);

    chres /= NOD;
    znres /= NOD;

    printf("%d\n", chres);
    printf("---\n");
    printf("%d\n", znres);
}

void Division(int *arr)
{ /*  /  */

    int chres, znres, NOD;

    chres = arr[0] * arr[3];
    znres = arr[1] * arr[2];

    NOD = nod(chres, znres);

    chres /= NOD;
    znres /= NOD;

    printf("%d\n", chres);
    printf("---\n");
    printf("%d\n", znres);
}

void Info()
{

    printf("Version: 1.0\n");
    printf("Creator: Vasilewsckij");
}

int main()
{

    int exit;
    int arr[4];
    char mainstring[25];
    int ch_1, zn_1, ch_2, zn2;

    exit = 1;
    setlocale(LC_ALL, "Rus");

    Input(arr);

    while (exit)

    {
        scanf("%s", mainstring);
        if (!strncmp(mainstring, "sum", 3))
        {
            Plus(arr);
        }

        else if (!strncmp(mainstring, "diff", 4))
        {
            Minus(arr);
        }

        else if (!strncmp(mainstring, "info", 4))
        {
            Info();
        }

        else if (!strncmp(mainstring, "harmony", 7))
        {
            Harmony(arr);
        }

        else if (!strncmp(mainstring, "Mult", 4))
        {
            Multiplying(arr);
        }

        else if (!strncmp(mainstring, "division", 8))
        {
            Division(arr);
        }

        else if (!strncmp(mainstring, "input", 5))
        {
            Input(arr);
        }

        else if (!strncmp(mainstring, "exit", 4))
        {
            exit = 0;
        }

        else if (!strncmp(mainstring, "print", 5))
        {
            printf("%d\n", arr[0]);
            printf("---\n");
            printf("%d\n", arr[1]);
        }

        printf("%d\n", arr[2]);
        printf("---\n");
        printf("%d\n", arr[3]);
    }
}
