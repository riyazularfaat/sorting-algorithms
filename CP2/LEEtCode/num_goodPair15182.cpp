#include<bits/stdc++.h> 
using namespace std;

int numIdenticalPairs(vector<int> &nums)
{
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    int ans = 0;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        ans += i->second * (i->second - 1) / 2;
    }
    return ans;
}

int main()
{
    vector<int> nums;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << "Number of good pairs: " << numIdenticalPairs(nums) << endl;
}