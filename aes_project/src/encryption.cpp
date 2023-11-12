// encryption.cpp
#include "encryption.h"
#include "structures.h"
#include<bits/stdc++.h>
using namespace std;

void AddRoundKey(unsigned char *state, unsigned char *roundKey) {
    for (int i = 0; i < 16; i++) {
        state[i] ^= roundKey[i];
    }
}


static void SubBytes(unsigned char *state) {
    for (int i = 0; i < 16; i++) {
        state[i] = s[state[i]];
    }
}

static void ShiftRows(unsigned char *state) {
    unsigned char tmp[16];


    tmp[0] = state[0];
    tmp[1] = state[5];
    tmp[2] = state[10];
    tmp[3] = state[15];


    for (int i = 0; i < 16; i++) {
        state[i] = tmp[i];
    }
}




void MixColumns(unsigned char *state) {
    unsigned char tmp[16];


    for (int i = 0; i < 16; i++) {
        state[i] = tmp[i];
    }
}




static void Round(unsigned char *state, unsigned char *key) {
    SubBytes(state);
    ShiftRows(state);
    MixColumns(state);
    AddRoundKey(state, key);
}

void FinalRound(unsigned char *state, unsigned char *key) {
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, key);
}




void AESEncrypt(unsigned char *message, unsigned char *expandedKey, unsigned char *encryptedMessage) {
    unsigned char state[16]; 

    for (int i = 0; i < 16; i++) {
        state[i] = message[i];
    }

    int numberOfRounds = 9;

    AddRoundKey(state, expandedKey); 

    for (int i = 0; i < numberOfRounds; i++) {
        Round(state, expandedKey + (16 * (i + 1)));
    }

    FinalRound(state, expandedKey + 160);

    for (int i = 0; i < 16; i++) {
        encryptedMessage[i] = state[i];
    }
}

void KeyExpansionCore(unsigned char * in, unsigned char i) {
	unsigned char t = in[0];
	in[0] = in[1];
	in[1] = in[2];
	in[2] = in[3];
	in[3] = t;

	in[0] = s[in[0]];
	in[1] = s[in[1]];
	in[2] = s[in[2]];
	in[3] = s[in[3]];


	in[0] ^= rcon[i];
}


void KeyExpansion(unsigned char inputKey[16], unsigned char expandedKeys[176]) {
	
	for (int i = 0; i < 16; i++) {
		expandedKeys[i] = inputKey[i];
	}

	int bytesGenerated = 16;
	int rconIteration = 1; 
	unsigned char tmpCore[4]; 

	while (bytesGenerated < 176) {
		for (int i = 0; i < 4; i++) {
			tmpCore[i] = expandedKeys[i + bytesGenerated - 4];
		}


		if (bytesGenerated % 16 == 0) {
			KeyExpansionCore(tmpCore, rconIteration++);
		}

		for (unsigned char a = 0; a < 4; a++) {
			expandedKeys[bytesGenerated] = expandedKeys[bytesGenerated - 16] ^ tmpCore[a];
			bytesGenerated++;
		}

	}
}

