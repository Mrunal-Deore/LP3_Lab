//Write a program to generate binomial coefficients using dynamic programming.

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateBinomialCoefficients(int n) {
    // 2D vector to store the binomial coefficients
    vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));

    //  binomial coefficients
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            // Base cases
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C;
}

void printBinomialCoefficients(const vector<vector<int>>& C) {
    int n = C.size() - 1; 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;
    
    vector<vector<int>> binomialCoefficients = generateBinomialCoefficients(n);

    cout << "Binomial coefficients for n = " << n << ":\n";
    printBinomialCoefficients(binomialCoefficients);

    return 0;
}


//****************************** OUTPUT ******************************//
/*
Enter the value of n: 5
Binomial coefficients for n = 5:
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
*/