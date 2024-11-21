#include<bits/stdc++.h> 
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    int even_element = 0;
    for (int val = 0; val < nums.size(); val++)
    {
        if (nums[val] % 2 == 0)
        {
            swap(nums[val], nums[even_element]);
            even_element++;
        }
    }
    return nums;
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
    vector<int> result = sortArrayByParity(nums);
    for (int val : result)
    {
        cout << val << " ";
    }
    return 0;
}