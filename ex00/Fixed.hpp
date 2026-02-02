#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int					_value;
		static const int	_fbits;

	public:
		Fixed();
		//Fixed(const int value);
		//Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif