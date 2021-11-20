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

//Test Driver//
/*
void main() {
    printf("%d ", RollDaduNormal());
}
*/



