#include<bits/stdc++.h>
using namespace std;

void pritVector(vector<int> &v){
    vector<int> ans;
    int n = v.size();
    for(int i = 0; i < n; i++)
        ans.push_back(v[i]);
    for(int i = 0; i < n; i++)
        ans.push_back(v[i]);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    vector<int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the element " << i + 1 << ": ";
        cin >> x;
        nums.push_back(x);
    }
    pritVector(nums);
    return 0;
}