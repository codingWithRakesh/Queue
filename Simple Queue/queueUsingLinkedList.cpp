#include <iostream>
using namespace std;

class Node {
public :
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* head;
    int length;
public:
    Queue(){
        head = NULL;
        length = 0;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }else{
            Node* tmp = head;
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
        length++;
    }

    void pop(){
        if(head == NULL){
            cout << "invalid" << endl;
            return;
        }
        Node* tmp = head;
        head = head->next;

        delete tmp;
        length--;
    }

    int front(){
        if(head == NULL){
            cout << "invalid" << endl;
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }

    int size(){
        return length;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    cout << "Size: " << q.size() << endl;   // 3

    q.pop();
    cout << "Front after pop: " << q.front() << endl; // 20
    cout << "Size after pop: " << q.size() << endl;   // 2

    q.pop();
    q.pop();

    cout << "Empty: " << (q.empty() ? "Yes" : "No") << endl; // Yes

    q.pop(); // will print "invalid"

    return 0;
}