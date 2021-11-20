#include "stack.h"
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
void PushStack (Stack * S, Player P){
    if (IsEmptyStack(*S))
    {
        Top(*S) = 1;
    }
    else
    {
    	Top(*S)++;
    }
    InfoTop(*S) = P;
};
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack (Stack * S, Player* P){
	*P = InfoTop(*S);
    Top(*S)--;
};
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
