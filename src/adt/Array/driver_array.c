/* file driver array.c*/
#include<stdio.h>
#include "array.h"
#include "boolean.h"


void BalikIsiTab (TabInt T) {
/*I.S. Array terdefinisi*/
/*F.S. Menamplkan elemen dari array*/
    IdxType i;
    for (i = T.Neff; i >= IdxMin; i--){
        printf("%d\n", GetElmtArray (T, i));
    }
};

int main() {
    /*Menerima input jumlah array dan elemennya, kemudian membalik elemen array*/
    TabInt T;
    int i, n, elemen;

    MakeEmptyArray(&T);

    printf("Masukkan jumlah elemen : ");
    scanf("%d", &n);
    T.Neff = n;

    for (i = IdxMin; i <= n; i++){
        printf("Masukkan elemen array ke-%d: ", i);
        scanf("%d", &elemen);
        T.TI[i] = elemen;
    }

    printf("Setelah dibalik array menjadi : \n");
    BalikIsiTab(T);

    return 0;
}
