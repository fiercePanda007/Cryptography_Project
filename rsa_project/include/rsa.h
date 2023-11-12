// rsa.h
#ifndef RSA_H
#define RSA_H

#include <string>
#include <vector>

extern int public_key;
extern int private_key;
extern int n;

void setkeys();
long long int encrypt(double message);
long long int decrypt(int encrypted_text);
std::vector<int> encoder(std::string message);
std::string decoder(std::vector<int> encoded);

#endif // RSA_H
