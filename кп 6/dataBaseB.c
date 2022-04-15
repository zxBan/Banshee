#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "passenger.h"

void print_pas(passenger pas) {
       printf("Name: %s %s; Things: %d; Destination: %s; Dep.time: %s; Transfers: %d; CHildren: %d \n", pas.surname, pas.initials, pas.number_of_things, pas.destination, pas.departure_time, pas.transfer>
}

int main(int argc, char* argv[]) {
       if (argc !=3) {
           printf("Incorrect input.Correct input is: /program/ /key (-f print file, -p solving)/ input filename/");
           return 1;
       }

      FILE *input = fopen(argv[2], "r");
       if (!input) {
          printf("Can't open the file");
          return 2;
       }
       passenger pas;

       if(!strcmp(argv[1], "-f")) {
       printf("|-----------------------------------------------------------------------------------------------|\n");
       printf("|            Name         | Numberthings |     Destination     | Depart.time |transfers|children|\n");
       printf("|-----------------------------------------------------------------------------------------------|\n");
       while(fread(&pas, sizeof(passenger), 1 , input) == 1) {
            printf("|\t%-15s \t%-s|\t%-9d|\t%15s\t|\t%-s|\t%-7d|%5d\t|\n",pas.surname, pas.initials, pas.number_of_things, pas.destination,pas.departure_time, pas.transfers, pas.number_of_children);
       }
       fseek(input, 0, SEEK_SET);
       printf("|-----------------------------------------------------------------------------------------------|\n");
       return 0;
       }

       if (!strcmp(argv[1], "-p")) {
       int sum = 0;
       int count = 0;
       int pv;
       scanf("%d",&pv); 
       float srnumber = 0;
       while(fread(&pas, sizeof(pas), 1 , input) == 1) {
               sum += pas.number_of_things;
               count += 1;
       }
       srnumber = sum / count;
       fseek(input, 0, SEEK_SET);
       int n=0;
       printf("\n the number of passenger items is above average\n");
       while(fread(&pas, sizeof(pas), 1 , input) ==1) {
           if (pas.number_of_things > (srnumber + pv)) {
              n++;
             printf("%d. ", n);
             print_pas(pas);
           }
       }
       return 0;
       }
}
