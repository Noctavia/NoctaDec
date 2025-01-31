#include "include/extractor.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

bool extract_pyc_from_exe(const std::string& exe_path, const std::string& output_dir) {
    std::ifstream file(exe_path, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur : Impossible d'ouvrir " << exe_path << std::endl;
        return false;
    }

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    const char magic_number[] = { 0x42, 0x0D, 0x0D, 0x0A };
    auto it = std::search(buffer.begin(), buffer.end(), std::begin(magic_number), std::end(magic_number));

    if (it == buffer.end()) {
        std::cerr << "Aucun fichier .pyc trouvé." << std::endl;
        return false;
    }

    fs::create_directory(output_dir);
    std::ofstream out(output_dir + "/extracted.pyc", std::ios::binary);
    out.write(&(*it), buffer.end() - it);
    out.close();

    std::cout << "Fichier .pyc extrait dans " << output_dir << std::endl;
    return true;
}
