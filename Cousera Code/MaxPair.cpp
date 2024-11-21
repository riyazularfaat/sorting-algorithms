#include <bits/stdc++.h>
using namespace std;

long long max_pairwise_product(const vector<int> &numbers)
{
    int n = numbers.size();
    if (n < 2)
        return 0; // If there are less than two numbers, return 0.

    // Initialize the two largest numbers.
    int max1 = -1, max2 = -1;
    for (int i = 0; i < n; ++i)
    {
        if (max1 == -1 || numbers[i] > numbers[max1])
        {
            max2 = max1;
            max1 = i;
        }
        else if (max2 == -1 || numbers[i] > numbers[max2])
        {
            max2 = i;
        }
    }

    return (long long)numbers[max1] * numbers[max2];
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    long long result = max_pairwise_product(numbers);
    cout << result << endl;
    return 0;
}
