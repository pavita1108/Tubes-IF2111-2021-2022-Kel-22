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

    if (!IsEmptyList(Skill)){
        while (inputskill != 0 && !IsEmptyList(Skill)){
            printf("\nKamu memiliki skill:\n");
            PrintForwardList(Skill);
            printf("\nKeterangan:\n1 = Pintu Ga Ke Mana-Mana\n2 = Cermin Pengganda\n3 = Senter Pembesar Hoki\n4 = Senter Pengecil Hoki\n5 = Mesin Penukar Hoki\n");
            printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n\n"); 

            /* Memasukkan nomor skill yang akan dihapus */
            printf("Masukkan skill: ");
            scanf("%d", &inputskill);  
            DelSkill (&Skill, inputskill);
        }
    }

    
}