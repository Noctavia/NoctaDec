#ifndef EXTRACTOR_HPP
#define EXTRACTOR_HPP

#include <string>

bool extract_pyc_from_exe(const std::string& exe_path, const std::string& output_dir = "extracted");

#endif // EXTRACTOR_HPP
