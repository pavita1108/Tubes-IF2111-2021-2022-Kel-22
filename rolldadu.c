#include <stdio.h>
#include <stdlib.h>
int rolldadu() {
    int i, n;
    srand(time(NULL)); //menggunakan initial time untuk menentukan angka dadu
    n = (rand() % 6)+ 1; //modulo 6 agar hasil berada di range dadu, +1 agar tidak menghasilkan angka 0
    return n;
}

//Test Driver//
/*
void main() {
    printf("%d ", rolldadu());
}
*/



