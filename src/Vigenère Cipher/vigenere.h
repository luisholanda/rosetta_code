#include <string>

namespace Vigenere
{
    class Digest
    {
    public:
        Digest(std::string inKey);
        ~Digest();
    private:
        std::string mKey;
        std::string padKey(int inLength);
        static const unsigned int BASE = 26;

    public:
        std::string encrypt(std::string inStr);
        std::string decrypt(std::string inCrypt);
    };
}
