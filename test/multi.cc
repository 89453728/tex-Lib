#include "multi.h"

// constructor vacio
Hola::Hola(){
	data = "";
	size = 0;
	next = nullptr;
}
// constructor de copia
Hola::Hola(const Hola &h1){
	data=h1.data;
	size = h1.size;
	next=h1.next;
}
// destructor
Hola::~Hola(){
	Hola *ptr = next;
	Hola *aux = ptr;
	while(ptr->next != nullptr){
		aux = ptr;
		ptr = ptr->next;
		aux = nullptr;
	}
	ptr = nullptr;
}
void Hola::append(const Hola &h1){
	Hola *ptr;
	while(ptr->next != nullptr){
		ptr = ptr->next;
	}
	ptr->next = new Hola(h1);
	size++;
}
Hola Hola::getHola(int k)const{
	int iter = 0;
	if(size > k){
		if(k!=0){
			Hola *ptr = next;
			while(ptr-> next != nullptr && iter<k){
				ptr=ptr->next;
				iter++;
			}
			return *ptr;
		}else{
			return *this;
		}
	}
}
std::string Hola::getData()const{
	return data;
}

void Hola::setData(const std::string &s){
	data=s;
}
int Hola::getSize()const{
	return size;
}
