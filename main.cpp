#include <iostream>
#include <vector>
#include <regex>
#include <filesystem>
#include <string>

int main() {

    std::vector<std::string> args_vector;
    std::string args;

    std::cout << "Custom Linux Shell" << std::endl;

    std::cout << " > ";  
    std::cin >> args;
        
    // TODO: fix this regular expression
    std::regex e ("([a-zA-Z])\w+)");
    if ( std::regex_match(e, args) ) {
        std::cout << "Output is a string";
    } else {
        "Unknown output"
    }

    return 0;
       
};

int find_files() {
    // TODO: make output more readable
    std::filesystem::path cwd = std::filesystem::current_path();

    for (const auto & entry : std::filesystem::directory_iterator(cwd))
        std::cout << entry.path() << std::endl;

    return 0;

}