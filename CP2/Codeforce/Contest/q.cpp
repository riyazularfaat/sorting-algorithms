#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            int d = a[i] -a[i+1];
            if((a[i] - a[i+1] == 5 || a[i] - a[i+1] == 7) && (a[i] - a[i+2] == 5 || a[i] - a[i+2] == 7)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}