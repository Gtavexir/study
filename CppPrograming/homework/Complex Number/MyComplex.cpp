#include "MyComplex.h"
#include <cmath>
// Constructor
myComplex::myComplex(int real, int imag) {
    realPart = real;
    imaginaryPart = imag;
}
// Copy constructor
myComplex::myComplex(const myComplex& number) {
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const {
    return realPart;
}
int myComplex::getImaginaryPart() const {
    return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real) {
    realPart = real;
}
void myComplex::setImaginaryPart(int imag) {
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag) {
    realPart = real;
    imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const {
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator +(int value) const {
    return myComplex(value) + (*this);
}
myComplex operator +(int value, const myComplex& number) {
    return myComplex(value) + number;
}
myComplex myComplex::operator -(const myComplex& number) const {
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex (newReal, newImag);
}
myComplex myComplex::operator -(int value) const {
    return (*this) - myComplex(value);
}
myComplex operator -(int value, const myComplex& number) {
    return myComplex(value) - number;
}
myComplex myComplex::operator *(const myComplex& number) const {
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator *(int value) const {
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    return myComplex(newReal, newImag);
}
myComplex operator *(int value, const myComplex& number) {
    return myComplex(value * number.realPart, value * number.imaginaryPart);
}

// Assignment operators
myComplex& myComplex::operator =(const myComplex& number) {
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value) {
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
myComplex& myComplex::operator +=(const myComplex& number) {
    this->realPart += number.realPart;
    this->imaginaryPart += number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator +=(int value) {
    this->realPart += value;
    return *this;
}
myComplex& myComplex::operator -=(const myComplex& number) {
    this->realPart -= number.realPart;
    this->imaginaryPart -= number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value) {
    this->realPart -= value;
    return *this;
}
myComplex& myComplex::operator *=(const myComplex& number) {
    int newReal = this->realPart * number.realPart - this->imaginaryPart * number.imaginaryPart;
    int newImag = this->realPart * number.imaginaryPart + this->imaginaryPart * number.realPart;
    this->realPart = newReal;
    this->imaginaryPart = newImag;
    return *this;
}
myComplex& myComplex::operator *=(int value) {
    this->realPart *= value;
    this->imaginaryPart *= value;
    return *this;
}
// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const {
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const {
    return !(*this == number);
}
bool myComplex::operator >(const myComplex& number) const {
    return norm() > number.norm();
}
bool myComplex::operator >=(const myComplex& number) const {
    return norm() >= number.norm();
}
bool myComplex::operator <(const myComplex& number) const {
    return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const {
    return norm() <= number.norm();
}
// Overloaded unary operators
myComplex myComplex::operator -() { // unary minus
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~() {
    return myComplex(realPart, -imaginaryPart);
}
myComplex myComplex::operator ++() {
    this->realPart++;
    return *this;
}
myComplex myComplex::operator ++(int) {
    const myComplex temp(*this);
    ++(*this);
    return temp;
}
myComplex myComplex::operator --() {
    this->realPart--;
    return *this;
}
myComplex myComplex::operator --(int) {
    const myComplex temp(*this);
    --(*this);
    return temp;
}
// private function
int myComplex::norm() const {
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream &operator <<(ostream &outStream, const myComplex& number) {
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}
istream &operator >>(istream &inStream, myComplex& number) {
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}

