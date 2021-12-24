#include "textparser.h"

/* Var class definitions */

tex::Var::Var(){
	name="';
	value=0;
}
tex::Var::Var(const std::string &n){
    	name=n;
}
tex::Var::Var(const tex::Var &o){
	name=o.getName();
	value=o.getVal();
}

double tex::Var::eval(const double val){
	value=val;
	return val;
}
std::string tex::Var::getName()const{
	return name;
}
void tex::Var::setName(const std::string &n){
	name=n;
}
double tex::Var::getVal() const{
	return value;
}
int getValInt() const{
	return (int)value;
}
float getValFloat() const{
	return (float)value;
}
int8_t getValInt8()const{
	return (int8_t)value;
}
int16_t getValInt16()const{
	return (int16_t)value;
}
int32_t getValInt32() const{
	return (int32_t)value;
}
int64_t getValInt64()const{
	return (int64_t)value;
}
