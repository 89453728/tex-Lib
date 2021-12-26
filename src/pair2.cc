#include "pair2.h"

bool tex::checkPhar(const std::string &p) {
	uint opened=0,closed=0;
	for(uint i=0;i<p.length();i++){
		if(p[i] == '('){
			opened++;
		}else if(p[i]==')'){
			closed++;
		}else{
			continue;
		}
	}	
	return opened==closed;
}
std::string tex::char2str(const char &c){
	std::string ret = "";
	ret.append(1,c);
	return ret;
}

uint tex::countChar(const std::string &text, const std::string &patt){
	uint ret=0;
	for(uint i=0;i<text.length();i++)
		(text[i] == patt)? ret++ : continue;

	return ret;
}
bool tex::contain(const std::string &text, const std::string &patterns){
	for(int i=0;i<text.length();i++){
		for(int j=0;j<patterns.length();j++){
			if(text[i] == patterns[j]){
				return true;
			}
		}
	}
	return false;
}
bool tex::chechFunction(const std::string &fun){
	std::string trim = "";
	/* quit all white spaces */
	for(int i=0;i<fun.length();i++){
		if(fun[i] != ' '){
			trim += fun[i];
		}
	}
	
	/* check if hasn't some character in @#!|~=&?[]{}:;º´"$% */
	if(contain(trim,"@#!|~=&?[]{}:;º\"$%")){
		return false;
	}

	/*check if the first and the last characters are not operators
	examples: 
		*2+x^3-8*x
		4*98+5*(7-4)/
	*/
	
	if(contain(char2str(trim[0]),"+*/^") || contain(char2str(trim[trim.length()-1]),"+-*/^")){
		return false;
	}
	/*check if two characters in a row are not operators 
	examples: 
		2*x*(1+54)-9*+9
	check if a number is writted well: examples of bad numbers: 
	21. , x.77 ,. ,

	*/
	for(int i=1;i<trim.length()-1;i++){
		std::string buff;
		buff="";
		if(contain(char2str(trim[i]),"+-*/^")){
			if(contain(char2str(trim[i+1]),"*/)+^") || contain(char2str(trim[i-1]),"-+(")){
				error("dos operadores seguidos");
				return false;
			}

			int j;
			j = i+1;
			while(!contain(char2str(trim[j]),"*/-+^") && j<trim.length()){
				buff+=trim[j];
				j++;
			}
			if(contain(buff,NUMSDOT) && contain(buff,ABC)){
				error("hay un numero con caracteres entre dos operadores");
				return false;
			}
			buff="";
			j=i-1;
			while(!contain(char2str(trim[j]),"*/-+^") && j>=0){
				buff+=trim[j];
				j--;
			}
			if(contain(buff,NUMSDOT) && contain(buff,ABC)){
				error("hay un numero con caracteres entre dos operadores");
				return false;
			}
			buff="";
		}else if(contain(char2str(trim[i]),".")){
			int j;
			j=i+1;
			while(!contain(char2str(trim[j]),"+-*/^") && j<trim.length()){
				buff+=trim[j];
				j++;
			}
			j=i-1;
			while(!contain(char2str(trim[j]),"+-*/^") && j>=0){
				buff+=trim[j];
				j--;
			}
			if(contain(buff,ABC)){
				error("hay un numero con su . mal expresado");
				return false;
			}
		}
	}
	return true;
}
