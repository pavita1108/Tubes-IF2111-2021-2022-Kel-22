#include "driverskill.h"
#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int R1, i, inputskill;
    List Skill, Buff;
    address P;
    CreateEmptyList(&Skill);//list skill player
    CreateEmptyList(&Buff);//list buff yg aktif pada seorang player
    
    printf("Skill yang didapatkan pada giliran ini:\n");
    for (int i = 0; i < 10; i ++){
        R1 = RandomizeSkill();
        AddSkill(&Skill, R1);
    }

    if (!IsEmptyList(Skill)){
        printf("\nKamu memiliki skill:\n");
        PrintForwardList(Skill);
        printf("\nKeterangan:\n1 = Pintu Ga Ke Mana-Mana\n2 = Cermin Pengganda\n3 = Senter Pembesar Hoki\n4 = Senter Pengecil Hoki\n5 = Mesin Penukar Hoki\n");
        printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n\n"); 

        // Memasukkan nomor skill yang akan dihapus 
        printf("Masukkan skill: ");
        scanf("%d", &inputskill);  
        if (inputskill != 0){
            DelSkill (&Skill, inputskill);
            if (inputskill > 0){
                P = SearchList(Buff,inputskill);//buff tidak bisa distak, cek dulu apakah sudah ada
                if (P = Nil){//buff belum ada, bisa dimasukkan ke listbuff
                    InsVLastList(&Buff, inputskill);//memasukan buff ke dalam list buff
                }
                    /*jangan lupa saat endturn panggil prosedur DeleteBuff(Buff) untuk membersihkan status buff player*/
            }
        }
    }
}
