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
    x = rand() % 10;
    result = (result + x) % 10;
    return result;
}

void DelSkill (List *L, int i){
	int DelNum;
    i = abs(i);
	if (SearchList(*L,i)){
		DelPList(L, i);
		if (i == 2){ // biar mastiin skill 2 emang udah ada walaupun udah diapus
			CerminGanda(L);
		}
	}
	else{
		printf("\nAnda tidak memiliki skill tersebut");
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
		printf("Skill berhasil dimasukkan\n");
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

void CerminGanda (List *L){
	if (NbElmt(L) <= 9){
		printf("\nAnda mendapatkan skill:\n");
		AddSkill(L, RandomizeSkill());
		printf("\n");
		AddSkill(L, RandomizeSkill());
		printf("\nKamu memiliki skill:\n");
		PrintForwardList(*L);
		printf("\nKeterangan:\n1 = Pintu Ga Ke Mana-Mana\n2 = Cermin Pengganda\n3 = Senter Pembesar Hoki\n4 = Senter Pengecil Hoki\n5 = Mesin Penukar Hoki\n");
	}
	else{
		printf("\nUntuk menggunakan skill 2, Anda harus memiliki skill kurang dari 10");
	}
}