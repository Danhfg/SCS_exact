#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H

#include <string>
#include <vector>

bool 
ends_with(std::string const & value, std::string const & ending);

void 
populateOverlaps( std::vector<std::vector<int>> &overlaps, std::vector<std::string> &reads);

void
bitMask(std::vector<std::vector<int>> &dp, std::vector<std::vector<int>> &parent,
    std::vector<std::vector<int>> &overlaps, int N);

std::string 
scsWithDynamicPrograming(std::vector<std::string> reads);

#endif