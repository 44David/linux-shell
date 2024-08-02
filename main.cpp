#include <iostream>
#include <vector>
#include <regex>

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
       
};