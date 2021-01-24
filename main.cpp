#include "DataEncrypter.hpp"
#include "HashTable.hpp"
int main() {
    DataEncrypter de;
    de.exportData("lastNames.txt", false);
    de.exportData("raw.txt", true);
    HashTable ht;
    ht.importData("encrypted.txt");
    return 0;
}