#include "include/extractor.hpp"
#include "include/decompiler.hpp"
#include "include/disassembler.hpp"
#include "include/obfuscation.hpp"
#include <iostream>

int main() {
    std::string exe_path = "sample.exe";

    std::cout << "[1] Extraction..." << std::endl;
    if (!extract_pyc_from_exe(exe_path)) return 1;

    std::cout << "[2] Décompilation..." << std::endl;
    decompile_pyc("extracted/extracted.pyc");

    std::cout << "[3] Désassemblage..." << std::endl;
    disassemble_pyc("extracted/extracted.pyc");

    return 0;
}
