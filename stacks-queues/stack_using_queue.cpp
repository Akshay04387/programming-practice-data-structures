#include <bits/stdc++.h>


class Stack {
	static int curr;
	std::queue<int> q1,q2;
	public:
		void push(int val);
		int pop(void);
		//int peek(void);
};

int Stack::curr = 0;

void Stack::push(int val){
	curr++;
	q1.push(val);
	while(!q2.empty()){
		q1.push(q2.front());
		q2.pop();
	}
	//replacing the names of the queues
	std::queue<int> q;
	q = q1;
	q1 = q2;
	q2 = q;
}

int Stack::pop(void){
	if(curr==0){
		std::cout<<"stack is empty"<<std::endl;
		return -1;
	}else
		curr--;
		int val=q2.front();
	    q2.pop();
	    return val;
}

int main(){
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	std::cout<<s1.pop();
	std::cout<<" "<<s1.pop();
	std::cout<<" "<<s1.pop()<<"\n";
	std::cout<<s1.pop();
}