#include<iostream>
using namespace std;
#include<string>
template<class T>
class stack
{
	protected:
	T *ele;
	int capacity;
	int top;
	public:
	stack();
	stack(int);
	bool isempty();
	bool isfull();
	bool push(T);
	T pop();
	~stack();
};
template<class T>
stack<T>::stack()
{
	capacity = 10;
	top = -1;
	ele = new T[capacity];
}
template<class T>
stack<T>::stack(int c)
{
	top = -1;
	capacity = c;
	ele = new T[capacity];
}
template<class T>
bool stack<T>::isempty()
{
 	return(top==-1);
}
template<class T>
bool stack<T>::isfull()
{
 	return(top==(capacity-1));
}
template<class T>
bool stack<T>::push(T e)
{
	if(isfull())
		return false;
	ele[++top]=e;
	return true;	
}
template<class T>
T stack<T>::pop()
{
	return (ele[top--]);
}
template<class T>
stack<T>::~stack()
{
	delete []ele;
}
class inspectable_stack:public stack<int>
{
	public:
	int inspect();
};
int inspectable_stack::inspect()
{
	return (ele[top]);
}

int main()
{
	inspectable_stack i;
	i.push(1);
	cout<<i.inspect()<<endl;
	cout<<i.pop()<<endl;	
}


