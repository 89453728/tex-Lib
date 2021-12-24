#ifndef COMPLEX_F
#define COMPLEX_F

//
#include <iostream>
#include <string>
#include <cmath>
#include "strfunc.h"

namespace ff {
    template <class T>
    class Complex {
        private:
            T real;
            T imag;
        public:
            Complex(const T r,const T im);
            Complex(const Complex &o);
            Complex(void);
            Complex(const T); 
            
            //Complex operator +(const T a,const Complex &o) const;
            Complex operator +(const Complex &o) const;
            Complex operator +(const T a) const;

            //Complex operator *(const T a,const Complex &o) const;
            Complex operator *(const Complex &o) const;
            Complex operator *(const T a) const;

            //Complex operator -(const T a,const Complex &o) const;
            Complex operator -(const Complex &o) const;
            Complex operator -(const T a) const;

            //Complex operator /(const T a,const Complex &o) const;
            Complex operator /(const Complex &o) const;
            Complex operator /(const T a) const;
            
            Complex operator =(const Complex &o); 
            Complex operator =(const T a);

            //std::string << (const Complex &p,const Complex &o) const;

            ff::Complex<T> operator +=(const Complex &o);
            ff::Complex<T> operator +=(const T a);

            ff::Complex<T> operator -=(const Complex &o);
            ff::Complex<T> operator -=(const T a);

            ff::Complex<T> operator *=(const Complex &o);
            ff::Complex<T> operator *=(const T a);

            ff::Complex<T> operator /=(const Complex &o);
            ff::Complex<T> operator /=(const T a);

            bool operator ==(const Complex &o) const;
            bool operator ==(const T a) const;

            bool operator !=(const Complex &o) const;
            bool operator !=(const T a) const;

            bool operator >(const Complex &o) const;
            bool operator >(const T a) const;

            bool operator <(const Complex &o) const;
            bool operator <(const T a) const;

            bool operator >=(const Complex &o) const;
            bool operator >=(const T a) const;

            bool operator <=(const Complex &o) const;
            bool operator <=(const T a) const;
    
            
            T angle () const; 
            T abs () const;
            Complex conj () const;
            T Real () const;
            T Imag () const;

            void c_print() const;
            std::string strVal () const;
            Complex str2complex(const std::string &txt) const;
            
    };
}

/* Constructors */

template <class T>
ff::Complex<T>::Complex(const T r,const T im) {real = r; imag = im;}

template <class T>
ff::Complex<T>::Complex(const ff::Complex<T> &o) {
    this->real = o.Real();
    this->imag = o.Imag();
}
template <class T>
ff::Complex<T>::Complex(void) {
    this->real=0;
    this->imag=0;
} 
template <class T>
ff::Complex<T>::Complex(const T t) {
    this->real = t;
}

/* Operators */

/*
template <class T>
ff::Complex<T> ff::Complex<T>::operator +(const T a, ff::Complex<T> &o) const{
    ff::Complex<T> ret(o.Real() + a, o.Imag());
    return ret;
}*/

template <class T>
ff::Complex<T> ff::Complex<T>::operator + (const ff::Complex<T> &o) const{
    ff::Complex<T> ret(this->real + o.Real(),this->imag + o.Imag());
    return ret;
}

template <class T>
ff::Complex<T> ff::Complex<T>::operator + (const T a) const{
    ff::Complex<T> ret(this->real + a,this->imag);
    return ret;
}
/*
template <class T> 
ff::Complex<T> ff::Complex<T>::operator *(const T a, const ff::Complex<T> &o) const{
    ff::Complex<T> ret(a*o.Real(),a*o.Imag());
    return ret;
}*/

template <class T>
ff::Complex<T> ff::Complex<T>::operator *(const ff::Complex<T> &o) const{
    ff::Complex<T> ret((this->real)*o.Real() - (this->imag)*o.Imag() , (this->real)*o.Imag() + (this->imag)*o.Real());
    return ret;
}

template <class T>
ff::Complex<T> ff::Complex<T>::operator *(const T a) const{
    ff::Complex<T> ret((this->real)*a, (this->imag)*a);
    return ret;
}
/*
template <class T>
ff::Complex<T> ff::Complex<T>::operator -(const T a, const ff::Complex<T> &o) const {
    ff::Complex<T> ret(a - o.Real(),o.Imag());
    return ret;
}*/

template <class T>
ff::Complex<T> ff::Complex<T>::operator -(const ff::Complex<T> &o) const{
    ff::Complex<T> ret(this->real - o.Real(),this->imag - o.Imag());
    return ret;
}

template <class T>
ff::Complex<T> ff::Complex<T>::operator -(const T a) const{
    ff::Complex<T> ret(this->real - a,this->imag);
    return ret;
}
/*
template <class T>
ff::Complex<T> ff::Complex<T>::operator /(const T a, const ff::Complex<T> &o) const {
    ff::Complex<T> ret(a*o.Real()/o.abs(), -a*o.Imag()/o.abs());
    return ret;
}*/

template <class T>
ff::Complex<T> ff::Complex<T>::operator /(const ff::Complex<T> &o) const{
    ff::Complex<T> ret(this->real,this->imag);
    ret = ret * (*o.conj());
    ret /= ret.abs();
    return ret;
}

template <class T>
ff::Complex<T> ff::Complex<T>::operator /(const T a) const {
    ff::Complex<T> ret(this->real/a,this->imag/a);
    return ret;
}

template <class T>
ff::Complex<T> ff::Complex<T>::operator =(const ff::Complex<T> &o) {
    this->real = o.Real();
    this->imag = o.Imag();
    return *this;
}

template <class T>
ff::Complex<T> ff::Complex<T>::operator =(const T a){
    this->real = a;
    return *this;
}
/*
template <class T>
std::string ff::Complex<T>::operator <<(const ff::Complex<T> &p, const ff::Complex<T> &o) const{
    return p.strVal() + o.strVal();
}*/

template<class T>
ff::Complex<T> ff::Complex<T>::operator +=(const ff::Complex<T> &o){
    this->real += o.Real();
    this->imag += o.Imag();
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator +=(const T a) {
    this->real += a;
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator -=(const ff::Complex<T> &o){
    this->real -= o.Real();
    this->imag -= o.Imag();
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator -=(const T a) {
    this->real -= a;
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator *=(const ff::Complex<T> &o){
    T rtemp=this->real, itemp=this->imag;

    this->real = rtemp*o.Real() - itemp*o.Imag();
    this->imag = rtemp*o.Imag() + itemp*o.Real();
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator *=(const T a) {
    this->real = a*this->real;
    this->imag = a*this->imag;
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator /=(const ff::Complex<T> &o){
    T rtemp=this->real, itemp=this->imag;
    this->real = (this->real)*(o.conj()).Real() - (this->imag)*(o.conj()).Imag();
    this->imag = rtemp*(o.conj()).Imag() + itemp*(o.conj()).Real();
    this->real /= o.abs();
    this->imag /= o.abs();
    return *this;
}

template<class T>
ff::Complex<T> ff::Complex<T>::operator /=(const T a){
    this->real /= a;
    this->imag /= a;
    return *this;
}

template<class T>
bool ff::Complex<T>::operator ==(const ff::Complex<T> &o) const{
    return ((this->real == o.Real()) && (this->imag == o.Imag())); 
}

template<class T>
bool ff::Complex<T>::operator ==(const T a) const{
    if (this->imag == 0) {
        return this->real == a;
    }
    return false;
}

template<class T>
bool ff::Complex<T>::operator !=(const ff::Complex<T> &o) const{
    return ((this->real != o.Real()) || (this->imag != o.Imag())); 
}

template<class T>
bool ff::Complex<T>::operator !=(const T a) const{
    if (this->imag == 0) {
        return this->real != a;
    }
    return false;
}

template<class T>
bool ff::Complex<T>::operator >(const ff::Complex<T> &o) const{
    return this->abs() > o.abs();
}

template<class T>
bool ff::Complex<T>::operator >(const T a) const{
    return this->abs() > a;
}

template<class T>
bool ff::Complex<T>::operator <(const ff::Complex<T> &o) const{
    return this->abs() < o.abs();
}

template<class T>
bool ff::Complex<T>::operator <(const T a) const{
    return this->abs() < a;
}

template<class T>
bool ff::Complex<T>::operator >=(const ff::Complex<T> &o) const{
    return this->abs() >= o.abs();
}

template<class T>
bool ff::Complex<T>::operator >=(const T a) const{
    return this->abs() >= a;
}

template<class T>
bool ff::Complex<T>::operator <=(const ff::Complex<T> &o) const{
    return this->abs() <= o.abs();
}

template<class T>
bool ff::Complex<T>::operator <=(const T a) const {
    return this->abs() <= a;
}

/* methods */

template <class T>
ff::Complex<T> ff::Complex<T>::conj() const {
    ff::Complex<T> ret(this->real,-this->imag);
    return ret;
}

template <class T>
T ff::Complex<T>::abs() const {
    return sqrt( (this->real)*this->real + (this->imag)*this->imag );
}

template <class T>
T ff::Complex<T>::Real() const {
    return this->real;
}

template <class T>
T ff::Complex<T>::Imag() const {
    return this->imag;
}

template <class T>
void ff::Complex<T>::c_print() const {
    std::string sign;
    if (this->Imag() >= 0){
        sign = " + ";
    }
    else {
        sign = "  ";
    }
    std::cout << this->Real() << sign << this->Imag() << "i\n"; 
}

template <class T>
T ff::Complex<T>::angle() const {
    return atan( this->imag / this->real);
}

template <class T> 
std::string ff::Complex<T>::strVal () const {
    std::string buff = "";
    buff += std::to_string(this->real) + (this->imag < 0? " " : " + ") + std::string(this->imag) + "i";
    return buff;
}
template <class T>
ff::Complex<T> ff::Complex<T>::str2complex(const std::string &txt)const {
    T *temp = ff::splitComplex<T>(txt);
    ff::Complex<T> ret(temp[0],temp[1]);
    return temp;
}

typedef ff::Complex<double> doubleComplex;
typedef ff::Complex<int> intComplex;
typedef ff::Complex<int8_t> int8Complex; 
typedef ff::Complex<int16_t> int16Complex; 
typedef ff::Complex<int32_t> int32Complex; 
typedef ff::Complex<int64_t> int64Complex; 
typedef ff::Complex<uint8_t> uint8Complex; 
typedef ff::Complex<uint16_t> uint16Complex; 
typedef ff::Complex<uint32_t> uint32Complex; 
typedef ff::Complex<uint64_t> uint64Complex; 

const doubleComplex i(0,1);
const doubleComplex j(0,1);

#endif 
