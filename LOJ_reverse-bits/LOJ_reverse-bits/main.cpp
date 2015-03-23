//
//  main.cpp
//  LOJ_reverse-bits
//
//  Created by 丛远东 on 15/3/17.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int t=31;
        while(n!=0){
            if(n%2==1)
                ans+=pow(2,t);
            t--;
            n/=2;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.reverseBits(43261596);
}
