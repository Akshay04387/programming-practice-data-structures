#include <bits/stdc++.h>

class Queue{
    static int curr;
    std::stack<int> s1,s2;
    public:
    void enqueue(int val);
    int pop(void);
};

int Queue:: curr = 0;

void Queue::enqueue(int val){
    curr++;
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    s1.push(val);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
}

int Queue::pop(void){
    if(curr==0){
        std::cout<<"queue is empty";
        return -1;
    }
    curr--;
    int val = s2.top();
    s2.pop();
    return val;
}

int main(){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    std::cout<<q1.pop()<<" ";
    std::cout<<q1.pop()<<" ";
    std::cout<<q1.pop()<<" ";
    std::cout<<q1.pop()<<" ";
    std::cout<<q1.pop()<<" ";
    std::cout<<"\n";
}
