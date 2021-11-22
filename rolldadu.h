#ifndef rolldadu_H
#define rolldadu_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "player.h"
#include "map.h"

int RollDaduNormal();
//Menghasilkan angka dadu normal, yaitu dari 1~MaxRoll
int RollDaduKecil();
//Menghasilkan angka dadu dari 1~floor(MaxRoll/2) akibat terkena buff Sinar Pengecil Hoki
int RollDaduBesar();
////Menghasilkan angka dadu dari floor(MaxRoll/2)~MaxRoll akibat terkena buff Sinar Pembesar Hoki
int Roll(Player P);
//mengocok dadu sesuai kondisi player(buff)
void Move(Player *P, int hasil);
#endif
