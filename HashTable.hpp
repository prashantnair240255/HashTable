#include "LinkedList.hpp"

template<class T, class U>
class HashTable{

private:
	int hash(T key);
	LinkedList<T, U> *bucket;

public:
	HashTable();
	U& operator[](T key);
	void display();
};

