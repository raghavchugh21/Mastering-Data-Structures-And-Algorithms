#include <iostream>
#include <string>
using namespace std;
#include<stack>
#include <cmath>
int countBracketReversals(string input) {
	
    stack<int> s;
    float m = 0;
    for(int i=0;i<input.size();i++){
        if(input[i]=='{'){
            s.push('(');
        }
        else{
            if(s.empty()){
                m++;
                continue;
            }
            s.pop();
        }
    }
    float n=0;
    while(!s.empty()){
        s.pop();
        n++;
    }
    if(int(m+n)%2==0)
    	return ceil(m/2) + ceil(n/2);
    else
        return -1;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}