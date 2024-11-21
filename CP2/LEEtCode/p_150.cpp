// Given an integer array nums, return true if any value 
// appears more than once in the array, otherwise return false.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]] == 1)
                return true;
            mp[nums[i]]++;
        }
        return false;
    }
};
int main(){
    Solution s;
    vector<int> v = {1, 2, 3, 1};
    cout << s.containsDuplicate(v) << endl;
    return 0;
}