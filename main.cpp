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

int read_file(std::string filename) {
    std::ifstream readfile(filename);
    
    std::string line;

    while (getline ( readfile, line )) {
        std::cout << line << std::endl;
    };

    return 0;

};



int main() {

    std::vector<std::string> args_vector;
    std::string arg1, arg2;

    std::cout << "Custom Linux Shell" << std::endl;

    while (1) {
        std::cout << "> ";  

        std::cin >> arg1 ;

        if (std::cin >> arg2) {
            std::cout << arg2;
        };
        

        if (arg1 == "ls") {
            find_files();
        }; if (arg1 == "cat") {
            read_file("hello.txt");
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

