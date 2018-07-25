//
// Created by ZHUWX on 2018/1/29.
//

#ifndef EAT_HAND_H
#define EAT_HAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BURSIZE 2048

int hex2dec(char c);

void urldecode(char url[]);

int Wanzhou (char poststr[]);

int Kaorou (char poststr[]);

int Tujia  (char poststr[]);

int Yipin (char poststr[]);

int Smnoodles(char poststr[]);

int Hundun(char poststr[]);

int Yangrou(char poststr[]);

int Egg(char poststr[]);

int English(char poststr[]);

char zhi[3];

#endif //EAT_HAND_H
