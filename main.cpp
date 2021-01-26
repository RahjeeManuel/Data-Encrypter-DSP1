#include <vector>
#include "DataEncrypter.hpp"
#include "HashTable.hpp"
int main() {
    //Creates .txt files
    DataEncrypter de;
    de.exportData("lastNames.txt", false);  //reads lastNames.txt and exports to raw.txt
    de.exportData("raw.txt", true);     //reads raw.txt and exports to encrypted.txt

    //Creates the hash table
    HashTable ht;
    ht.importData("encrypted.txt"); //reads encryped.txt and creates a hash table
    
    //creates creates a pair<userId, password> vector from raw.txt
    std::ifstream inFile("raw.txt");
    std::vector<std::pair<std::string, std::string> > dataEntries;
    if (inFile.is_open()) {
        int counter = 0;
        std::string line;
        while (getline(inFile, line) && counter < 5) { //only takes the first five entries
            std::stringstream ss(line);
            std::pair<std::string, std::string> dataPair;
            ss >> dataPair.first >> dataPair.second;
            dataEntries.push_back(dataPair);
            counter++;
        }
        inFile.close();
    } else {
        std::cout << "raw.txt could not be opened." << std::endl;
        exit (EXIT_FAILURE);
    }

    std::cout << "Legal:" << std::endl;
    std::cout << std::setw(15) << std::left << "Userid" << std::setw(15) << std::left << "Password" << "Result" << std::endl;

    //hashes each userid from the pair vector and compares the entry's password with the hashtable's password
    for (int i = 0; i < dataEntries.size(); i++) {
        std::string userId = dataEntries[i].first;
        std::string rawPassword = dataEntries[i].second;
        std::string encryptedPassword = de.encryptPassword(rawPassword);    //encrypts the plain text password
        std::string hashTablePassword = ht.searchNode(userId)->getPassword();   //gets the encrypted password from the hash table
        std::cout 
        << std::setw(15) << std::left << userId 
        << std::setw(15) << std::left << rawPassword 
        << ((encryptedPassword == hashTablePassword) ? "match" : "no match")    ////compares both encrypted passwords
        << std::endl;
    }

    std::cout << "\nIllegal:" << std::endl;
    std::cout << std::setw(15) << std::left << "Userid" << std::setw(15) << std::left << "Password" << "Result" << std::endl;

    //changes one letter in the unencrypted password then checks if it matches the password in the hashtable
    for (int i = 0; i < dataEntries.size(); i++) {
        std::string userId = dataEntries[i].first;
        std::string rawPassword = dataEntries[i].second;
        rawPassword[0] = 'x'; //changes the first letter in the plaintext password to x
        std::string encryptedPassword = de.encryptPassword(rawPassword);    //encrypts the changed password
        std::string hashTablePassword = ht.searchNode(userId)->getPassword();   //gets the encrypted password from the hash table
        std::cout 
        << std::setw(15) << std::left << userId 
        << std::setw(15) << std::left << rawPassword 
        << ((encryptedPassword == hashTablePassword) ? "match" : "no match")    //compares both encrypted passwords
        << std::endl;
    }
    return 0;
}