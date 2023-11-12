#ifndef STRUCTURES_H
#define STRUCTURES_H

extern unsigned char s[256];
extern unsigned char mul2[256];
extern unsigned char mul3[256];
extern unsigned char rcon[10];
extern unsigned char inv_s[256];
extern unsigned char mul9[256];
extern unsigned char mul11[256];
extern unsigned char mul13[256];
extern unsigned char mul14[256];
static void SubBytes(unsigned char *state);
static void ShiftRows(unsigned char *state);
static void Round(unsigned char *state, unsigned char *key);
#endif // STRUCTURES_H
