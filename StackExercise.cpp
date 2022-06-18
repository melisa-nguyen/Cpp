
#include <iostream>
#include <stack>

using namespace std;
template <typename T>
void insertElement(stack<T>& myStack, T element) {
	stack<T> newStack;
	for (int i = 0; i < myStack.size()+1 / 2; i++){
		newStack.push(myStack.top());
		myStack.pop();
	}
myStack.push(element); //Insert the new element to the top of the original stack
while (newStack.empty() == false) { //Add back to oringal top half of the stack that was copied to newStack
	myStack.push(newStack.top());
	newStack.pop();
}

}
template <typename P>
void printStack(stack<P> myStack) {
	cout << "\nTOP"<< endl;
	
	while(myStack.empty()== false){ //While stack is not empty the top element will be printed then deleted from the stack
		cout << myStack.top() << endl;
		myStack.pop();
	}
	cout << "BOTTOM" << endl;
}

int main()
{
	stack<int> myStack; //Create and populate stack
	myStack.push(10);
	myStack.push(20);
	myStack.push(30);
	myStack.push(40);
	myStack.push(50);
	myStack.push(60);
	myStack.push(70);
	myStack.push(80);

	int element;
	cout << "Enter element to add to middle of stack:" << endl; //If input is not an integer, a zero will take place of the element and be inserted
	cin >> element;
	insertElement(myStack, element);
	printStack(myStack);



}
