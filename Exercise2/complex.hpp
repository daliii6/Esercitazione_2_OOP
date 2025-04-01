#pragma once  //protegge l'header dalle doppie inclusioni
#include <iostream>
#include <cmath>

template<typename T> requires std::floating_point<T> //T virgola mobile
class ComplexNumber {
    T real, imag;

public:
    // Costruttore di default
    ComplexNumber() : real(0), imag(0) {}
	
	// explicit impedisce la conversione implicita da T a ComplexNumber<T>
	explicit ComplexNumber(T a){
		real = a;
        imag = 0;
        std::cout << "Il numero complesso " << a << " ha parte immaginaria nulla." << std::endl;
    }
    
    // Costruttore con parametri definiti dall'utente
    ComplexNumber(T r, T i) : real(r), imag(i) {}
    
    /* Metodi per ottenere parte reale e immaginaria: const per non modificare
	l'istanza quando viene chiamata la funzione */
    T getReal() const { 
		return real;
	}
    T getImag() const { 
		return imag;
	}
    
    // Metodo per il coniugato
    ComplexNumber conjugate() const { 
		return ComplexNumber(real, -imag);
	}
    
    /* Operatore += tra numeri complessi: prende in input solo un
	parametro other passato per riferimento costante */
    ComplexNumber& operator+=(const ComplexNumber& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    /* Operatore + tra numeri complessi: definito usando += e prende 
	in input solo un parametro other passato per riferimento costante */
    ComplexNumber operator+(const ComplexNumber& other) const {
        ComplexNumber result = *this; // per non modificare i valori originali
        result += other;
        return result;
    }
    
    // Operatore += tra ComplexNumber a sx e T a dx
    ComplexNumber& operator+=(const T& value) {
        real += value;
        return *this;
    }
    
    // Operatore + tra ComplexNumber e T
    ComplexNumber operator+(const T& value) const {
        ComplexNumber result = *this;
        result += value;
        return result;
    }
    
    // Operatore *= tra numeri complessi
    ComplexNumber& operator*=(const ComplexNumber& other) {
        T r = real * other.real - imag * other.imag;
        T i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }
    
    // Operatore * tra numeri complessi
    ComplexNumber operator*(const ComplexNumber& other) const {
        ComplexNumber result = *this;
        result *= other;
        return result;
    }
    
    // Operatore *= tra ComplexNumber a sx e T a dx
    ComplexNumber& operator*=(const T& value) {
        real *= value;
        imag *= value;
        return *this;
    }
    
    // Operatore * tra ComplexNumber e T
    ComplexNumber operator*(const T& value) const {
        ComplexNumber result = *this;
        result *= value;
        return result;
    }
};

// Overload dell'operatore per stampare
template<typename T>
std::ostream& operator<<(std::ostream& os, const ComplexNumber<T>& c) {
        if (c.getReal() == 0 && c.getImag() == 0){
            os << "0";
        }else if (c.getReal() == 0 && c.getImag() != 0){
            os << c.getImag() << "i";
        }else if (c.getReal() != 0 && c.getImag() == 0){
            os << c.getReal();
        }else if(c.getReal() != 0 && c.getImag() > 0){
        os << c.getReal() << "+" << c.getImag() << "i";
        }else if(c.getReal() != 0 && c.getImag() < 0){
        os << c.getReal() << "-" << -c.getImag() << "i";   
        }
        return os;
}
  
// Operatori + e * tra un numero reale a sx e ComplexNumber a dx
template<typename T, typename U>
ComplexNumber<U> operator+(const T& value, const ComplexNumber<U>& c) {
    return ComplexNumber<U>(static_cast<U>(value) + c.getReal(), c.getImag()); /* per evitare i conflitti di tipi
	static_cast converte nel tipo usato per definire U*/
}

template<typename T, typename U>
ComplexNumber<U> operator*(const T& value, const ComplexNumber<U>& c) {
    return ComplexNumber<U>(static_cast<U>(value) * c.getReal(), static_cast<U>(value) * c.getImag());
}
