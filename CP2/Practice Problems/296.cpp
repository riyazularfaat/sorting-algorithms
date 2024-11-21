#include <iostream>
#include <limits.h>
using namespace std;

// Function to find the minimum number of scalar multiplications
void matrixChainOrder(int p[], int n) {
    // Create a 2D table to store the minimum number of multiplications
    int m[n][n];

    // m[i, j] = 0 when multiplying one matrix (i.e., i == j)
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length (from 2 to n-1)
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
// Try placing a parenthesis at different positions between i and j
            // to find the minimum cost
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    // Output the minimum number of multiplications needed
    cout << "Minimum number of multiplications is: " << m[1][n - 1] << endl;
}

int main()
{
    int p[] = {10, 20, 30, 40};
    int n ;
    cout << "Enter the number of matrices: ";
    cin>>n;
    matrixChainOrder(p, n);
    return 0;
}

