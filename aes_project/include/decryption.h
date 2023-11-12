// decryption.h
#ifndef DECRYPTION_H
#define DECRYPTION_H

#include "structures.h" 

void SubRoundKey(unsigned char *state, unsigned char *roundKey);
void InverseMixColumns(unsigned char *state);
void InitialRound(unsigned char *state, unsigned char *key);
void AESDecrypt(unsigned char *encryptedMessage, unsigned char *expandedKey, unsigned char *decryptedMessage);

#endif // DECRYPTION_H

