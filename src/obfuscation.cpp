#include "include/obfuscation.hpp"
#include <iostream>
#include <cstdlib>

void deobfuscate_code(const std::string& py_file) {
    std::string command = "python3 python_bindings/py_deobfuscate.py " + py_file;
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Déobfuscation réussie." << std::endl;
    } else {
        std::cerr << "Erreur lors de la déobfuscation." << std::endl;
    }
}
