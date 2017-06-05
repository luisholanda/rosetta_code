#include "vigenere.h"

namespace Vigenere
{
    Digest::Digest(std::string inKey):
        mKey(inKey)
    {}

    Digest::~Digest()
    {}

    std::string Digest::padKey(int inLength)
    {
        std::string _padKey{this->mKey};

        for (size_t i = 0; _padKey.length() < inLength ; ++i) {
            _padKey += this->mKey[i];
        }

        return _padKey;
    }

    std::string Digest::encrypt(std::string inStr)
    {
        std::string key = this->padKey(inStr.length());
        std::string _crypt{};

        for (size_t i = 0; i < inStr.length(); i++) {
            _crypt[i] = static_cast<char>(static_cast<int>(inStr[i] + key[i])) + 'A';
        }

        return _crypt;
    }

    std::string Digest::decrypt(std::string inCrypt)
    {
        std::string key = this->padKey(inCrypt.length());
        std::string _decrypt{};

        for (size_t i = 0; i < inCrypt.length(); i++) {
            _decrypt[i] = static_cast<char>(static_cast<int>(inCrypt[i] - key[i])) + 'A';
        }

        return _decrypt;
    }
}
