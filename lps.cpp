#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
// LPS é uma questao tipica em que a programacao dinamica tem um otimo resultado de solucao
int findLongestPalindrome(string X, int i, int j)
{
    if (i > j) 
        return 0;
 
    if (i == j)
        return 1;
 
    if (X[i] == X[j]) {

        return findLongestPalindrome(X, i + 1, j - 1) + 2;
    }

    return max(findLongestPalindrome(X, i, j - 1), findLongestPalindrome(X, i + 1, j));
}
 
int main()
{
    // string X = "ABBDCACACBAB";
    string X;
    cin >> X;
    int n = X.length();
 
    cout << "O tamanho da subsequência palindromica mais longa é: " << findLongestPalindrome(X, 0, n - 1) << "\n";
 
    return 0;
}