#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    unordered_map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (m.find(i) == m.end())
        {
            ans.push_back(i);
        }
    }
    return ans;
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
    vector<int> ans = findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
