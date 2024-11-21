#include<bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    cin>>num;
    int l = num.length();
    int ans = num[l - 1] + num[l - 2];
    for (int i = l - 2; i >= 0; i--)
    {
        ans = (ans %3 + num[i] % 3) % 3;
    }
    if (ans % 3 == 0)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}