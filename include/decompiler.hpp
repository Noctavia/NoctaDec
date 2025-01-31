#ifndef DECOMPILER_HPP
#define DECOMPILER_HPP

#include <string>

void decompile_pyc(const std::string& pyc_file, const std::string& output_file = "output.py");

#endif // DECOMPILER_HPP
