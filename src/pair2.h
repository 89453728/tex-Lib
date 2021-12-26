#ifndef PAIRTEX
#define PAIRTEX
#include <string>
#include <iostream>
#include <cmath>

#define ABC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMS "0123456789"
#define E 2.718281828
namespace tex {
	typedef unsigned int uint;
	
	template <class T>
	struct Binary {
		T a,b; // one for each side
		std::string op; // name of the function that associate a and b
		uint level;
	}; 
	typedef Binary Bin;

	bool checkFunction (const std::string &fun);
	bool countChar(const std::string &, const std::string &);
	bool contain(const std::string &text, const std::&patterns);
	bool checkPhar(const std::string &p);
	std::string char2str(const char &c);

	template <class T>
	class funcSplit {
		private: 
			std::string func;
			Bin<T> *bins;
			uint len;
		public: 
			funcSplit();
			funcSplit(const funcSplit &o);
			/*
				will be some new operators of sum, substract, multiplication
				and division.
			*/		
			Bin operator()(uint pos)const;
			uint getLen() const;
			std::string getFunc()const;
			void setFunc(const std::string &s);
	};

	template <class T>
	funcSplit<T>::funcSplit() {
		bins = nullptr;
		func = "";
		len=0;
	}
	template <class T>
	funcSplit<T>::funcSplit(const funcSplit &o){
		func = o.getFunc();
		bins = new Bins[o.getLen()];
		for(uint i=0;i<o.getLen();i++){
			bins[i] = o(i);
		}
		len = o.getLen();
	}
	template <class T>
	std::string funcSplit<T>::getFunc()const{
		return this->func;
	}
	template <class T>
	void funcSplit<T>::setFunc(const std::string &s) {
		this->func = s;
	}
	template <class T>
	uint funcSplit<T>::getLen() const {
		return len;
	}
	template <class T>
	Bin funcSplit<T>::operator ()(uint pos)const{
		if(pos < len){
			return bins[pos];
		}
	}
	template <class T>
	bool funcSplit<T>::resolve() {
		if(!checkPhar(func)){
			return false; // check if every pharentesis is ok
		}
		/*priority ^ / * + - */
	}

}
#endif
