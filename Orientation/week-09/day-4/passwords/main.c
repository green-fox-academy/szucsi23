#include <stdio.h>
#include "passwords.h"

int main()
{
    print_strengtg(get_pwd_strength("a"));
    printf("\n");
    print_strengtg(get_pwd_strength("almafa"));
    printf("\n");
    print_strengtg(get_pwd_strength("almafa23"));
    printf("\n");
    print_strengtg(get_pwd_strength("almafa23....23almafa"));
}