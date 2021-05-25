#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "santaren.h"

void creatingTrips(List **root, int pos)
{
  Node *head;
  char str[128];
  char *name, *tab;
  int proof, index, i;
  tab = "\n";
  head = (*root)->head;
  while (head->position != pos)
  {
    head = head->next;
  }

  Trip *templateTrip = (Trip *)malloc(sizeof(Trip));
  head->trip = templateTrip;
  head->trip->occupied = index = 0;

  printf("Passangers name:\n");
  getchar();
  gets(str);
  (head->trip->passengers) = (char*)malloc(strlen(str)*sizeof(char));
  strcpy(head->trip->passengers,str);
  strcat(head->trip->passengers,tab);
  head->trip->len = strlen(str);
  head->trip->occupied++;
}

float tripsList(List **root)
{
  Node *head;
  int i, pos, proof, newlen, empty;
  char str[128];
  char *name, *tab;
  char* passlist;
  float coeff;
  head = (*root)->head;

  empty = 0;
  for (i = 0; head != NULL; i++)
  {
    head->position = i;
    if (head->trip != NULL)
    {
      printf("%d. %s", head->position, head->info->name);
      empty++;
    head = head->next;
    }
  }
  
  if(empty == 0)
  {
    printf("No active tours available\n");
    return 0;
  }
  scanf("%d", &pos);
  head = (*root)->head;
  while (head->position != pos)
  {
    head = head->next;
  }

  printf("0 - Add\n");
  printf("1 - Formating\n");
  printf("2 - List of passangers\n");
  scanf("%d", &pos);

  switch (pos)
  {
  case 0:
  {
    if (head->trip->occupied != head->info->crucial->places)
    {
      printf("Passangers name:\n");
      getchar();
      gets(str);
      tab  = "\n";
      name = (char *)malloc(head->trip->len * sizeof(char));
      strcpy(name, head->trip->passengers);

      free(head->trip->passengers);
      newlen = head->trip->len+strlen(str)+1;
      head->trip->passengers = (char *)malloc(newlen * sizeof(char));
      strcpy(head->trip->passengers,name);
      strcat(head->trip->passengers, str);
      strcat(head->trip->passengers, tab);

      head->trip->len = newlen;
      head->trip->occupied++;
      break;
    }
    else
    printf("Trip is full\n");
    break;
  }
  case 1:
  {
    
    coeff = (float)head->trip->occupied/(float)head->info->crucial->places*(float)head->trip->occupied*(float)head->info->crucial->cost;
    free(head->trip);
    head->trip= NULL;
    return coeff;
    break;
  }
  case 2:
  {
    templateInfo(head->info);
    printf("Passangers list:\n");
    printf("%d/%d\n", head->trip->occupied,head->info->crucial->places);
    printf("%s\n", head->trip->passengers);
    
    break;
  }
  default:
    return 0;
    break;
  }
  return 0;
}

#ifndef TESTING
int main()
{
  List *cr;
  TourTemplate *templ, *sec, *s, *custom;
  char move[12];
  float netProfit;
  float d = 299.99;
  int exit, type;
  cr = NULL;

  exit = 0;
  readfile(&cr);

  while (!exit)
  {
    printf("Default - Exit\n");
    printf("1 - Show templates\n");
    printf("2 - Create custom template\n");
    printf("3 - Change template\n");
    printf("4 - Forming a trip\n");
    printf("5 - Trips list\n");
    printf("6 - Profit check\n");
    printf("7 - Load templates\n");
    

    scanf("%s", move);
    switch (move[0])
    {
    case '1':
      show(cr);
      break;
    case '2':
    {
      custom = createCustom();
      add(&cr, custom);
      break;
    }
    case '3':
    {
      preview(cr);
      scanf("%d", &type);
      system("cls");
      change(&cr, type);
      break;
    }
    case '4':
    {
      preview(cr);
      scanf("%d", &type);
      system("cls");
      creatingTrips(&cr, type);
      break;
    }
    case '5':
    {
      netProfit += tripsList(&cr);
      break;
    }
    case '6':
    {
      printf("Profit: %.2f\n",netProfit);
      break;
    }
    case '7':
    {
      load(cr);
      break;
    }

    default:
      exit = 1;
      break;
    }
  }
  return 0;
}
#endif