#include "DataEncrypter.hpp"
std::string DataEncrypter::getExtendedKey(std::string password) {
    if (password.size() <= CIPHER_KEY.size()) {
        return CIPHER_KEY;
    }
    int sizeDifference = password.size() - CIPHER_KEY.size();
    std::string extendedKey = CIPHER_KEY;
    while (sizeDifference >= CIPHER_KEY.size()) {
        extendedKey += extendedKey;
        sizeDifference -= CIPHER_KEY.size();
    }
    extendedKey += extendedKey.substr(0, sizeDifference);
    return extendedKey;
}
std::string DataEncrypter::generateRandomPassword() {
    std::string password;
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password.push_back('a' + rand() % 26);
    }
    return password;
}
DataEncrypter::DataEncrypter() {
    srand(time(0));
}
std::string DataEncrypter::encryptPassword(std::string password) {
    std::string encryption;
    std::string extendedKey = getExtendedKey(password);
    for (int i = 0; i < password.size(); i ++) {
        encryption += ((password[i] - 'a' + extendedKey[i] - 'a') % 26) + 'a';
    }
    return encryption;
}
std::string DataEncrypter::decryptPassword(std::string password) {
    std::string decryption;
    std::string extendedKey = getExtendedKey(password);
    for (int i = 0; i < password.size(); i ++) {
        decryption += (((password[i] - 'a' - (extendedKey[i] - 'a')) + 26) % 26) + 'a';
    }
    return decryption;
}
void DataEncrypter::exportData(std::string inputFileName, bool encrypt) {
    std::ifstream inFile(inputFileName);
    std::ofstream outFile(encrypt ? ENCRYPTED_FILE : RAW_FILE);
    if (inFile.is_open()) {
        if (outFile.is_open()) {
            std::string line;
            while (getline(inFile, line)) {
                std::stringstream ss(line);
                std::string userId;
                if (encrypt == false) {
                    ss >> userId;
                    outFile << std::setw(15) << std::left << userId << generateRandomPassword() << std::endl;  
                } else {
                    std::string password;
                    ss >> userId >> password;
                    outFile << std::setw(15) << std::left << userId << encryptPassword(password) << std::endl;
                }
            }
            outFile.close();
        } else {
           std::cout << (encrypt ? ENCRYPTED_FILE : RAW_FILE) << " could not be opened." << std::endl;
           exit (EXIT_FAILURE);
        }
        inFile.close();
    } else {
        std::cout << inputFileName << " could not be opened." << std::endl;
        exit (EXIT_FAILURE);
    }
}