#include "listdp.h"
#include <stdio.h>

int main () {
    List L ;
    CreateEmptyList(&L) ;
    address P ;
    int n, i, X, count, sum ;
    scanf("%d", &n) ;
    count = 0 ;
    sum = 0 ;
    for (i = 0; i < n; i++) {
        scanf("%d", &X) ;
        if (X > 0) {
            if (sum < 10) {
                InsVLastList(&L, X) ;
                sum++ ;
                count = count + X ;
                printf("%d %d\n", sum, count) ;
            }
            else {
                printf("Skill penuh\n") ;
            }
        }
        else {
            P = SearchList(L, X*-1) ;
            if (P == NilList) {
                printf("Tidak ada skill\n") ;
            }
            else {
                DelPList(&L, X*-1) ;
                sum-- ;
                count = count + X ;
                printf("%d %d\n", sum, count) ;
            }
        }
    }
    return 0 ;
}