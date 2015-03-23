//
//  main.cpp
//  LOJ_rotate-array
//
//  Created by 丛远东 on 15/3/18.
//  Copyright (c) 2015年 丛远东. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k%n;
        for(int i=0;i<=(n-k-1)/2;i++){
            int t = nums[i];
            nums[i] = nums[n-k-1-i];
            nums[n-k-1-i] = t;
        }
        
        for(int i=n-k,j=1;i<=(2*n-k-1)/2;i++,j++){
            int t = nums[i];
            nums[i] = nums[n-j];
            nums[n-j] = t;
        }
        
        for(int i=0;i<n/2;i++){
            int t = nums[i];
            nums[i] = nums[n-i-1];
            nums[n-i-1] = t;
        }
        
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    int nums[7] = {1,2,3,4,5,6,7};
    s.rotate(nums, 7, 9);
    for(int i=0;i<7;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
