/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:29:49 by aaouni            #+#    #+#             */
/*   Updated: 2023/02/04 04:29:50 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_value(0){
	
	std::cout << "Default constructor called" << std::endl;
} 

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
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
// const int Fixed::fraction = 8;