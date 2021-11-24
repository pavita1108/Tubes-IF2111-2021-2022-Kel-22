#include <stdio.h>
#include <stdlib.h>
#include "rolldadu.h"
#include <time.h>
#include <math.h>
#include "player.h"
#include "map.h"

int RollDaduNormal() {
    int n;
    srand(time(NULL)); //menggunakan initial time untuk menentukan angka dadu
    n = (rand() % MaxRoll)+ 1; //modulo maxroll agar hasil berada di range dadu, +1 agar tidak menghasilkan angka 0
    return n;
    //range [1 to MaxRoll]
}

int RollDaduKecil() {//digunakan saat player memiliki buff Senter Pengecil Hoki
    int n;
    int a = floor(MaxRoll/2);
    srand(time(NULL));
    n = (rand() % a)+ 1;
    return n;
    //range [1 to floor(MaxRoll/2)]
}

int RollDaduBesar() {//digunakan saat player memiliki buff Senter Pembesar Hoki
    int n;
    int a= floor(MaxRoll/2);
    srand(time(NULL)); 
    n = (rand() % (MaxRoll+1-a) )+ a; 
    return n;
    //range [floor(MaxRoll/2) to MaxRoll]
}

int Roll(Player P){
	if (P.doneRoll==false){
	    int a; 
	    if (P.Pembesar == true){
	        a = RollDaduBesar();
	    }
	    else if (P.Pengecil == true){
	        a = RollDaduKecil();
	    }
	    else{
	    	a = RollDaduNormal();
		}
		printf("%s",P.Nama);
	    printf(" mendapatkan angka %d\n", a);
	    return a;
	}
}

void Move(Player *P, int hasil){
	int tambah,kurang;
	boolean gerak;
	gerak = false;
	if ((*P).doneRoll==false){
		tambah = (*P).CPosition + hasil;
		kurang = (*P).CPosition - hasil;
		
		if(Map[tambah] == '.' && Map[kurang] == '.'&& kurang > 0 && tambah <= N){
			gerak = true;
			int jwb;
			printf("%s",(*P).Nama);
    		puts(" dapat maju mundur.");
    		printf("Ke mana %s mau bergerak:\n",(*P).Nama);
    		printf("1. %d\n", kurang);
    		printf("2. %d\n", tambah);
    		printf("Masukkan pilihan : ");
    		scanf("%d",&jwb);
    		
			while (jwb != 1 && jwb != 2){
				puts("Pilihan salah masukkan lagi");
				printf("Masukkan pilihan : ");
    			scanf("%d",jwb);
			};
			
			if(jwb == 1){
				(*P).CPosition = kurang;
				printf("%s",(*P).Nama);
				printf(" mundur %d langkah.\n",hasil);
				printf("%s",(*P).Nama);
				printf(" berada di petak %d.\n",kurang);
			}
			else{//jwb == 2
				(*P).CPosition = tambah;
				printf("%s",(*P).Nama);
				printf(" maju %d langkah.\n",hasil);
				printf("%s",(*P).Nama);
				printf(" berada di petak %d.\n",((*P).CPosition)+1);
			}
		}
		else if(Map[tambah] == '.' && tambah <= N){
			gerak = true;
			(*P).CPosition = tambah;
			printf("%s",(*P).Nama);
			printf(" maju %d langkah.\n",hasil);
			printf("%s",(*P).Nama);
			printf(" berada di petak %d.\n",((*P).CPosition)+1);
		}
		else if (Map[kurang] == '.'&& kurang > 0 ){
			gerak = true;
			(*P).CPosition = kurang;
			printf("%s",(*P).Nama);
			printf(" mundur %d langkah.\n",hasil);
			printf("%s",(*P).Nama);
			printf(" berada di petak %d.\n",((*P).CPosition)+1);
		}
		else{
			printf("%s",(*P).Nama);
			puts(" tidak dapat bergerak.\n");
		}
		
		if(gerak){
			boolean found;
			int tujuan,i;
			i = 1;
			found = false;
			while (found == false && i<((Teleporter.Neff)/2)+1){
				if (Teleporter.TI[i*2-1]== ((*P).CPosition)+1){
					printf("Petak %d memiliki teleporter menuju %d.\n",((*P).CPosition)+1,Teleporter.TI[i*2]);
					tujuan = Teleporter.TI[i*2];
					found=true;
				}
				i++;
			};
			
			if (found == false){
				printf("%s",(*P).Nama);
				puts(" tidak menemukan teleporter.");
			}
			else{
				printf("%s",(*P).Nama);
				printf(" menemukan teleporter.\n");
				if((*P).Imun){
					char a;
					printf("%s",(*P).Nama);
					puts(" memiliki imunitas teleport.");
					scanf("%c",&a);
					while (a != 'Y' && a != 'N'){
						printf("Jawaban tidak valid.\n");
						printf("Apakah ingin teleport (Y/N)?");
						scanf("%c",&a);
						if ( a == 'Y' || a == 'N'){
							break;
						}
					}
					
					if (a == 'Y'){
						(*P).CPosition = tujuan -1;
						printf("%s",(*P).Nama);
						printf(" teleport ke petak %d.\n", tujuan);
					}
					else{
						printf("%s",(*P).Nama);
						puts(" tidak teleport.") ;
                        (*P).Imun = false ;
                        puts("Buff imunitas teleport hilang.") ;
					}
				}
				else{
					(*P).CPosition = tujuan -1;
					printf("%s",(*P).Nama);
					printf(" tidak memiliki imun.\n");
					printf("%s",(*P).Nama);
					printf(" teleport ke petak %d.\n", tujuan);
				}
			}
		}
		(*P).doneRoll = true;
	}
	else{
		puts("Kamu udh ngeroll.");
	}
	
}


