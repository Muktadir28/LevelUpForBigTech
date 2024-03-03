//
//  CountKSubsequencesOfAStringWithMaximumBeauty.cpp
//  
//
//  Created by Md Muktadir on 3/3/24.
//

class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        set<char> distinctChars;
        vector<pair<int, int>> freq(26, {0, 0});

        for(char ch : s) {
            freq[ch - 'a'].first++;
            freq[ch - 'a'].second = ch - 'a';
            distinctChars.insert(ch);
        }

        if(distinctChars.size() < k) {
            return 0;
        }

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        long long ans = 1;
        int mod = 1000000000 + 7;
        int idx = 0;

        while(idx < freq.size() && freq[idx].first != freq[k - 1].first) {
            ans = (ans * freq[idx].first) % mod;
            idx++;
        }

        int numberOfKFreq = 0;
        int remainingIdxes = k - idx;
        long long kFreqMultiplier = 1;

        while(idx < freq.size() && freq[idx].first == freq[k - 1].first) {
            numberOfKFreq++;
            idx++;
        }

        kFreqMultiplier = nCr_mod_m(numberOfKFreq, remainingIdxes, mod);

        while(remainingIdxes--) {
            kFreqMultiplier = (kFreqMultiplier * freq[k -1].first) % mod;
        }

        ans = (ans * kFreqMultiplier) % mod;
        return ans;
    }

    int nCr_mod_m(int n, int r, int m)
    {
        int nCr[n + 1][r + 1];
        int i, j;

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= min(i, r); j++) {
                if (j == 0 || j == i)
                    nCr[i][j] = 1;

                else
                    nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % m;
            }
        }

        return nCr[n][r];
    }
};

#include <stdio.h>

int main() {
    //Nothing to do here
    return 0;
}
