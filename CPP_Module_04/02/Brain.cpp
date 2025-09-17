#include "Brain.hpp"

Brain::Brain():type("Default"), index(0){
	std::cout << "Brain default constructor called" <<std::endl;
}

Brain::Brain(const std::string type): index(0){
	this->type = type;
	std::cout << "Brain "<< type <<" is created" <<std::endl;

}

Brain::Brain(const Brain &other): type(other.type), index(other.index){
	std::cout << "Brain copy constructor called" <<std::endl;
	for ( int i = 0; i < other.index; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain "<< type <<" is created" <<std::endl;
}

Brain &Brain::operator=(const Brain &other){
	if (this != &other){
		this->index = other.index;
	this->type = other.type;
	for ( int i = 0; i < other.index; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain "<< type <<" is created" <<std::endl;
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain " << type<< " destroyed" <<std::endl;
}

void Brain::setIdea(const std::string idea){
	if (index >= MAX_INDEX){
		std::cout << "The brains" << type << "is full ideas" << std::endl;
		return ;
	}
	ideas[index] = idea;
	++index;
}

void Brain::getIdeas() const {
	if (index == 0){
		std::cout << "The brains " << type << " not have ideas" << std::endl;
		return ;
	}
	std::cout << "Brains " << type << " ideas:" <<std::endl << std::endl;;
	for (int i = 0; i < index; i++)
		std::cout << ideas[i]<< std::endl;
}

