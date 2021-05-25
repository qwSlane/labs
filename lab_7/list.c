#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "list.h"

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

int insurance()
{
    int type;
    printf("Insurence \n");
    printf("1 - yes \n");
    printf("0 - no \n");
    scanf("%d", &type);
    return type;
}

int nutritions()
{
    int f_type;
    system("cls");
    printf("Food \n");
    printf("0 - - \n");
    printf("1 - include \n");
    scanf("%d", &f_type);
    return f_type;
}
int hous()
{
    int h_type;
    printf("Accomodation \n");
    printf("0 - not include  \n");
    printf("1 - * \n");
    printf("2 - ** \n");
    printf("3 - *** \n");
    printf("4 - **** \n");
    printf("5 - ***** \n");
    scanf("%d", &h_type);
    return h_type;
}

TourTemplate *secondary(TourTemplate *temp)
{
    Minor *addition;
    int insurence, nutrritions, type, h_type, f_type;
    char *tab, *housing;

    addition = (Minor *)malloc(sizeof(Minor));
    tab = "\n";
    float cost = 99.99;
    type = insurance();
    cost += 50 * type;
    addition->insurance = (type == 1) ? 1 : 0;

    f_type = nutritions();
    addition->nutrition = (f_type != 0) ? 1 : 0;
    cost += 25 * type;
    system("cls");

    h_type = hous();
    cost += h_type * 12;
    housing = (char *)malloc(50 * sizeof(char));
    switch (h_type)
    {
    case 1:
        housing = "Hotel*\n";
        break;
    case 2:
        housing = "Hotel**\n";
        break;
    case 3:
        housing = "Hotel***\n";
        break;
    case 4:
        housing = "Hotel****\n";
        break;
    case 5:
        housing = "Hotel*****\n";
        break;
    default:
        housing = "Not include\n";
        break;
    }
    addition->housing = housing;
    temp->crucial->cost = cost;
    temp->secondary = addition;
    return temp;
}

TourTemplate *createCustom()
{
    TourTemplate *temp;
    char *name, *route;
    float cost;
    char *tab;
    int day, month, year, num, type;
    printf("1.Standart\n");
    printf("2. Premium\n");
    scanf("%d", &type);
    system("cls");
    name = (char *)malloc(50 * sizeof(char));
    route = (char *)malloc(50 * sizeof(char));
    tab = "\n";
    printf("Name: \n");
    scanf("%s", name);
    name = strcat(name, tab);
    printf("Date: \n");
    scanf("%d%d%d", &day, &month, &year);
    printf("Route:\n");
    scanf("%s", route);
    printf("Number of seats: \n");
    scanf("%d", &num);

    temp = create(name, 0, num, route, day, year, month);

    if (type == 1)
    {
        cost = 99.99;
        temp->crucial->cost = cost;
    }
    else
    {
        temp = secondary(temp);
    }
    return temp;
}

void preview(List *root)
{
    Node *head;
    int i;
    head = root->head;
    for (i = 0; head != NULL; i++)
    {
        head->position = i;
        printf("%d. %s", head->position, head->info->name);
        head = head->next;
    }
}

void change(List **root, int pos)
{
    Node *head;
    Minor *addition;
    TourTemplate *templ;
    char *name, *route;
    int day, month, year, num, type, h_type, f_type;
    head = (*root)->head;
    name = (char *)malloc(50 * sizeof(char));
    route = (char *)malloc(50 * sizeof(char));

    while (head->position != pos)
    {
        head = head->next;
    }
    templ = head->info;
    printf("\n");
    printf("1.%s", templ->name);
    printf("2.Date: %d.%d.%d\n", templ->crucial->date->day, templ->crucial->date->month, templ->crucial->date->year);
    printf("3.Number of seats: %d\n", templ->crucial->places);
    printf("4.Route: %s\n", templ->crucial->route);
    if (templ->secondary == NULL)
    {
        printf("5.Premium upgrade\n");
    }
    else
    {
        printf("5.To standart\n");

        addition = templ->secondary;

        printf("6.Hotel: %s", templ->secondary->housing);
        if (templ->secondary->insurance == 1)
        {
            printf("7.Insurance: included\n");
        }
        if (templ->secondary->nutrition == 1)
        {
            printf("8.Nutrition: included\n");
        }
    }
    printf("\n");
    scanf("%d", &type);

    switch (type)
    {
    case 1:
    {
        printf("Name: \n");
        scanf("%s", name);
        templ->name = name;
        break;
    }
    case 2:
    {
        printf("Date: \n");
        scanf("%d%d%d", &day, &month, &year);
        templ->crucial->date->day = day;
        templ->crucial->date->month = month;
        templ->crucial->date->day = year;
        break;
    }
    case 3:
    {
        printf("Number of seats: \n");
        scanf("%d", &num);
        templ->crucial->places = num;
        break;
    }
    case 4:
    {
        printf("Route:\n");
        scanf("%s", route);
        templ->crucial->route = route;
        break;
    }
    case 5:
    {
        if (templ->secondary == NULL)
        {
            templ = secondary(templ);
        }
        else
        {
            free(templ->secondary);
            templ->secondary = NULL;
            templ->crucial->cost = 99.99;
        }
        break;
    }
    case 6:
    {
        printf("Accomodation \n");
        printf("0 - not include  \n");
        printf("1 - * \n");
        printf("2 - ** \n");
        printf("3 - *** \n");
        printf("4 - **** \n");
        printf("5 - ***** \n");
        scanf("%d", &h_type);
        templ->crucial->cost += h_type * 12;
        switch (h_type)
        {
        case 1:
            addition->housing = "Hotel*\n";
            break;
        case 2:
            addition->housing = "Hotel**\n";
            break;
        case 3:
            addition->housing = "Hotel***\n";
            break;
        case 4:
            addition->housing = "Hotel****\n";
            break;
        case 5:
            addition->housing = "Hotel*****\n";
            break;
        default:
            addition->housing = "Not include\n";
            break;
        }
        break;
    }
    case 7:
    {
        printf("Insurence \n");
        printf("1 - yes \n");
        printf("0 - no \n");
        scanf("%d", &type);
        templ->crucial->cost += 50 * type;
        addition->insurance = (type == 1) ? 1 : 0;
        system("cls");
        break;
    }
    case 8:
    {
        printf("Food \n");
        printf("0 - - \n");
        printf("1 - include \n");
        scanf("%d", &f_type);
        addition->nutrition = (f_type != 0) ? 1 : 0;
        templ->crucial->cost += 25 * type;
        system("cls");
        break;
    }
    default:
        return;
    }
}

void load(List *root)
{
    FILE *file;
    Node *head;
    TourTemplate *templ;
    int i;
    head = root->head;
    file = fopen("templates.txt", "w");

    for (i = 0; head != NULL; i++)
    {
        templ = head->info;
        fprintf(file, "%s", templ->name);
        fprintf(file, " %.2f$\n", templ->crucial->cost);
        fprintf(file, "Number of seats: %d\n", templ->crucial->places);
        fprintf(file, "Date: %d.%d.%d\n", templ->crucial->date->day, templ->crucial->date->month, templ->crucial->date->year);
        fprintf(file, "Route: %s\n", templ->crucial->route);

        if (templ->secondary != NULL)
        {
            fprintf(file,"Hotel: %s", templ->secondary->housing);
            fprintf(file,"Insurance: %d\n", templ->secondary->insurance);
            fprintf(file,"Nutrition: %d\n", templ->secondary->nutrition);
        }
        head = head->next;
    }
    fclose(file); 
}