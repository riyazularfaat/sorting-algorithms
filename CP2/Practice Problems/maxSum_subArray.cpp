#include<bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int> &vec)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int val: vec)
    {
        currentSum += val;
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}


int main()
{
    vector<int> vec = {1, -2, 3, 10, -4, 7, 2, -5};    
    maxSubarray(vec);

    return 0;
}