//
//  main.cpp
//  LOJ_number-of-1-bits
//
//  Created by 丛远东 on 15/3/17.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            if(n%2 == 1)
                count ++;
            n/=2;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.hammingWeight(1111);
}
