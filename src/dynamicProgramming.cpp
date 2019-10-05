#include <iostream>
#include <algorithm>  /// min
#include <cmath> /// pow

#include "dynamicProgramming.h"

/**
 * https://stackoverflow.com/questions/874134/find-out-if-string-ends-with-another-string-in-c
 * Obs.: Em C++ 20 já existe esse método
 */ 
inline bool ends_with(std::string const & value, std::string const & ending) {
    if (ending.size() > value.size()) 
        return false;
    
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

void 
populateOverlaps( std::vector<std::vector<int>> &overlaps,
    std::vector<std::string> &reads) {
    
    int N = reads.size();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j){
            if ( i != j) {
                int min = std::min(reads[i].length(), reads[j].length());
                for (int k = min; k >=0; --k) {
                   if (ends_with(reads[i], reads[j].substr(0, k))) {
                       overlaps[i][j] = k;
                       break;
                   }
                }
            }
        }
    }
}

void
bitMask(std::vector<std::vector<int>> &dp,
    std::vector<std::vector<int>> &parent,
    std::vector<std::vector<int>> &overlaps,
    int N) {

    for (int mask = 0; mask < (1 << N); ++mask) {
        for (int bit = 0; bit < N; ++bit) {
            if (((mask >> bit) & 1) > 0) {
                int pmask = mask ^ (1 << bit);
                
                if ( pmask == 0)
                    continue;
                
                for (int i = 0; i < N; ++i) {
                    if (((pmask >> i) & 1) > 0 ) {
                        int val = dp[pmask][i] + overlaps[i][bit];
                        if ( val > dp[mask][bit]) {
                            dp[mask][bit] = val;
                            parent[mask][bit] = i;
                        }
                    }
                }

            }
        }
    }
}

std::string 
scsWithDynamicPrograming(std::vector<std::string> reads) {
    
    int N = reads.size();
 
    // // 1o Passo
    std::vector<std::vector<int>> overlaps(N, std::vector<int>(N));

    populateOverlaps(overlaps, reads);
 
    // // 2o Passo
    std::vector<std::vector<int>> dp(1 << N, std::vector<int>(N));
    std::vector<std::vector<int>> parent(1 << N, std::vector<int>(N, -1));
    
    bitMask(dp, parent, overlaps, N);

    // 3o Passo
    std::vector<int> perm(N);
    std::vector<bool> seen(N);
    int t = 0;
    int mask = (1 << N) - 1;

    int p =0;
    for (int j = 0; j < N; ++j) {
        if (dp[(1<<N) - 1][j] > dp[(1<<N) - 1][p]){}
            p = j;
    }

    while (p != -1) {
        perm[t++] = p;
        seen[p] = true;
        int p2 = parent[mask][p];
        mask = mask ^(1 << p);
        p = p2;
    }

    for (int i = 0; i < t/2; ++i) {
        int v = perm[i];
        perm[i] = perm[t-1-i];
        perm[t-1-i] = v;
    }

    for (int i = 0; i < N; ++i) {
        if (!seen[i])
            perm[t++] = i;
    } 

    std::string answer(reads[perm[0]]);

    for (int i = 1; i < N; ++i) {
        int overlap = overlaps[perm[i-1]][perm[i]];
        answer += (reads[perm[i]].substr(overlap));
    }

    return answer;
}

int main() {

  std::vector<std::string> palavras;
  palavras.push_back("ccd");
  palavras.push_back("bbc");
  palavras.push_back("abb");
  palavras.push_back("ddddddd");
  
  std::cout << "A resposta:" << scsWithDynamicPrograming(palavras);
}