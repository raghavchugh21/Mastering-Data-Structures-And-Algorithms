#include <iostream>
#include <queue>
using namespace std;
#include<queue>
#include<stack>

queue<int> reverseKElements(queue<int> &input, int k) {
    
    queue<int> q;
    stack<int> s;
    
    for(int i=0;i<k;i++){
        s.push(input.front());
        input.pop();
    }
    
    for(int i=0;!input.empty();i++){
        q.push(input.front());
        input.pop();
    }
    
    for(int i=0;i<k;i++){
        input.push(s.top());
        s.pop();
    }
    
    for(int i=0;!q.empty();i++){
        input.push(q.front());
        q.pop();
    }
    
    return input;
    
}

int main() {
    int n, k;
    cin >> n >> k;
    
    queue<int> q;

    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }

    queue<int> ans = reverseKElements(q, k);

    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}