#include<bits/stdc++.h>
using namespace std;

long long max_pairwise_product(const vector<int>& numbers)
{
    int n = numbers.size();
    long long max_product = 0;
    for(int first = 0;first<n;++first)
    {
        for(int second = first+1;second<n;++second)
        {
            if((long long) numbers[first]*numbers[second]>max_product)
                max_product = (long long) numbers[first]*numbers[second];
        }
    }
    return max_product;
}
int main()
{
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++)
    {
        cin>>numbers[i];
    }
    long long result = max_pairwise_product(numbers);
    cout<<result<<endl;
    return 0;
}