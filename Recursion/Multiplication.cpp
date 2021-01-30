#include <iostream>
#include "solution.h"
using namespace std;

int multiplyNumbers(int m, int n) {
    // Write your code here
	if(n==0)
        return 0;
    int smallAns = multiplyNumbers(m,n-1);
    return m+smallAns;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
