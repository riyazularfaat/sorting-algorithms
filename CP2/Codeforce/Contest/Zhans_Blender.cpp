#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;
        if (n == 0){
            cout << 0 << endl;
            continue;
        }

        long long time = 0;
        while(n > 0)
        {
            long long to_put = min(y, n);
            n -= min(x, to_put);
            time++;
        }

        cout << time << endl;
    }

    return 0;
}