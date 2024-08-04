#include <iostream>
#include <vector>
#include <regex>
#include <filesystem>
#include <string>
#include <fstream>

int find_files() {
    // TODO: make output more readable
    std::filesystem::path cwd = std::filesystem::current_path();

    for (const auto & entry : std::filesystem::directory_iterator(cwd))
        std::cout << entry.path() << std::endl;

    return 0;
};

void read_file(std::string filename) {
    
    std::ifstream readfile(filename);
    
    std::string line;

    while (std::getline ( readfile, line )) {
        std::cout << line << std::endl;
    };
};



int main() {

    std::vector<std::string> args_vector;
    std::string arg1, arg2;

    while (1) {
        std::cout << "> ";  

        std::cin >> arg1;
        std::getline(std::cin, arg2);

        if (arg1 == "ls") {
            find_files();
        }; if (arg1 == "cat") {
            read_file(arg2);
        };

    }




        
    // TODO: fix this regular expression
    // std::regex e ("([a-zA-Z])\w+)");
    // if ( std::regex_match(e, args) ) {
    //     std::cout << "Output is a string";
    // } else {
    //     "Unknown output"
    // }

    return 0;
       
};

