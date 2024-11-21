#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Declairing a pair
    pair<int, int> p;
    p = make_pair(1, 2); // or p = {1, 2};

    cout << "Prtinting the pair of integers: \n";
    cout << p.first << " " << p.second << endl;

    pair<int, string> p1;
    p1 = make_pair(1, "Hello");
    cout << "Prtinting the pair of integers & string: \n";
    cout << p1.first << " " << p1.second << endl;

    // Declairing an array of pairs
    pair<int,int> p_array[3];
    p_array[0] = {1, 2};
    p_array[1] = {3, 4};
    p_array[2] = {5, 6};
    cout << "Prtinting the pair of array of integers: \n";
    for(int i = 0; i < 3; i++)
        cout << p_array[i].first << " " << p_array[i].second << endl;

    //Coping pair
    pair<int, int> &p2 = p;
    p2.first = 3;
    p2.second = 4;
    cout << "Prtinting the pair of integers after copying: \n";
    cout << p.first << " " << p.second << endl;

    // Swapping pairs
    swap (p_array[0], p_array[2]);
    cout << "Prtinting the pair of array of integers after swapping: \n";
    for (int i = 0; i < 3; i++)
        cout << p_array[i].first << " " << p_array[i].second << endl;

    pair<int, int> p3;
    cout << "Enter a pair of integers: ";
    cin>>p3.first>>p3.second; // Input pair
    cout << "Prtinting the pair of integers after input: \n";
    cout << p3.first << " " << p3.second << endl;


    pair<int, int> p_array2[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter a pair of integers: ";
        cin >> p_array2[i].first >> p_array2[i].second;
    }
    cout << "Prtinting the pair of array of integers after input: \n";
    for (int i = 0; i < 5; i++)
        cout << p_array2[i].first << " " << p_array2[i].second << endl;




    return 0;
}