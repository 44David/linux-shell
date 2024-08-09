#include <iostream>
#include <vector>
#include <regex>
#include <filesystem>
#include <string>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <sstream>
#include <cstdio>
#include <cstdlib>

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

char * str_to_char(std::string str) {
        int length = str.length();
        char *char_str = new char [length + 1];

        strcpy(char_str, str.c_str());
        return char_str;
}

int main(int argc, char** argv) {
    std::vector<std::string> args_vector;
    std::string arg1, arg2;


    while (1) {
        std::cout << "> ";  

        std::cin >> arg1;

        std::regex characters ("[^a-zA-Z0-9/.*!#(){}=+-~]+");

        if (std::regex_match(arg1, characters)) {
           std::cout << "Unknown output" << std::endl;;
        };

        std::getline(std::cin, arg2);
        

        // TODO make this more readable and efficient.
        // TODO add error handling for all functions and commands.
        if (arg1 == "ls") { 
            find_files();
        }; if (arg1 == "cat") {
            read_file(str_to_char(arg2));
        }; if (arg1 == "echo") {
            std::cout << arg2 << std::endl;
        }; if (arg1 == "cd") {
            chdir(str_to_char(arg2));
        }; if (arg1 == "pwd") {
            std::cout << std::filesystem::current_path() << std::endl;
        }; if (arg1 == "run") {

            std::ostringstream oss;
            oss << "chmod +x " << arg2;
            std::string chmod_string = oss.str();
            system(str_to_char(chmod_string));

            std::ostringstream oss2;
            oss2 << "./" << arg2;
            std::string exec_string = oss.str();
            system(str_to_char(exec_string));
        }; if (arg1 == "touch") {
            std::ofstream outfile (arg2);
        }; if (arg1 == "mkdir") {
                std::filesystem::create_directories(arg2);
        }; if (arg1 == "rm") {
            std::remove(str_to_char(arg2));
        }

    };

    return 0;
       
};

