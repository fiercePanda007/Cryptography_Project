// encryption/main_new.cpp
#include "rsa_project.h"
#include <iostream>

int main() {
    primefiller();
    setkeys();
    std::string message;

    std::cout << "Enter the message: ";
    getline(std::cin, message);

    // calling the encoding function
    std::vector<int> coded = encoder(message);

    std::cout << "Initial message:\n" << message;
    std::cout << "\n\nThe encoded message (encrypted by public key):\n";
    for (auto& p : coded)
        std::cout << p;
    std::cout << "\n\nThe decoded message (decrypted by private key):\n";
    std::cout << decoder(coded) << std::endl;

    return 0;
}
