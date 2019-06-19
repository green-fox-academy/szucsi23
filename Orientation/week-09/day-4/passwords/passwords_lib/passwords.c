//
// Created by hun46 on 2019. 06. 06..
//

#include "passwords.h"
#include <string.h>
#include <stdio.h>

strength_t get_pwd_strength(char *password)
{
    int length = strlen(password);
    if(length > 30 || length < 4) {
        return ERROR;
    }

    int num_num = 0;
    int marks_num = 0;

    for (int i = 0; i < length; ++i) {
        if(password[i] >= 33 && password[i] <= 64) {
            if(password[i] >= 48 && password[i] <= 57) {
                num_num++;
            } else {
                marks_num++;
            }
        }
    }

    if(length >= 10 && num_num >= 4 && marks_num >= 2) {
        return STRONG;
    } else if(length >= 6 && num_num >= 1) {
        return MODERATE;
    } else if(length >= 4) {
        return WEAK;
    }

}

void print_strengtg(strength_t strength)
{
    switch(strength) {
        case ERROR: {
            printf("ERROR ");
            break;
        }
        case WEAK: {
            printf("WEAK ");
            break;
        }
        case MODERATE: {
            printf("MODERATE ");
            break;
        }
        case STRONG: {
            printf("STRONG ");
            break;
        }
    }
}