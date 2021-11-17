#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>

/*    printf("Kamu memiliki skill:\n");
    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill"); */

int main(){
    int R1, i, inputskill;
    List Skill;
    CreateEmptyList(&Skill);
    
    printf("Skill yang didapatkan pada giliran ini:\n");
    R1 = RandomizeSkill();
    AddSkill(&Skill, R1);

    printf("\nKamu memiliki skill:\n");
    PrintForwardList(Skill);
    printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n\n"); 

    /* Memasukkan nomor skill yang akan dihapus */
    printf("Masukkan skill: ");
    scanf("%d", &inputskill);  
         
    while (inputskill != 0){ 
        DelSkill (&Skill, inputskill);

        printf("\nKamu memiliki skill:\n");
        PrintForwardList(Skill);
        printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n\n");
    
        printf("Masukkan skill: ");
        scanf("%d", &inputskill); 
    }
}