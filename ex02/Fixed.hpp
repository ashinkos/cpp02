/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:14:27 by aaouni            #+#    #+#             */
/*   Updated: 2023/02/04 23:16:11 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	~Fixed();
	Fixed(const Fixed &f);
	Fixed & operator =(const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	
	Fixed operator + (Fixed const &obj);
	Fixed operator - (Fixed const &obj);
	Fixed operator / (Fixed const &obj);
	Fixed operator * (Fixed const &obj);
	
	bool operator==(const Fixed& lhs); 
	bool operator!=(const Fixed& lhs); 
	bool operator< (const Fixed& lhs); 
	bool operator> (const Fixed& lhs);
	bool operator<=(const Fixed& lhs); 
	bool operator>=(const Fixed& lhs); 
	
	// prefiFixed increment
	Fixed& operator++();
    // postfiFixed increment
    Fixed operator++(int);
    
    // prefiFixed decrement
    Fixed& operator--()
    {
        // actual decrement takes place here
        return *this; // return new value by reference
    }
 
    // postfiFixed decrement
    Fixed operator--(int)
    {
        Fixed old = *this; // copy old value
        operator--();  // prefix decrement
        return old;    // return old value
    }

private:
	int	_value;
	static const int _fraction = 8;
}; 

std::ostream& operator << (std::ostream& os ,const Fixed& f);

#endif
