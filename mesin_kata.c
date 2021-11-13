#include <stdio.h>
#include "mesin_kata.h"

Kata CKata;
void IgnoreBlank(){
    while (((CC == BLANK) || (CC == MARK)) && (!EOP)) {
        ADV();
    }
};

void SalinKata(){
    int i;
    i = 0;
    while ((CC != MARK) && (CC != BLANK) && (i <= NMax) && (!EOP))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    if(CC == MARK || CC == BLANK || EOP){
        CKata.TabKata[i] = '\0';
    }
    CKata.Length = i;
};
         
void STARTKATA(){
    START();
    IgnoreBlank();
    if (CC != MARK) {
        SalinKata();
    }
};

void ADVKATA(){
    IgnoreBlank();
    if (CC != MARK)
    {
        SalinKata();
        IgnoreBlank();
    }
};

