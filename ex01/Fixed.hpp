/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:14:27 by aaouni            #+#    #+#             */
/*   Updated: 2023/02/04 21:14:28 by aaouni           ###   ########.fr       */
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

private:
	int	_value;
	static const int _fraction = 8;
}; 

std::ostream& operator << (std::ostream& os ,const Fixed& f);

#endif
