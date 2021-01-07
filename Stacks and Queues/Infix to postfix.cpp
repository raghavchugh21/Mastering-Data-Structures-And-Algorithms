#include<iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int calc(int a,int b,char op){
    int ans=0;
    switch(op)
    {
        case '+':
            ans=a+b;
            break;
        case '-':
            ans=a-b;
            break;
        case '*':
            ans=a*b;
            break;
        case '/':
            ans=a/b;
            break;
    }
    return ans;
}


void evaluatePostfix(char exp[]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the required output.
     * Taking input is handled automatically.
     */
    // Precedence map
    
    unordered_map<char,int> prec;
    prec['/']=2;
    prec['*']=2;
    prec['+']=1;
    prec['-']=1;
    
    string postfix="";
    
    stack <char> op;
    for(int i=0;exp[i]!='\0';i++){
        
        if(exp[i]>=48 && exp[i]<=57)
            postfix+=exp[i];
        else if(op.empty() || exp[i]=='('){
                op.push(exp[i]);
            }
        else if(exp[i]!=')'){
            
                while(!op.empty() && prec[exp[i]]<=prec[op.top()] && op.top()!='('){
                    postfix+=op.top();
                    op.pop();
                    }
                    op.push(exp[i]);
                }    
        else{
            while(!op.empty() && op.top()!='('){
                postfix+=op.top();
                op.pop();
            }
            if(!op.empty() && op.top()=='(')
                op.pop();        
        } 
    }
    while(!op.empty()){
        postfix+=op.top();
        op.pop();
    }
    cout<<postfix<<endl;
    
    stack<int> cal;
    int k=0;
    while(k<postfix.size()){
        if(postfix[k]>=48 && postfix[k]<=57){
            cal.push(postfix[k]-48);
        }
        else{
            int b=cal.top();
            cal.pop();
            int a=cal.top();
            cal.pop();
            int ans=calc(a,b,postfix[k]);
            cal.push(ans);
        }
        k++;
    } 
    cout<<cal.top()<<endl;;
}


//Driver program to test above functions
int main()
{
    char exp[1000];
    cin >> exp;
    evaluatePostfix(exp);
    return 0;
}