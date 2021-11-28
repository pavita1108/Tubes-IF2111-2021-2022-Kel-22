#include "../../boolean.h"
#include "../Listdp/listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L){
	return (First(L) == NilList && Last(L) == NilList);
};
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L){
	First(*L) = NilList;
    Last(*L) = NilList;
};
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address AlokasiList (infotype X){
	ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != NilList)
    {
        Info(P) = X;
        Next(P) = NilList;
        Prev(P) = NilList;
        return P;
    }
    else
    {
        return NilList;
    }
};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiList (address P){
	free(P);
};
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchList (List L, infotype X){
	address P;
	P = First(L);
    if (!IsEmptyList(L))
        while (((P) != NilList) && (Info(P) != X))
        {
            P = Next(P);
        }
    return P;
};
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, infotype X){
	address P;
	P = AlokasiList(X);
    if (P != NilList)
        InsertFirstList(L, P);
};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastList (List *L, infotype X){
	address P;
	P = AlokasiList(X);
    if (P != NilList)
        InsertLastList(L, P);
};
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, infotype *X){
	address P;
    DelFirstList(L, &P);
    *X = Info(P);
    DealokasiList(P);
};
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastList (List *L, infotype *X){
	address P;
    DelLastList(L, &P);
    *X = Info(P);
    DealokasiList(P);
};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, address P){
	if (IsEmptyList(*L))
    {
        First(*L) = P;
        Last(*L) = P;
        Next(P) = NilList;
        Prev(P) = NilList;
    }
    else
        InsertBeforeList(L, P, First(*L));
};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastList (List *L, address P){
	if (IsEmptyList(*L))
    {
        Next(P) = NilList;
        Prev(P) = NilList;
        First(*L) = P;
        Last(*L) = P;
    }
    else
        InsertAfterList(L, P, Last(*L));
};
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterList (List *L, address P, address Prec){
	Next(P) = Next(Prec);

    if (Next(Prec) != NilList)
    {
        Prev(Next(Prec)) = P;
    }
    else
    {
        Last(*L) = P;
    }

    Next(Prec) = P;
    Prev(P) = Prec;
};
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeList (List *L, address P, address Succ){
	Prev(P) = Prev(Succ);

    if (Prev(Succ) != NilList)
    {
        Next(Prev(Succ)) = P;
    }
    else
    {
        First(*L) = P;
    }

    Prev(Succ) = P;
    Next(P) = Succ;
};
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, address *P){
	*P = First(*L);
    First(*L) = Next(First(*L));
    if (First(*L) == NilList)
    {
        CreateEmptyList(L);
    }
    else
    {
        Prev(First(*L)) = NilList;
    }
};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastList (List *L, address *P){
	*P = Last(*L);
    Last(*L) = Prev(Last(*L));
    if (Last(*L) == NilList)
    {
        CreateEmptyList(L);
    }
    else
    {
        Next(Last(*L)) = NilList;
    }
};
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPList (List *L, infotype X) {
    address P ;
	P = SearchList(*L, X) ;
    if (P != NilList) {
        if (P == First(*L)) {
            DelFirstList(L, &P) ;
        }
        else if (P == Last(*L)) {
            DelLastList(L, &P) ;
        }
        else {
            Next(Prev(P)) = Next(P) ;
            Prev(Next(P)) = Prev(P) ;
        }
        DealokasiList(P) ;
    }
};
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfterList (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);

    Next(Prec) = Next(*Pdel);
    if (Next(*Pdel) != NilList)
    {
        Prev(Next(*Pdel)) = Prec;
    }
    else
    {
        Last(*L) = Prec;
    }

    Next(*Pdel) = NilList;
    Prev(*Pdel) = NilList;
};
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeList (List *L, address *Pdel, address Succ){
	*Pdel = Prev(Succ);

    Prev(Succ) = Prev(*Pdel);
    if (Prev(*Pdel) != NilList)
    {
        Next(Prev(*Pdel)) = Succ;
    }
    else
    {
        First(*L) = Succ;
    }

    Next(*Pdel) = NilList;
    Prev(*Pdel) = NilList;
};
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForwardList (List L){
	printf("[");
    if (!IsEmptyList(L))
    {
        address P ;
		P = First(L);
        do
        {
            printf("%d", Info(P));
            P = Next(P);
            if (P != NilList)
                printf(",");
        } while (P != NilList);
    }
    printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackwardList (List L){
	printf("[");
    if (!IsEmptyList(L))
    {
        address P ;
		P = Last(L);
        do
        {
            printf("%d", Info(P));
            P = Prev(P);
            if (P != NilList)
                printf(",");
        } while (P != NilList);
    }
    printf("]");
};
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
