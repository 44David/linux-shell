#include <iostream>
#include <vector>
#include <regex>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstring>


int find_files() {
    // TODO: make output more readable
    std::filesystem::path cwd = std::filesystem::current_path();

    for (const auto & entry : std::filesystem::directory_iterator(cwd))
        std::cout << entry.path() << std::endl;

    return 0;
};

int read_file(char* filename) {
    
    std::string line;
    std::ifstream readfile;

    readfile.open(filename);

    while (std::getline ( readfile, line )) {
        std::cout << line << std::endl;

    };
    readfile.close();

    return 0;
};

int main() {
    std::vector<std::string> args_vector;
    std::string arg1, arg2;

    
    // char regex_e[] = "[a-zA-Z]\w+";

    while (1) {
        std::cout << "> ";  

        std::cin >> arg1;

        std::regex characters ("[^a-zA-Z0-9]+");

        if (std::regex_match(arg1, characters)) {
           std::cout << "Unknown output";
        };

        std::getline(std::cin, arg2);

        if (arg1 == "ls") {
            find_files();
        }; if (arg1 == "cat") {
            int length = arg2.length();
            char* char_arg2 = new char[length + 1];

            strcpy(char_arg2, arg2.c_str());

            read_file(char_arg2);
        }; if (arg1 == "echo") {
            std::cout << arg2 << std::endl;
        }; 
    };
    
    // TODO: fix this regular expression


    return 0;
       
};

