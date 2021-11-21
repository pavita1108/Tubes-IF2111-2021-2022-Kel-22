#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "listskill.h"
#include "player.h"

#ifndef UNDO_H
#define UNDO_H

void undo (Stack stackPemain);
/* Menghapus Infotop dari stack jika jumlah elemen stack > 1*/
/* I.S. Stack  tidak mungkin kosong */
/* F.S. TOP berkurang satu */
    
#endif