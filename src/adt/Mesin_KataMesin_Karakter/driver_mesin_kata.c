#include <stdio.h>
#include "mesin_kata.h"
#include "mesin_kata.c"

//membaca file konfigurasi
int main() {
    STARTKATA();
    while (!EOP) {
        for (int i=0;i<CKata.Length;i++) {
            printf("%c",CKata.TabKata[i]);
            }
        printf("\n");
        ADVKATA();
    }
return 0;
}