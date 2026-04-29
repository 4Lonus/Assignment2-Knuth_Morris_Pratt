#ifndef KMP_MAIN_H
#define KMP_MAIN_H

#include "iostream"
#include "vector"

bool KMP(const std::string& text, const std::string& word);
std::vector<int> findFailureSpotsKMP(const std::string& input);

#endif