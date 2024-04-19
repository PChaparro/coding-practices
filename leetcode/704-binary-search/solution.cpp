#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, 
            r = nums.size() - 1, 
            mid, 
            numAtMid; 

        while(l <= r){
            mid = (r + l) / 2; 
            numAtMid = nums[mid]; 

            if(numAtMid == target) return mid; 
            else if(numAtMid < target) l = mid + 1; 
            else r = mid -1; 
        }

        return -1; 
    }
};