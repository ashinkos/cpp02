/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:30:03 by aaouni            #+#    #+#             */
/*   Updated: 2023/02/04 23:20:03 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_value(0){
	
	std::cout << "Default constructor called" << std::endl;
} 

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
} 

Fixed::Fixed(const int n)
{	
	_value = n << _fraction;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	_value = roundf(f * (1 << _fraction));
	std::cout << "Float constructor called" << std::endl;
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

Fixed Fixed::operator + (Fixed const &obj){
	
	return(Fixed(this->_value + obj._value));
}

bool Fixed::operator> (const Fixed& lhs){
	
	return(this->_value > lhs._value);
}

Fixed& Fixed::operator++(){
    this->_value++;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed old = *this; // copy old value
    operator++();  // prefiFixed increment
    return old;    // return old value
}