//
// Created by hun46 on 2019. 06. 06..
//

#ifndef PASSWORDS_PASSWORDS_H
#define PASSWORDS_PASSWORDS_H

typedef enum {
    ERROR, WEAK, MODERATE, STRONG
}strength_t;

strength_t get_pwd_strength(char *password);
void print_strengtg(strength_t);

#endif //PASSWORDS_PASSWORDS_H
