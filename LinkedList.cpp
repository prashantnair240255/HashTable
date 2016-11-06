#include "LinkedList.hpp"

template<class T, class U>
U& LinkedList<T,U>::operator[](T key){
	Item<T, U> *temp = head;
	while(temp && temp->key != key){
		temp = temp->next;
	}

	if(temp)
		return temp->value;
	else{
		insertItem(key, "");
		temp = head;
		while(temp->next)
			temp = temp->next;
		return temp->value;
	}
}

template<class T, class U>
void LinkedList<T, U>::insertItem(T key, U value){
	Item<T, U> *item = new Item<T, U>;
	item->key = key;
	item->value = value;
	item->next = NULL;

	if(!head){
		head = item;
	}
	else{
		Item<T, U> *temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = item;
	}
}

template<class T, class U>
void LinkedList<T, U>::printContents(){
	Item<T, U> *temp = head;
	while(temp){
		std::cout << "[" << temp->key << ":" << temp->value << "]\t";
		temp = temp->next;
	}
}




