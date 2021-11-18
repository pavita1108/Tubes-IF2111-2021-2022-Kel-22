#ifndef listskill_H
#define listskill_H

#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NbElmt (List *L);
/* Menghitung penjang list */

int RandomizeSkill ();
/* Menghasilkan angka yang akan dipakai di procedure AddSkill */

void DelSkill (List *L, int i);
/* Menghapus skill yang diinput user baik untuk membuang dan menggunakan */

void AddSkill (List *L, int hasil);
/* Mengeluarkan nama skill dengan menggunakan angka dari fungsi RandomizeSkill
dan memasukkannya ke list skill jika banyak elemen di list skill masih kurang atau sama dengan 10 */

int CurrentSkill (int inputskill);
/* Mereturn skill yang sedang aktif */

#endif
