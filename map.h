#include "mesin_kata.h"
#include "array.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAP_H
#define MAP_H

extern char Map[101];
extern int MaxRoll,N;
extern TabInt Teleporter;

void readConfig ();
//Membaca file konfigurasi
void PrintMap(TabPlayer a , char map[101]);
//Mengeluarkan current position dari player
#endif

