/* Given an array of pairs representing students' IDs and their scores 
(e.g., pair<int, int> where first is the ID and second is the score), 
sort the array based on scores in descending order. 
If two students have the same score, sort them by ID in ascending order.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    pair<int, int> students[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the ID and score of student " << i + 1 << ": ";
        cin >> students[i].first >> students[i].second;
    }

    sort(students, students + n, [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }); // Sorting the array of pairs
    for (int i = 0; i < n; i++)
        cout << "ID: " << students[i].first << " Score: " << students[i].second << endl;

    return 0;
}