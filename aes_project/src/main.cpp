// main.cpp
#include <iostream>
#include<bits/stdc++.h>
#include "encryption.h"
#include "decryption.h"
using namespace std;

int main() {
    cout << "=============================" << endl;
    cout << " 128-bit AES Encryption Tool   " << endl;
    cout << "=============================" << endl;

    char message[1024];

    cout << "Enter the message to encrypt: ";
    cin.getline(message, sizeof(message));
    cout << message << endl;

    // Pad message to 16 bytes
    int originalLen = strlen((const char *)message);

    int paddedMessageLen = originalLen;

    if ((paddedMessageLen % 16) != 0) {
        paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
    }

    unsigned char *paddedMessage = new unsigned char[paddedMessageLen];
    for (int i = 0; i < paddedMessageLen; i++) {
        if (i >= originalLen) {
            paddedMessage[i] = 0;
        } else {
            paddedMessage[i] = message[i];
        }
    }

    unsigned char *encryptedMessage = new unsigned char[paddedMessageLen];

    string str;
    ifstream infile;
    infile.open("keyfile", ios::in | ios::binary);

    if (infile.is_open()) {
        getline(infile, str); // The first line of file should be the key
        infile.close();
    } else
        cout << "Unable to open file";

    istringstream hex_chars_stream(str);
    unsigned char key[16];
    int i = 0;
    unsigned int c;
    while (hex_chars_stream >> hex >> c) {
        key[i] = c;
        i++;
    }

    unsigned char expandedKey[176];

    KeyExpansion(key, expandedKey);

    for (int i = 0; i < paddedMessageLen; i += 16) {
        AESEncrypt(paddedMessage + i, expandedKey, encryptedMessage + i);
    }

    cout << "Encrypted message in hex:" << endl;
    for (int i = 0; i < paddedMessageLen; i++) {
        cout << hex << (int)encryptedMessage[i];
        cout << " ";
    }

    cout << endl;

    // Write the encrypted string out to file "message.aes"
    ofstream outfile;
    outfile.open("message.aes", ios::out | ios::binary);
    if (outfile.is_open()) {
        outfile.write(reinterpret_cast<char *>(encryptedMessage), paddedMessageLen);
        outfile.close();
        cout << "Wrote encrypted message to file message.aes" << endl;
    } else
        cout << "Unable to open file";

    // Free memory
    delete[] paddedMessage;
    delete[] encryptedMessage;
    
    
    
    
    
    cout << "=============================" << endl;
    cout << " 128-bit AES Decryption Tool " << endl;
    cout << "=============================" << endl;

    // Read in the message from message.aes
    string msgstr;
    ifstream infileD;
    infileD.open("message.aes", ios::in | ios::binary);

    if (infileD.is_open())
    {
        getline(infileD, msgstr); // The first line of file is the message
        cout << "Read in encrypted message from message.aes" << endl;
        infileD.close();
    }
    else cout << "Unable to open file";

    char *msg = new char[msgstr.size() + 1];

    strcpy(msg, msgstr.c_str());

    int n = strlen((const char *)msg);

    unsigned char * encryptedMessageD = new unsigned char[n];
    for (int i = 0; i < n; i++) {
        encryptedMessageD[i] = (unsigned char)msg[i];
    }

    // Free memory
    delete[] msg;

    // Read in the key
    string keystr;
    ifstream keyfile;
    keyfile.open("keyfile", ios::in | ios::binary);

    if (keyfile.is_open())
    {
        getline(keyfile, keystr); // The first line of file should be the key
        cout << "Read in the 128-bit key from keyfile" << endl;
        keyfile.close();
    }
    else cout << "Unable to open file";


    int j = 0;
    unsigned int d;
    while (hex_chars_stream >> hex >> d)
    {
        key[j] = d;
        j++;
    }


    KeyExpansion(key, expandedKey);

    int messageLen = strlen((const char *)encryptedMessage);

    unsigned char *decryptedMessage = new unsigned char[messageLen];

    for (int i = 0; i < messageLen; i += 16) {
        AESDecrypt(encryptedMessage + i, expandedKey, decryptedMessage + i);
    }

    cout << "Decrypted message in hex:" << endl;
    for (int i = 0; i < messageLen; i++) {
        cout << hex << (int)decryptedMessage[i];
        cout << " ";
    }
    cout << endl;
    cout << "Decrypted message: ";
    for (int i = 0; i < messageLen; i++) {
        cout << decryptedMessage[i];
    }
    cout << endl;

    return 0;
}



