#include "sha512.h"

int main() {
    // Input
    std::string S = "GeeksForGeeks";

    // Create an instance of SHA512
    SHA512 sha512;

    // Function Call
    std::cout << S << ": " << sha512.generateSHA512(S);

    return 0;
}
