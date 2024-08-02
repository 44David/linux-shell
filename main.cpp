#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> args_vector;
    std::string args;

        std::cout << "Custom Linux Shell" << std::endl;

        std::cout << " > ";  
        std::cin >> args;
        std::cout << typeid(args).name();
       
};