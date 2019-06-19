//
// Created by hun46 on 2019. 06. 06..
//

#include "bus.h"
#include <stdio.h>
#include <stdlib.h>

void read_from_file(char *filename)
{
    FILE *myFile = fopen(filename, "r");
    char buffer[30];
    while (buffer = getline()) {
    getline();
    }
    fclose(myFile);
}

