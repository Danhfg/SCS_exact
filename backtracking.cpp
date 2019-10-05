#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

static bool starts_with(const std::string str, const std::string prefix)
{
    return ((prefix.size() <= str.size()) && std::equal(prefix.begin(), prefix.end(), str.begin()));
}

int overlap(std::string a, std::string b, int min_length=5)
{
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
            std::string stringThatLevel, std::string * shortest){
    
    if (depth == n){
        //std::vector<bool>::iterator it = std::find(used.begin(), used.end(), 0);
        //int index = std::distance(used.begin(), it);
        //int over = overlap(stringThatLevel, a[index], 1);
        //stringThatLevel += a[index].substr(over);
        for (auto const& c: used) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
        int over = overlap(stringThatLevel, curr[n-1], 1);
        stringThatLevel += curr[n-1].substr(over);
        if (*shortest != "" and stringThatLevel.size() >= shortest->size()){
            return;
        }
        else
            *shortest = stringThatLevel;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (not used[i])
        {  
            std::string stringAux = "";
            if (stringThatLevel == "")
            {
                stringAux = a[i];
            }
            else{
                stringAux = stringThatLevel;
                int over = overlap(stringThatLevel, a[i], 1);
                stringAux += a[i].substr(over);
                //stringThatLevel = stringThatLevel;
                if (*shortest != "" and stringAux.size() >= shortest->size()){
                    return;
                }
            }


            curr.push_back(a[i]);
            used[i] = true;
            for (auto const& c: curr) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
            backtranckingSCS(a, n, depth+1, used, curr, stringAux, shortest);
            curr.pop_back();
            std::cout << "Voltando: ";
            for (auto const& c: curr) {
                std::cout << c << " ";
            }
            std::cout << std::endl;
            used[i] = false;
        }
    }
    return;
}

int main()
{
    std::vector<std::string> a = {"ccd", "bbc", "abb", "ddddddd"};
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
    backtranckingSCS(a, n, 0, used, curr, "", shortest);
    std::cout << "Shortest: "<< *shortest << std::endl;
    return 0;
}