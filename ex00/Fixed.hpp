/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:29:52 by aaouni            #+#    #+#             */
/*   Updated: 2023/02/04 04:29:53 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS
#define FIXED_CLASS

#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed & operator =(const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int	_value;
	static const int _fraction = 8;
}; 

#endif 
