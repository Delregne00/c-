#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd>

class Fixed
{
	private:
		int	value;
		static const int FractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator =(const Fixed &other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		int		getRawBits()const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
