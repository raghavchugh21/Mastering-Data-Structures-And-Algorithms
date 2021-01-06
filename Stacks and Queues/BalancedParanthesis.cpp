#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}


#include <bits/stdc++.h> 
using namespace std;

bool isBalanced(string expression) 
{
    stack<char> s;
    for(int i=0;i<expression.size();i++){
        if(expression[i]=='(')
           s.push(expression[i]);
        else{
           if(!s.empty()&&s.top()=='(')
               s.pop();
           else 
               return false;
        }
    }
    if(!s.empty())
        return false;
    return true;
}