#include <stdio.h>
#include "ticket.h"

typedef struct tickets{
    char passanger_name[50];
    char origin[50];
    char destiny[50];
    int airplane_number;
}Tickets;

typedef struct knot {
    Tickets t;
    struct knot *next;
}Knot;

typedef struct list {
    Knot *start;
    Knot *end;
} List;

