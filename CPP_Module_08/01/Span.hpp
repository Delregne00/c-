#ifndef SPAN_HPP
#define  SPAN_HPP

#include <iostream>
#include <vector>


class Span{
private:
	std::vector<int> _arr;
	unsigned int	_size;
public:
	Span();
	Span(const Span &other);
	Span(unsigned int size);
	Span &operator=(const Span &otehr);
	~Span();

	class OutOfRangeException : public::std::exception{
		const char *what() const throw();
	};

	class NotFoundNumberException : public::std::exception{
		const char *what() const throw();
	};
	void addNumber(int n);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};


#endif
