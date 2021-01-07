#include <iostream>
#include <stack>
using namespace std;
#include <stack>
using namespace std;
void sortStack(stack<int> &s){
    // Write your code here
    stack<int> tempStack;
    
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        
        while(!tempStack.empty()&&tempStack.top()>temp)
        {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }
    
    while(!tempStack.empty()){
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> input;
    int size, value;
    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> value;
        input.push(value);
    }
    sortStack(input);
    while(!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
}
