#include <stdio.h>
#include <stdlib.h>
#include "../Listskill/listskill.h"
#include "impskill.h"
#include "../Array/array.h"
#include "../Player/player.h"
#include "../Map/map.h"

void Skill(Player *P, TabPlayer *TPlayer){
	if (!IsEmptyList((*P).Skill)){
		TabInt t;
		MakeEmptyArray(&t);
        printf("\nKamu memiliki skill:\n");
        PrintSkill((*P).Skill,&t);
        
        printf("\nTekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n\n"); 

        // Memasukkan nomor skill yang akan dihapus 
        int i,inputskill,a;
        printf("Masukkan skill: ");
        scanf("%d", &inputskill);  
        
        if (inputskill != 0){
			a = abs(inputskill);
			i = t.TI[a-1];
			if (SearchList((*P).Skill,i)){
				DelPList(&((*P).Skill), i);
				if(inputskill < 0 ){
					puts("Skill berhasil dibuang");
				}
				else if (i == 1){
					(*P).Imun = true;
					puts("Pintu Ga Ke Mana-Mana berhasil dipakai");
				}
				else if (i == 2){
					if ((*P).Pengganda == false){
						(*P).Pengganda = true;
						if (NbElmt((*P).Skill)<= 9){
							int a;
							printf("\nAnda mendapatkan skill:\n");
							a = RandomizeSkill();
							AddSkill(&((*P).Skill),a);
							a = RandomizeSkill();
							AddSkill(&((*P).Skill),a);
							puts("Cermin Pengganda berhasil dipakai");
						}
						else{
							printf("\nUntuk menggunakan skill 2, Anda harus memiliki skill kurang dari 10\n");
						}
						
					}
					else{
						puts("Udah pernah make Cermin Pengganda");
						InsVLastList (&((*P).Skill), i);
					}
					
				}
				else if (i == 3){
					if ((*P).Pengecil == false){
						(*P).Pembesar = true;
						puts("Senter Pembesar Hoki berhasil dipakai");
					}
					else{
						puts("Masih ada buff senter pengecil");
						InsVLastList (&((*P).Skill), i);
					}
				}
				else if (i == 4){
					if ((*P).Pembesar == false){
						(*P).Pengecil = true;
						puts("Senter Pengecil Hoki berhasil dipakai");
					}
					else{
						puts("Masih ada buff senter pembesar");
						InsVLastList (&((*P).Skill), i);
					}
				}
				else if (i == 5){
					//KAMUS
					int input, anda, temp,i;
				    //ALGORITMA
				    printf("Daftar pemain:\n");
				    for (i=0; i<(*TPlayer).Neff; i++){
				        if (strcmp((*TPlayer).TI[i].Nama,(*P).Nama) == 0 ){
				            anda = i;
				        }
				        else{
				            printf("%d. %s\n", i+1 ,(*TPlayer).TI[i].Nama); 
				        }
				    }
				    printf("Map sekarang:\n");
				    PrintMap(*TPlayer, Map);
				
				    printf("Masukan nomor player yang ingin kamu tukar : ");
				    scanf("%d",&input); 
				    while ((input-1) == anda){//validasi input
				        printf("Tidak bisa menukar posisi dengan diri sendiri!\n");
				        printf("Masukan nomor player yang ingin kamu tukar:");
				        scanf("%d",&input);
				    }
				    //tukar posisi
				    temp = (*TPlayer).TI[input-1].CPosition;
				    (*TPlayer).TI[input-1].CPosition =  (*TPlayer).TI[anda].CPosition;
				    (*TPlayer).TI[anda].CPosition =temp;
				    puts("Mesin Penukar Hoki berhasil dipakai");
				}
			}
			else{
				printf("\nAnda tidak memiliki skill tersebut\n");
			}
        }
    }
}



