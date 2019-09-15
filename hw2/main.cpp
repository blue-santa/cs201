/** 
 * main.cpp
 * Bryan Beus
 * September 14, 2019
 * The main program in the assignment - vector names and other features
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/functional/hash.hpp>

void InputNames(std::vector<std::string> & names) {
    for (int i = 0; i < 10; i++) {

        std::string name;
        std::cout << "Please enter a name: ";
        std::getline (std::cin, name);
        names.push_back(name);
    }
}

bool DoesNameExist(const std::vector<std::string> & names) {

    // const std::string & nameToFind, 
    std::string nameToFind;
    std::cout << "Tell me a name for which to search in the database: ";
    std::getline (std::cin, nameToFind);

    for (int i = 0; i < names.size(); i++) {
        if (names.at(i) == nameToFind) {
            return true;
        }
    }

    return false;
}

void PrintNames(const std::vector<std::string> & names) {

    for (int i = 0; i < names.size(); i++) {

        std::cout << names.at(i) << std::endl;
    }

}

void CreateHashData(const std::vector<std::string> & names) {

    std::vector<std::string> hash_table;
    for (int i = 0; i < names.size(); i++) {
        boost::hash<std::string> string_hash;
        hash_table.push_back(string_hash(names.at(i));
    }

    return hash_table;
}

int main(int argc, char **argv) {

    std::vector<std::string> names;
    InputNames(names);

    std::cout << std::endl;

    // nameToFind, 
    bool result_of_name_search = DoesNameExist(names);
    std::cout << result_of_name_search << std::endl;

    std::cout << std::endl;

    PrintNames(names);

    std::vector<std::string> hash_table = CreateHashTable(names);

    std::cout << std::endl << "The following hashes belong respectively to the names vector." << endl;
    PrintNames(hash_table);

    std::cout << std::endl;

    return 0;
}
