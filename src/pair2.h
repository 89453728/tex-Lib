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
	template<class T>
	T evaluate(const std::string &func, std::string *vars,T *values, int nvars);
	template <class T>
	class funcSplit {
		private: 
			std::string func;
			std::string vars;
			T *values;
			int nvars;
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
			int getNvars()const;
			T getValue(const int &pos)const;
			std::string getVarName(const int &pos)const;
	};
	template <class T>
	funcSplit<T>::funcSplit() {
		bins = nullptr;
		func = "";
		len=0;
		vars=nullptr;
		values = nullptr;
		nvars=0;
	}
	template <class T>
	funcSplit<T>::funcSplit(const funcSplit &o){
		func = o.getFunc();
		bins = new Bins[o.getLen()];
		for(uint i=0;i<o.getLen();i++){
			bins[i] = o(i);
		}
		len = o.getLen();
		vars=new std::string[o.getNvars()];
		nvars=o.getNvars();
		values=new T[nvars];
		for(int i=0;i<nvars;i++){
			vars[i] = o.getVarName(i);
			values[i] = o.getValue(i);
		}
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
	int funcSplit<T>::getNvars()const {
		return nvars;
	}
	template <class T>
	T funcSplit<T>::getValue(const int &pos)const {
		if(pos < nvars)
			return values[pos]; 
	}
	template <class T>
	std::string funcSplit<T>::getVarName(const int &pos)const{
		if(pos < nvars)
			return vars[pos];
	}
	template <class T>
	Bin funcSplit<T>::operator ()(uint pos)const{
		if(pos < len)
			return bins[pos];
	}
	template <class T>
	bool funcSplit<T>::resolve() {
		if(!checkPhar(func)){
			return false; // check if every pharentesis is ok
		}
		/*priority ^ / * + - */
		if(!checkFunction(func)){
			return false; // check if the function is well
		}	
	}	
	template<class T>
	T evaluate(const std::string &func, std::string *vars, T* values, int nvars){
		Bin
		for(int i=0;i<func.length();i++){
			switch(func[i]){
				case '(':
					int j=i+1;
					std::string buff="";
					while(func[j] != ')'){
						buff.append(1,func[i]);
						j++;
					}

					break;
				case '^':
					
					break;
				case '*':
					break;
				case '/':
					break;
				case '+':
					break;
				case '-':
					break;
				default: 
					continue;
			};
		}
	}
}
#endif
