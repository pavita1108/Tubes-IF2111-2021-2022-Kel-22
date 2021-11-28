/*File driver ADT stack*/
#include "stack.h"
#include "player.h"
#include "listdp.h"
#include <stdio.h>
#include <string.h>

void MakeTabSinglePlayer (TabPlayer *TPlayer){
	printf("Masukkan nama player : ");
	MakePlayer(&((*TPlayer).TI[1]));
};
 
boolean IsValidCommand (int x) {
    return((x == 1) || (x == 2) || (x == 3));
};



int main() {
    /*Asumsi pemain tidak melakukan move ke tempat yang sama secara berturut-turut*/

    Stack S, StackforCopy;
    TabPlayer TP;
    Player P;
    int tujuan, ans, command;

    printf("Selamat Datang di Pintu Hitam Legam!!\n");
    printf("Lokasi dengan koordinat 0 menandakan kamu berada di HOME\n");
    printf("Terdapat 3 perintah yang dapat dijalankan yaitu : \n");
    printf("1. MOVE (berpindah lokasi dan menambahkan ke histori lokasi serta menampilkan lokasi saat ini)\n");
    printf("2. BACK (berpindah ke lokasi sebelumnya dan menghapus loakasi terakhir dari histori)\n");
    printf("3. EXIT (Keluar dari Pintu Hitam Legam dan menampilkan lokasi teratas di histori)\n");

    MakeTabSinglePlayer(&TP);

    CreateEmptyStack(&S);
    /*Posisi awal 0*/
    PushStack(&S, TP);
    printf("Posisi awal kamu saat ini adalah ");
    printf("%d\n", InfoTop(S).TI[1].CPosition);

    int round = 1;
    do {
       do{
            printf("1. MOVE\n");
            printf("2. BACK\n");
            printf("3. EXIT\n");

            printf("Masukkan command : ");
            scanf("%d", &command);
       } while (!(IsValidCommand(command)));

        if (command == 1){
            printf("Berikut adalah tempat tujuan yang tersedia saat ini !!\n");

            printf("1. Bank Negara\n");
            printf("2. Geumga Plaza\n");
            printf("3. Land of Down\n");
            printf("4. Rumah Tata\n");
            printf("5. Rumah Roni\n");
            printf("Rute terpilih : ");
            scanf("%d", &tujuan);
            if ((tujuan >= 1) && (tujuan <= 5)) {
                TP.TI[1].CPosition = tujuan;
                PushStack(&S, TP);                  /*Menambah lokasi baru ke Stack*/
                printf("Lokasi saat ini : ");
                printf("%d\n", InfoTop(S).TI[1].CPosition);
                if (tujuan == 1){
                    printf("Selamat ! Kamu telah sampai di Bank Negara\n");
                }
                else if (tujuan == 2){
                    printf("Selamat ! Kamu telah sampai di Geumga Plaza\n");
                }
                else if (tujuan == 3){
                    printf("Selamat ! Kamu telah sampai di Land of Down\n");
                }
                else if (tujuan == 4){
                    printf("Selamat ! Kamu telah sampai di Rumah Tata\n");
                }
                else if (tujuan == 5){
                    printf("Selamat ! Kamu telah sampai di Rumah Roni\n");
                }
            }
            else {
                printf("Tujuan tidak valid !\n");
            }
        }

        else if (command == 2){
            PopStack(&S, &TP);          /*Menghapus lokasi terakhir dikunjungi dari Stack*/
            if (IsEmptyStack(S)) {      /*Jika stack kosong akan kembal ke posisi awal = 0*/
                ResetPlayer(&(TP.TI[1]));
                PushStack(&S, TP);
			}
            printf("Lokasi saat ini : ");
            printf("%d\n",InfoTop(S).TI[1].CPosition);
		} 

    }while(command != 3);

    printf("Lokasi terakhir : ");
    printf("%d\n",InfoTop(S).TI[1].CPosition);   /*Menampilkan lokasi terakhir (InfoTop) dari Stack*/

    return 0;
}