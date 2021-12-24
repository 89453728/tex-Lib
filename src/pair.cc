/*
parser.h

Copyright (C) 2020-2021 Yassin Achengli <0619883460@uma.es>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, see
<https://www.gnu.org/licenses/>.

======================================================================
*/

#include "pair.h"
using tex::uint;

/*
	Priotity order 
	() 
	^
	/
	* 
	+
	-	
*/
bool tex::checkPhar(const std::string &p){
	bool ret = true;
	uint opened=0;
	uint closed=0;
	for(uint i=0;i<p.length();i++){
		if(p[i]=='('){
			opened++;
		}else if(p[i]==')'){
			closed++;
		}else{
			continue;
		}
	}
	if(opened != closed) {
		return false;
	}
	uint i=0;
	while(i<p.length()){
		if(p[i]=='('){
			opened=1;
			closed=1;
			uint j=i+1;
			while(opened != closed && j<p.length()){
				if(p[j] == '('){
					opened++;
				}else if(p[j]==')'){
					closed++;
				}else{
					continue;
				}
				j+=1;
			}
			if(opened==closed){
				if(opened == 1){
					ret *= true;
				}else {
					std::string buff = "";
					for(uint k=i+1;k<j;k++){
						buff+=p[k];
					}
					ret *= checkPhar(buff);
				}
			}else{
				ret *= false;
			}
			i+=j;
		}else {
			i += 1;
		}
	}
	return ret;
}

bool tex::clear(const std::string &text, const std::string &patterns) {
	for(uint i=0;i<text.length();i++){
		for(uint j=0;i<patterns.length();j++){
			if(text[i] == patterns[j]){
				return false;
			}
		}
	}
	return true;
}

tex::Bifunc* strFunc(const std::string &o){
	tex::Bifunc *ret;
	uint mults=0,divs=0,subs=0,pots=0,sums=0,phars=0;
	/*check if any pharentesis opened is closed correctly and if all the operators 
	have two members and count all of them*/
	uint last=0;
	
	if(!tex::checkPar(o)){
		return;
	}
	
	for(uint i=0;i<o.length();i++){		
		else if(o[i]=='*' && i!= o.length()-1 && i!=0){
			std::string check="" + o[i-1] + o[i] + o[i+1];
			if(clear(check),"*+-/^"){
				mults++;	
			}
		}else if(o[i]=='/' && i!= o.length()-1 && i!=0){
			std::string check="" + o[i-1] + o[i] + o[i+1];
			if(clear(check),"*+-/^"){
				divs++;	
			}
		}else if(o[i]=='+' && i!= o.length()-1 && i!=0){
			std::string check="" + o[i-1] + o[i] + o[i+1];
			if(clear(check),"*+-/^"){
				sums++;	
			}
		}else if(o[i]=='-' && i!= o.length()-1 && i!=0){
			std::string check="" + o[i-1] + o[i] + o[i+1];
			if(clear(check),"*+-/^"){
				subs++;	
			}
		}else if(o[i]=='^' && i!= o.length()-1 && i!=0){
			std::string check="" + o[i-1] + o[i] + o[i+1];
			if(clear(check),"*+-/^"){
				pots++;	
			}
		}
	}
	
	
	std::string prev="";
	if(sums != 0){
		for(uint i=0;i<o.length();i++){
			if(o[i] == '+'){
				std::string after="";
				for(uint k=i+1;k<o.length();k++){
					after+=o[i];
				}
				if(clear(after,"+-*/^") && clear(prev,"+-*/^")){
					tex::Bin bifuncdata;
					bifuncdata.op = '+';
					int r = bifuncdata.a = std::stod(prev);
					if(!r) {
						std::cerr<<"Syntax error, numbers no agree\n";
					}
					r = bifuncdata.b = std::stod(after); // getting the values to assign into the function  
					if(!r) {
						std::cerr<<"Syntax error, numbers no agree\n";
					}
					return new tex::Bifunc(bifuncdata);
				}else{
					ret->appendBin(strFunc(prev),0);
					ret->appendBin(strFunc(after),1);
					return ret;
				}
			}
			prev+=o[i];
		}
	}
}

bool checkFunction (const std::string &fun) {
	std::string funcs[4][7] = {
		{"acos","asin","atan","acosh","asinh","atanh","abs"},
		{"cos","cosh","ceil","","","",""},
		{"exp","log","log10","log2","floor","",""},
		{"sin","sinh","sqrt","tan","tanh","trunc","round"}
	};
	uint l[] = {7,3,5,7};
	uint selector;
	if(fun[0] == 'a'){
		selector=0;
	}else if(fun[0] == 'c'){
		selector=1;
	}else if(fun[0] == 'e' || fun[0] == 'l' || fun[0] == 'f'){
		selector=2;
	}else if(fun[0] == 's' || fun[0] == 't' || fun[0] == 'r'){
		selector=3;
	}else {
	        return false;
	}
	for(uint i=0;i<l[selector];i++){
		if(fun == funcs[selector][i]){
			return true;
		}
	}
	return false;
}


double tex::call(const Bin &s){
	swith (s.op) {
		case "cos": return cos(s.a);break;
		case "sin": return sin(s.a);break;
		case "tan": return tan(s.a);break;
		case "acos": return acos(s.a);break;
		case "asin": return asin(s.a);break;
		case "atan": return atan(s.a);break;
		case "sinh": return cosh(s.a);break;
		case "cosh": return sinh(s.a);break;
		case "tanh": return tanh(s.a);break;
		case "asinh": return acosh(s.a);break;
		case "acosh": return asinh(s.a);break;
		case "atanh": return atanh(s.a);break;
		case "exp": return exp(s.a); break;
		case "log": return log(s.a);break;
		case "log10": return log10(s.a);break;
		case "log2": return log2(s.a);break;
		case "sqrt": return sqrt(s.a);break;
		case "ceil": return ceil(s.a);break;
		case "floor": return floor(s.a);break;
		case "trunc": return trunc(s.a);break;
		case "round": return round(s.a);break;
		case "abs": return abs(s.a);break;
		default: std::cerr << "function not found\n";	 
	};
}
/*constructors and destructors*/
tex::Bifunc::Bifunc(const std::string &form){
	
}
tex::Bifunc::Bifunc(const tex::Bin &d) {
	data=d;
	childa=nullptr;
	childb=nullptr;
}
tex::Bifunc::Bifunc(const Bifunc &o){
	data=o.data;
	childa=o.childa;
	childb=o.childb;
}
tex::Bifunc::~Bifunc(const){
	if(childa != nullptr){
		~childa; // kill child a
	}
	if(childb != nullptr){
		~childb; // kill child b
	}
}
	
/*methods */
void tex::Bifunc::appendBin(const tex::Bifunc &o, tex::uint p){
	if(p==0){
		childa = &o;
	}else{
		childb = &o;
	}
}
tex::Bifunc * tex::Bifunc::getChild(tex::uint p) const{
	if(p==0)
		return childa;
	
	return childb;
}
double tex::Bifunc::eval() const{
	switch(op){
		case "+":
			return data.a+data.b;
			break;
		case "-":
			return data.a-data.b;
			break;
		case "*":
			return data.a*data.b;
			break;
		case "/":
			return data.a/data.b;
			break;
		case "^":
			return pow(data.a,data.b);
			break;
		default: 
			return tex::call(data);
	}
}
double tex::Bifunc::eval(const double a, const double b) const{
	switch(op){
		case "+":
			return a+b;
			break;
		case "-":
			return a-b;
			break;
		case "*":
			return a*b;
			break;
		case "/":
			return a/b;
			break;
		case "^":
			return pow(a,b);
			break;
		default: 
			tex::Bin d;
			d.a=a;
			d.b=b;
			d,op = data.op;
			return tex::call(d);
	}
}
