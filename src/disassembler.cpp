#include "include/decompiler.hpp"
#include <iostream>
#include <cstdlib>

void decompile_pyc(const std::string& pyc_file, const std::string& output_file) {
    std::string command = "python3 python_bindings/py_decompile.py " + pyc_file + " " + output_file;
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << "Décompilation réussie : " << output_file << std::endl;
    } else {
        std::cerr << "Erreur lors de la décompilation." << std::endl;
    }
}
