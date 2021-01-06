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
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}

class Queue {
    
    Node *fron,*rear;
    int size;
    
    public:
    
    Queue() {
        rear = NULL;
        fron = NULL;
        size = 0;
    }
    
    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        Node *temp = new Node(data);
        if(isEmpty()){
            fron = temp;
            rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
            return -1;
        }
        else{
            int data = fron->data;
            fron = fron->next;
            if(fron==NULL)
                rear=NULL;
            size--;
            return data;
        }
        return 0;
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
            return -1;
        else
            return fron->data;
    }
    
};