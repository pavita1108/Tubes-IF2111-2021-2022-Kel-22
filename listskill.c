#include "boolean.h"
#include "listdp.h"
#include "listskill.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NbElmt (List L){
	address P;
	P = First(L);
	int count;
	count = 1;
	while (P != Nil){
		count ++;
		P = Next(P);
	}
	return count;
}

int RandomizeSkill (){
	int x;
	srand(time(0));
    x = rand() % 10;
    return x;
}

void AddSkill (List *L, int hasil){
	int skill;
	if (hasil == 0){
		skill = 1;
		printf("1. Pintu Ga Ke Mana-Mana\n");
	}
	else if(hasil == 1){
		skill = 2;
		printf("2. Cermin Pengganda\n");
	}
	else if(hasil == 2 || hasil == 3){
		skill = 3;
		printf("3. Senter Pembesar Hoki\n");
	}
	else if(hasil == 4 || hasil == 5){
		skill = 4;
		printf("4. Senter Pengecil Hoki\n");
	}
	else if(hasil == 6){
		skill = 5;
		printf("5. Mesin Penukar Hoki\n");
	}
	else if(hasil >= 7 && hasil <= 9){
		skill = 0;
		printf("Teknologi Gagal\n");
        printf("Maaf Anda mendapatkan Teknologi Gagal\n");
	}

	if (skill != 0 && NbElmt(*L) < 11){
		InsVLastList(L, skill);
		printf("\nSkill berhasil dimasukkan\n");
	}

	else if (NbElmt(*L) >= 11){
		printf("Jumlah skill yang dimiliki sudah 10\n");
	}
}

int CurrentSkill (int inputskill){
/* Menghasilkan skill yang sedang aktif */
	int CurrSkill;
	CurrSkill = inputskill;
	return CurrSkill;
}

void PrintSkill(List L,TabInt *T){
	address P ;
	int i;
	i =1;
	P = First(L);
    do
    {
    	printf("%d. ",i);
        if (Info(P) == 1){
        	puts("Pintu Ga Ke Mana-Mana");
        	(*T).TI[i-1]=1;
		}
		else if (Info(P) == 2){
			puts("Cermin Pengganda");
			(*T).TI[i-1]=2;
		}
		else if (Info(P) == 3){
			puts("Senter Pembesar Hoki");
			(*T).TI[i-1]=3;
		}
		else if (Info(P) == 4){
			puts("Senter Pengecil Hoki");
			(*T).TI[i-1]=4;
		}
		else if (Info(P) == 5){
			puts("Mesin Penukar Hoki");
			(*T).TI[i-1]=5;
		}
        P = Next(P);
        i++;
    } while (P != Nil);
}
