/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:30:03 by aaouni            #+#    #+#             */
/*   Updated: 2023/02/05 22:57:35 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_value(0){
	
	// std::cout << "Default constructor called" << std::endl;
} 

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
} 

Fixed::Fixed(const int n)
{	
	// std::cout << "Int constructor called" << std::endl;
	_value = n << _fraction;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fraction));
}

Fixed::Fixed(const Fixed &f){
	// std::cout << "Copy constructor called" << std::endl;
	*this = f;
} 

Fixed & Fixed::operator =(const Fixed &f){
	// std::cout << "Copy assignment operator called" << std::endl;
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

Fixed Fixed::operator+(const Fixed& obj) const{
	return(Fixed(this->_value + obj._value));
}

Fixed Fixed::operator-(const Fixed& obj)const{
	return(Fixed(this->_value - obj._value));
}

Fixed Fixed::operator*(const Fixed& obj)const{
	Fixed mult;
	mult.setRawBits((_value * obj._value)  >> _fraction);
	return (mult);
}

Fixed Fixed::operator/(const Fixed& obj)const{
	Fixed fract;
	fract.setRawBits(((float)(_value) / obj._value) * (1 << _fraction) );
	return (fract);
}

bool Fixed::operator>(const Fixed& obj)const{
	
	return(this->_value > obj._value);
}

bool Fixed::operator<(const Fixed& obj)const{
	
	return(this->_value < obj._value);
}

bool Fixed::operator==(const Fixed& obj)const {
	
	return(!operator>(obj) && !operator<(obj));
}

bool Fixed::operator!=(const Fixed& obj)const {
	
	return(!operator==(obj));
}

bool Fixed::operator>=(const Fixed& obj) const{
	
	return(operator>(obj) || operator==(obj));
}

bool Fixed::operator<=(const Fixed& obj) const{
	
	return(operator<(obj) || operator==(obj));
}

Fixed& Fixed::operator++(){
    this->_value++;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed old = *this; 
    operator++();  
    return old;
}

Fixed& Fixed::operator--()
{
    this->_value--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed old = *this; 
    operator--();  
    return old;
}

Fixed & Fixed::min(Fixed &a, Fixed &b){
	return (a < b) ? a : b;
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b){
	return (a > b) ? a : b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}