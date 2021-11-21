#include <stdio.h>
#include <stdlib.h>
#include <rolldadu.h>
#include <time.h>
#include <player.h>
#include <map.h>

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

void Roll(Player P){
//KAMUS LOKAL
    address Q;
    int a; //angka dadu yg keluar
//ALGORITMA
    Q = SearchList(P.Buff,3); //cek buff sinar pembesar hoki
    if (Q != Nil){
        a = RollDaduBesar();
    }
    else{//buff  sinar pembesar hoki tidak ditemukan
        Q = SearchList(P.Buff,4); //cek buff sinar pengecil hoki
        if (Q != Nil){
            a = RollDaduKecil();}
        else{//gapunya buff sinar pengecil hoki juga, roll dadu normal
            a = RollDaduNormal(); 
        }
    }
    printf("Anda mendapatkan angka:%d", a);
    //Checking map (belum selesai)
    /*if (a petak di depan dan di belakang adalah petak terlarang){
        printf("Borak tidak dapat bergerak");
    }
    else if (a petak di depan tidak terlarang tapi a petak belakang terlarang){
        printf("Anda dapat maju %d", a,"langkah");
    ()
*/
}
//Test Angka Dadu//
/*
void main() {
    printf("%d ", RollDaduNormal());
}
*/



