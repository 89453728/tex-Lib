#ifndef MULTI
#define MULTI
#include <string>

class Hola {
 	private: 
 		Hola * next;
 		std::string data; 
 		int size;
 	public:
		Hola();
		Hola(const Hola &h1);
		~Hola();
		
		void append(const Hola &h1);
		Hola getHola(int k) const;
		
		std::string getData()const;
		void setData(const std::string &s);
		int getSize()const;
};
#endif
