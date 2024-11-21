#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long result;
        vector<long long> a(n);
        for (int i = 0; i < n-1; i++)
        {
            cin >> a[i];
            sort(a.begin(), a.end());
            result = a[n - 1] - a[n - 2];
        }
        
        cout << result << endl;
    }
    return 0;
}