#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
	Top(*S) = NilStack;
};
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
	return Top(S) == NilStack;
};
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack (Stack S){
	return Top(S) == MaxEl;
};
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack (Stack * S, TabPlayer A){
    Top(*S)=Top(*S)+1;
    (*S).P[(*S).TOP] = A;
    int i;
    for (i = 0; i < A.Neff; i++) {
    	
        (*S).P[(*S).TOP].TI[i].Skill.First = NULL ;
        (*S).P[(*S).TOP].TI[i].Skill.Last = NULL ;
        copySkill(A.TI[i].Skill, &((*S).P[(*S).TOP].TI[i].Skill)) ;
    }
    
};
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack (Stack * S, TabPlayer* A){
	*A = (*S).P[Top(*S)];
    Top(*S)=Top(*S)-1;
    
};
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
