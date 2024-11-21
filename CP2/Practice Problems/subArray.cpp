#include<bits/stdc++.h>
using namespace std;

void subArray(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }    
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    subArray(arr, n);

    return 0;
}