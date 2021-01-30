#include <iostream>
#include "solution.h"
using namespace std;

#include<cstring>
bool helper(char input[],int start, int end)
{
    if(start>=end)
        return true;
    
    bool smallAns = helper(input,start+1,end-1);
    
    if((input[start]==input[end])&&(smallAns))
        return true;
    
    return false;
}
bool checkPalindrome(char input[]) {
    // Write your code here
	return helper(input,0,strlen(input)-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
