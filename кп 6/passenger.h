ifndef _passender_h_
#define _passenger_h_
#include <stdio.h>
#include <string.h>

typedef struct {
        char surname [40];
        char initials[8];
        int  number_of_things;
        char destination [50];
        char departure_time [5];
        int transfers;
        int number_of_children;
} passenger;
#endif