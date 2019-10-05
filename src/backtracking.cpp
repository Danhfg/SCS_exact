#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#include "backtracking.h"

static bool starts_with(const std::string str, const std::string prefix){
    return ((prefix.size() <= str.size()) && std::equal(prefix.begin(), prefix.end(), str.begin()));
}

int overlap(std::string a, std::string b, int min_length){
    /* Retorna o tamanho do maior sufixo ou prefixo que contenha pelo menos min_length.
        Se não existir sobreposição, returna 0. */
    int start = 0; 
    while (1){
        start = a.find(b.substr(0,min_length), start);
        if (start == -1)
            return 0;
        if (starts_with(b,a.substr(start,a.size()-1) ) )
            return (a.size())-start;
        start += 1;
    }
}

void backtranckingSCS(std::vector<std::string> a, size_t n,
            size_t depth,std::vector<bool> used, std::vector<std::string> curr, 
            std::string stringThatLevel, std::string * shortest, int * iter){
    
    if (depth == n){
        //std::vector<bool>::iterator it = std::find(used.begin(), used.end(), 0);
        //int index = std::distance(used.begin(), it);
        //int over = overlap(stringThatLevel, a[index], 1);
        //stringThatLevel += a[index].substr(over);
        //int over = overlap(stringThatLevel, curr[n-1], 1);
        /*
        std::cout << over;
        stringThatLevel += curr[n-1].substr(over);
        if (*shortest != "" and stringThatLevel.size() >= shortest->size()){
            return;
        }
        else
            *shortest = stringThatLevel;
        std::cout << over << "A";*/
        *shortest = stringThatLevel;
        std::cout << "Tamanho da menor superstring atual: " << shortest->size() << std::endl;
    }
    
    for (size_t i = 0; i < n; ++i)
    {
        if (not used[i])
        {  
            *iter += 1;
            curr.push_back(a[i]);
            used[i] = true;
            for (auto const& c: curr) {
                if (c == curr[curr.size()-1])
                {
                    std::cout << c;
                }
                else
                    std::cout << "|-";
            }
            std::cout << std::endl;


            std::string stringAux = "";
            if (stringThatLevel == "")
            {
                stringAux = a[i];
                backtranckingSCS(a, n, depth+1, used, curr, stringAux, shortest, iter);
                curr.pop_back();
                //std::cout << "Voltando: ";
                //for (auto const& c: curr) {
                    //std::cout << c << " ";
                //}
                //std::cout << std::endl;
                used[i] = false;
            }
            else{
                stringAux = stringThatLevel;
                int over = overlap(stringThatLevel, a[i], 1);
                stringAux += a[i].substr(over);
                //stringThatLevel = stringThatLevel;
                if (not (*shortest != "") or stringAux.size() < shortest->size()){
                    backtranckingSCS(a, n, depth+1, used, curr, stringAux, shortest, iter);
                    //std::cout << "Voltando: ";
                    //for (auto const& c: curr) {
                        //std::cout << c << " ";
                    //}
                    //std::cout << std::endl;
                }
                curr.pop_back();
                used[i] = false;

            }

        }
    }
    return;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> a = {"bbbbbbbcdd", "bbbbbbbbcd", "abbbbbbbb", "ddddddd"};
    //std::vector<std::string> a = {"ccd", "bbc", "abb", "ddddddd"};
    //std::vector<std::string> a = {"abb", "ccddddd", "bbc"};
    auto n(a.size());
    std::vector<bool> used;
    for (size_t i = 0; i < n; ++i)
    {
        used.push_back(false);
    }
    std::vector<std::string> curr;
    std::string * shortest = new std::string("");
    //*shortest = "";
    //std::cout << *shortest;
    int * iter = new int();
    *iter = 0;
    backtranckingSCS(a, n, 0, used, curr, "", shortest, iter);
    std::cout << "Shortest: "<< *shortest << std::endl;
    std::cout << "Iterações: "<< *iter << std::endl;

    return 0;
}