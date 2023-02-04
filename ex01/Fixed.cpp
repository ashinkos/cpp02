#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed():_value(0){
	
	std::cout << "Default constructor called" << std::endl;
} 

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
} 
Fixed::Fixed(const int n)
{	
	_value = n << _fraction;
}

Fixed::Fixed(const float f)
{
	_value = roundf(f * (1 << _fraction));
}


Fixed::Fixed(const Fixed &f){
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
} 

Fixed & Fixed::operator =(const Fixed &f){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &f)
	{ 
		_value = f.getRawBits();
	} 
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return(_value);
}

void Fixed::setRawBits( int const raw ){
	_value = raw;
}

int Fixed::toInt( void ) const{
	return(_value >> _fraction);
}

float Fixed::toFloat( void ) const{
	return((float) _value / (1 << _fraction));
}

std::ostream& operator << (std::ostream& os , const Fixed& f){
	os << f.toFloat();
	return(os);
}

