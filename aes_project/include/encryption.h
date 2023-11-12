// encryption.h
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

void AddRoundKey(unsigned char *state, unsigned char *roundKey);


void MixColumns(unsigned char *state);

void FinalRound(unsigned char *state, unsigned char *key);
void AESEncrypt(unsigned char *message, unsigned char *expandedKey, unsigned char *encryptedMessage);
void KeyExpansion(unsigned char inputKey[16], unsigned char expandedKeys[176]);
void KeyExpansionCore(unsigned char * in, unsigned char i) ;

#endif // ENCRYPTION_H

