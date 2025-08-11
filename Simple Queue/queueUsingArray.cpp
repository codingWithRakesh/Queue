#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int frontIndex = 0;
    int rearIndex = -1;
    int n;
public :
    Queue(int size){
        // arr = (int *)malloc(size*(sizeof(int)));
        arr = new int[size];
        n = size;
    }
    void push(int data){
        if (n - 1 <= rearIndex) {
            cout << "Stack Overflow\n";
            return;
        }
        rearIndex++;
        arr[rearIndex] = data;
    }

    void pop(){
        if(frontIndex > rearIndex){
            cout << "Stack Empty" << endl;
            return;
        }
        frontIndex++;
    }

    int front(){
        if(frontIndex > rearIndex){
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool empty(){
        return (rearIndex + 1 - frontIndex) == 0;
    }
};

int main(){
    Queue q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(4);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }


    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    return 0;
}