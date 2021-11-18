#include "boolean.h"
#include "listdp.h"
#include "listskill.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NbElmt (List *L){
	address P;
	P = First(*L);
	int count;
	count = 1;
	while (P != Nil){
		count ++;
		P = Next(P);
	}
	return count;
}

int RandomizeSkill (){
	int result, skill, x, i;
	srand((unsigned) (time(0)));
    for(i = 1; i < 10; i++){
        x = rand() % 10;
    }
    result = (result + x) % 10;
    return result;
}

void DelSkill (List *L, int i){
    if (i != 0 ){
        if (i < 0){
            int DelNum;
            i = abs(i);
            DelPList(L, i);
            printf("Membuang skill %d", i);
        }
        else{
			DelPList(L, i);
            printf("Menggunakan skill %d", i);
        }
    }
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

	if (skill != 0 && NbElmt(L) < 11){
		InsVLastList(L, skill);
		printf("\nSkill berhasil dimasukkan\n");
	}

	else if (NbElmt(L) >= 11){
		printf("Jumlah skill yang dimiliki sudah 10\n");
	}
}

int CurrentSkill (int inputskill){
/* Menghasilkan skill yang sedang aktif */
	int CurrSkill;
	CurrSkill = inputskill;
	return CurrSkill;
}