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
	count = 0;
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

void DelI (List *L, int i){
	address P;
	int j = 0;
	P = First(*L);
	if (i == 0){
		DelFirstList(L, &P);
	}
	else if (i == NbElmt(L)){
		DelLastList(L, &(Last(*L)));
	}
	else{
		while (j < i){
			j ++;
			P = Next(P);
		}
		P = Prev(P);
		DelAfterList(L, &P, Prev(P));
	}
}

void DelSkill (List *L, int i){
	if (IsEmptyList(*L)){
		printf("Anda tidak mempunyai skill\n");
	}
	else{
		i = abs(i);
		DelI(L, i);
	}
}

void AddSkill (List *L, int hasil){
	int skill;
	if (hasil == 0){
		skill = 0;
		printf("Pintu Ga Ke Mana-Mana\n");
	}
	else if(hasil == 1){
		skill = 1;
		printf("Cermin Pengganda\n");
	}
	else if(hasil == 2 || hasil == 3){
		skill = 2;
		printf("Senter Pembesar Hoki\n");
	}
	else if(hasil == 4 || hasil == 5){
		skill = 3;
		printf("Senter Pengecil Hoki\n");
	}
	else if(hasil == 6){
		skill = 4;
		printf("Mesin Penukar Hoki\n");
	}
	else if(hasil >= 7 && hasil <= 9){
		skill = 5;
		printf("Teknologi Gagal\n");
        printf("Maaf Anda mendapatkan Teknologi Gagal\n");
	}

	if (skill != 5 && NbElmt(L) < 10){
		InsVLastList(L, skill);
		printf("Skill ");
		printf("%d", skill);
		printf(" berhasil dimasukkan\n");
	}
	else if (NbElmt(L) >= 10){
		printf("Jumlah skill yang dimiliki sudah 10\n");
	}
}
