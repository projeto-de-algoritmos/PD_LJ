#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
 
// problema de particao usando programacao dinamica
bool subsetSum(vector<int> const &A, int n, int sum)
{
    
    if (sum == 0) 
        return true;
    
    if (n < 0 || sum < 0) 
        return false;
 
    bool include = subsetSum(A, n - 1, sum - A[n]);
 
    if (include) 
        return true;
 
    bool exclude = subsetSum(A, n - 1, sum);
    return exclude;
}
 
bool partition(vector<int> const &A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    return !(sum & 1) && subsetSum(A, A.size() - 1, sum/2);
}
 
int main() {

    // vector<int> A = { 7, 3, 1, 5, 4, 8 };
    vector<int> A;
    int n, val;
    cout << "Escreva a quantidade do seu set: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        printf("Escreva o valor do indice %d: ", i);
        cin >> val;
        A.push_back(val);
    }
    if (partition(A)) {
        cout << "Set pode ser particionado." << "\n";
    }
    else {
        cout << "Set nao pode ser particionado." << "\n";
    }
 
    return 0;
}