#include <iostream>


template<class T, class U> 
class Item{
	T key;
	U value;
	Item *next;
};

template<class T, class U>
class LinkedList{

private:
	Item<T, U> *head;

public:
	LinkedList():head(0){}
	U& operator[](T key);
	void insertItem(T key, U value);
	void printContents();
};

