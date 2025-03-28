#include<iostream>
#include<complex>
#define STACK_SIZE_8

using namespace std;

//7: T vincolata ad essere di tipo floating point
template<typename T> //requires floating_point<T>
class complex_number{
	
	T real;
	T imag;
	

	
public:
	//1: costruttore di default
	complex_number() : real(0), imag(0)
	{}
	
	//2: costruttore user-defined per l'inizializzazione di parte reale e immaginaria
	complex_number(T r = 0, T i = 0) : real(r), imag(i)
	{}
	
	//3: metodi che restituiscono parte reale, immaginaria e coniugato
	//parte reale
	T reale(void) const{
		return real;
	}
	
	//parte immaginaria
	T immaginaria(void) const{
		return imag;
	}
	
	//coniugato
	complex_number coniugato(void) const{
		return complex_number(real, -imag);
	}
	
	//5: overload degli operatori += e +
	complex_number& operator+=(const complex_number& other){
		T a = real;
		T b = imag;
		T c = other.real;
		T d = other.imag;
		real = a+c;
		imag = d+b;
		return *this;
	}
	
	complex_number& operator+(const complex_number& other) const{
		complex_number sum = *this;
        sum += other;
        return sum;
	}
	
	//6: overload degli operatori *= e *
	complex_number& operator*=(const complex_number& other){
		T a = real;
		T b = imag;
		T c = other.real;
		T d = other.imag;
		real = a*c - b*d;
		imag = a*d + b*c;
		return *this;
	}
	
	complex_number& operator*(const complex_number& other) const{
		complex_number prod = *this;
		prod *= other;
		return prod;
	}
};

//commutatività degli operatori + e *
template<typename T>
complex_number<T>
operator+(const T& i, const complex_number<T>& r)
{
    return r + i;
}

template<typename T>
complex_number<T>
operator*(const T& i, const complex_number<T>& r)
{
    return r * i;
}


//4: overload dell'operatore <<
template<typename T>
ostream& operator<<(ostream& os, const complex_number<T>& c){
	os << c.real;
	if (c.imag >= 0)
		os << "+" << c.imag << "i";
	else
		os << c.imag << "i";
	
	return os;
}


int main()
{
	return 0;
}