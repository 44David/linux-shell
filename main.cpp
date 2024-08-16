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

void save_output(char** args) {
    std::ofstream commandfile ("command-history.txt");

    commandfile << args;

    commandfile.close();
};

int main(int argc, char** argv) {
    
    while (1) {
        std::cout << "> ";  


        std::regex characters ("[^a-zA-Z0-9/.*!#(){}=+-~]+");

        // if (std::regex_match(arg1, characters)) {
        //    std::cout << "Unknown output" << std::endl;;
        // };

        
        // TODO make this more efficient 
        
        //for (int i = 0 ; i >= argc ; i++){
        save_output(argv);  
        //}
        
        
        if (argc == 1) {
            if (argv[0] == "ls") {
                find_files();
            }; 
            if (argv[0] == "pwd") {
                std::cout << std::filesystem::current_path() << std::endl;
            };
        }; 
        
        if (argc == 2) {
            if (argv[0] == "cat") {
                read_file(argv[1]);
            };
            if (argv[0] == "echo") {
                std::cout << argv[1];
            };
            if (argv[0] == "cd") {
                chdir(argv[1]);
            };
            if (argv[0] == "run") {
                std::ostringstream oss;
                oss << "chmod +x " << argv[1];
                std::string chmod_string = oss.str();
                system(str_to_char(chmod_string));

                std::ostringstream oss2;
                oss2 << "./" << argv[1];
                std::string exec_string = oss.str();
                system(str_to_char(exec_string));
            };
            if (argv[0] == "touch") {
                std::ofstream outfile (argv[1]);
            };
            if (argv[0] == "mkdir") {
                std::filesystem::create_directories(argv[1]);
            };
            if (argv[0] == "rm") {
                std::remove(argv[1]);
            };


        };

        if (argc == 3 && argv[1] == ">") {
            //TODO add error handling
            auto input = system(argv[0]);

            std::ofstream outfile (argv[2]);

            outfile << input;

            outfile.close();
        };


       
    return 0;
    
    };
};
