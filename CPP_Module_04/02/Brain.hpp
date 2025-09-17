#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define NB_IDEAS 100
#define MAX_INDEX (NB_IDEAS - 1)

class Brain{
	private:
	std::string ideas[NB_IDEAS];
	std::string type;
	int index;

	public:
	Brain();
	Brain(const std::string type);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void	setIdea(const std::string idea);
	void	getIdeas()const;
};

#endif
