#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}

class Stack {
    // Define the data members
    Node *head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return head==NULL;
    }

    void push(int element) {
        if(isEmpty()){
            Node *temp = new Node(element);
            head = temp;
        }
        else{
            Node *temp = new Node(element);
            temp->next = head;
            head = temp;
        }
        size++;
        // Implement the push() function
    }

    int pop() {
        if(isEmpty())
            return -1;
        int x = head->data;
        head = head->next;
        size--;
        return x;
        // Implement the pop() function
    }

    int top() {
        if(isEmpty())
            return -1;
        return head->data;
        // Implement the top() function
    }
};