#include "../../boolean.h"
#include "array.h"
#include <stdio.h>

void MakeEmptyArray (TabInt *T){
	(*T).Neff = 0;
};


/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (TabInt T){
	return ((T).Neff);
};

int MaxNbElArray (TabInt T){
	return (IdxMax - IdxMin + 1);
};

/* *** Selektor INDEKS *** */
IdxType GetFirstIdxArray (TabInt T){
	return (IdxMin);
};

IdxType GetLastIdxArray (TabInt T){
	return ((T).Neff);
};

ElType GetElmtArray (TabInt T, IdxType i){
	return ((T).TI[(i)]);
};


/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTabArray (TabInt Tin, TabInt *Tout){
	*Tout = Tin;
};

void SetElArray (TabInt *T, IdxType i, ElType v){
	(*T).TI[(i)] = v ;
};

void SetNeffArray (TabInt *T, IdxType N){
	(*T).Neff = N;
};


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArray (TabInt T, IdxType i){
	return ((i >= IdxMin) && (i <= IdxMax));
};

boolean IsIdxEffArray (TabInt T, IdxType i){
	return ((i >= GetFirstIdxArray(T)) && (i <= GetLastIdxArray(T)));
};

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (TabInt T){
	return (NbElmtArray(T) == 0);
};

boolean IsFullArray (TabInt T){
	return (NbElmtArray(T) == (IdxMax - IdxMin + 1));
};


