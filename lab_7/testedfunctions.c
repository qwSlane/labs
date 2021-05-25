#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "testedfunctions.h"

void readfile(List **cr)
{
    FILE *file;
    file = fopen("info.txt", "r");
    char str[128], name[128], route[128];
    char dop[128] = "-";
    float cost;
    int places, day, year, month;

    while (fgets(str, 128, file))
    {
        TourTemplate *template;

        strcpy(name, str);

        fgets(str, 128, file);
        cost = atof(str);

        fgets(str, 128, file);
        places = atoi(str);

        fgets(str, 128, file);
        strcpy(route, str);

        fgets(str, 128, file);
        day = atoi(str);

        fgets(str, 128, file);
        month = atoi(str);

        fgets(str, 128, file);
        year = atoi(str);
        template = create(name, cost, places, route, day, year, month);
        fgets(str, 128, file);
        if (str[0] != dop[0])
        {
            Minor *min = (Minor *)malloc(sizeof(Minor));
            char *house = (char *)malloc(128 * sizeof(char));
            strcpy(house, str);
            min->housing = house;
            fgets(str, 128, file);
            min->insurance = atoi(str);
            fgets(str, 128, file);
            min->nutrition = atoi(str);
            template->secondary = min;
            fgets(str, 128, file);
        }
        add(cr, template);
    }
    fclose(file);
}

TourTemplate *create(char *name, float cost, int places, char *route, int day, int year, int month)
{
    Date *date = (Date *)malloc(sizeof(Date));
    if (date != NULL)
    {
        date->day = day;
        date->month = month;
        date->year = year;

        Mandatory *cr = (Mandatory *)malloc(sizeof(Mandatory));

        cr->cost = cost;
        cr->date = date;
        cr->places = places;
        char *rt = (char *)malloc(128 * sizeof(char));
        strcpy(rt, route);
        cr->route = rt;

        TourTemplate *templ = (TourTemplate *)malloc(sizeof(TourTemplate));
        char *a = (char *)malloc(128 * sizeof(char));
        strcpy(a, name);
        templ->name = a;
        templ->crucial = cr;
        templ->secondary = NULL;

        return templ;
    }
    else
        printf("Access denied");
}

void add(List **cr, TourTemplate *info)
{
    if (*cr == NULL)
    {
        *cr = (List *)malloc(sizeof(List));
        Node *root = (Node *)malloc(sizeof(Node));
        root->info = info;
        root->trip = NULL;
        root->next = root->prev = NULL;
        (*cr)->head = (*cr)->tail = root;
        return;
    }
    else
    {
        Node *added = (Node *)malloc(sizeof(Node));
        added->info = info;
        added->next = NULL;
        added->trip = NULL;

        added->prev = (*cr)->tail;
        (*cr)->tail->next = added;

        (*cr)->tail = added;
        return;
    }
}

void show(List *root)
{
    Node *head;
    head = root->head;
    while (head != NULL)
    {
        templateInfo(head->info);
        head = head->next;
    }
}

void templateInfo(TourTemplate *templ)
{
    printf("\n");
    printf("%s", templ->name);
    printf("Cost: %.2f$\n", templ->crucial->cost);
    printf("Number of seats: %d\n", templ->crucial->places);
    printf("Date: %d.%d.%d\n", templ->crucial->date->day, templ->crucial->date->month, templ->crucial->date->year);
    printf("Route: %s\n", templ->crucial->route);

    if (templ->secondary != NULL)
    {
        printf("Hotel: %s", templ->secondary->housing);
        if (templ->secondary->insurance == 1)
        {
            printf("Insurance: included\n");
        }
        if (templ->secondary->nutrition == 1)
        {
            printf("Nutrition: included\n");
        }
    }
}
