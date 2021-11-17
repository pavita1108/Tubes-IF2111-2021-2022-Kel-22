#ifndef listskill_H
#define listskill_H

#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NbElmt (List *L);

int RandomizeSkill (int x);

void DelI (List *L, int i);

void DelSkill (List *L, int i);

void AddSkill (List *L, int hasil);

#endif
