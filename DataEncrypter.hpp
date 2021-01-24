#ifndef DATAENCRYPTER_HPP
#define DATAENCRYPTER_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <iostream>
class DataEncrypter {
    private:
        const int PASSWORD_LENGTH = 9;
        const std::string CIPHER_KEY = "jones";
        const std::string RAW_FILE = "raw.txt";
        const std::string ENCRYPTED_FILE = "encrypted.txt";
        std::string getExtendedKey(std::string);
        std::string generateRandomPassword();
    public:
        DataEncrypter();
        std::string encryptPassword(std::string password);
        std::string decryptPassword(std::string password);
        void exportData(std::string inputFileName, bool encrypt);
};
#endif