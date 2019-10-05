#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <string>
#include <vector>

int 
overlap(std::string a, std::string b, int min_length = 5);

void 
backtranckingSCS( std::vector<std::string> a, size_t n,
    size_t depth,std::vector<bool> used, std::vector<std::string> curr, 
    std::string stringThatLevel, std::string * shortest, int * iter);
    

#endif