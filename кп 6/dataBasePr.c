#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "passenger.h"

int main(int argc, char* argv[]){
       if (argc != 3) {
             printf("Incorrect input.Correct input is: /program/ /input_filename/ /output_filename/");
             return 1;
       }
       passenger pas;
       FILE *out = fopen(argv[2], "w");
       if (!out) {
             printf("Can't open the file");
             return 2;
       }
       FILE *in_file = fopen(argv[1], "r");
       while(!feof(in_file)) {
             fscanf(in_file, "%s%s%d%s%s%d%d", pas.surname, pas.initials, &pas.number_of_things, pas.destination, pas.departure_time, &pas.transfers, &pas.number_of_children);
             fwrite(&pas, sizeof(pas), 1, out);
       }
       fclose(in_file);
       fclose(out);
       return 0;
}
