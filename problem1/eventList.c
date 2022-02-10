#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    /*
    Event *event = malloc(sizeof(Event));
    name[15] = 0;
    sscanf(name, "%s", event->eventName);
    event->next = NULL;

    return event;
    */
    EventList *evenlist = malloc(sizeof(evenlist));
    return evenlist;
}

void DestroyEventList(EventList *this)
{

    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *a = this->head;
    if (this->isEmpty == 0)
    {
        return NULL;
    }
    // primero remover el último
    else
    {

        while (a != NULL)
        {
            if (*(a->eventName + 2) == *(name + 2) && *(a->eventName + 3) == *(name + 3))
            {
                return a;
            }

            a = a->next;
        }
    }

    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    Event *r = this->head;
    if (this->isEmpty != 0)
    {
        while (r != NULL)
        {
            if (*(r->eventName + 2) == *(event->eventName + 2) && *(r->eventName + 3) == *(event->eventName + 3))
                return;

            r = r->next;
        }
        this->last->next = event;
        this->last = event;
    }
    else
    {
        this->head = event;
        this->last = event;
        this->isEmpty = 1;
    }
}

void RemoveEvent(EventList *this, char *name)
{
     Event *a = this->head;
    if (this->isEmpty == 0)
    {
        return;
    }
    // primero remover el último
    else
    {
       
        while (a != NULL)
        {
            if (*(this->head->eventName + 2) == *(name + 2))
            {
                this->head = this->head->next;
                break;
            }

            else if (*(a->next->eventName + 2) == *(name + 2))
            {
                a->next = a->next->next;

                break;
            }

            a = a->next;
        }
        if (this->head==NULL)
        {
            this->isEmpty = 0;
        }
    }
}

void ListEvents(EventList *this)
{
    Event *a = this->head;
    // imprime esto si la lista está vacía
    if (this->isEmpty == 0)
        printf("empty\n");
    else
    {
        while (a != NULL)
        {
            printf("%s\n", a->eventName); // BORRAR OJO
            a = a->next;
        }
    }
}
