#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int num = nums.size();
    return nums[num / 2];
}

int main()
{
    vector<int> nums;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << majorityElement(nums);

    return 0;
}