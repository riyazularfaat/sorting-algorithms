#include<bits/stdc++.h>
using namespace std;
void pritVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "Printing the vector: \n";
    pritVector(v);

    cout << "Deletting the last element: \n";
    v.pop_back();
    pritVector(v);

    vector<int> v2(3, 10); // 3 elements with value 10
    cout << "Printing the vector with 3 elements with value 10: \n";
    pritVector(v2);

    vector<int> &v3(v2); // copy constructor
    v3.push_back(20);
    cout << "Printing the vector v3 after copying v2: \n";
    pritVector(v3);

    vector<int> v4;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the element " << i + 1 << ": ";
        cin >> x;
        v4.push_back(x);
    }
    cout << "Printing the vector v4 after input: \n";
    pritVector(v4);

    return 0;
}