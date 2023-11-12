#ifndef SHA512_H
#define SHA512_H

#include <iostream>
#include <bitset>

typedef unsigned long long int int64;

class SHA512 {
private:
    int64 Message[80];
    const int64 Constants[80];
    
    std::string gethex(std::string bin);
    std::string decimaltohex(int64 deci);
    int64 BintoDec(std::string bin);
    int64 rotate_right(int64 x, int n);
    int64 shift_right(int64 x, int n);
    void separator(std::string getBlock);
    int64 maj(int64 a, int64 b, int64 c);
    int64 Ch(int64 e, int64 f, int64 g);
    int64 sigmaE(int64 e);
    int64 sigmaA(int64 a);
    void Func(int64 a, int64 b, int64 c, int64& d, int64 e, int64 f, int64 g, int64& h, int K);

public:
    SHA512();
    std::string generateSHA512(std::string myString);
};

#endif
