#include <iostream>
#include <string>

#define ABC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMS "0123456789"
#define NUMSDOT "0123456789."
#define E 2.718281828

std::string char2str(const char &c){
	std::string ret = "";
	ret.append(1,c);
	return ret;
}

void error(const std::string &desc){
	std::cerr << "checkFunction error at: " << desc << "\n"; 
}

bool contain(const std::string &text, const std::string &patterns){
	for(int i=0;i<text.length();i++){
		for(int j=0;j<patterns.length();j++){
			if(text[i] == patterns[j]){
				return true;
			}
		}
	}
	return false;
}
bool chechFunction(const std::string &fun){
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


int main(){
	std::cout << "ok\n";
	
	std::string f[] = {"2*x + 8 - (7*7 - x*9)",
			"55*4 + 6*(3^3*x-7)/6*",
			"88*x -4*(5*32.66-77)/8"};
	for(uint i=0;i<3;i++){
		std::cout << f[i] << "\n";
		if(chechFunction(f[i])){
			std::cout << "function " << i << " is well\n";
		}else {
			std::cout << "function "<< i << " is wrong \n";
		}
	}
	
	return 0;
}
