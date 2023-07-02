#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*MemFuncPtr)();
	int i;
	std::string complainsStr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	MemFuncPtr complains[5]  = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::unknwon};
	for(i = 0; complainsStr[i] != level && i < 4; i++);
	(this->*complains[i])();
}

void	Harl::unknwon()
{
	std::cout << "Probably complaining about insignificant problems" << std::endl;
}

void	Harl::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pic"
		"kle-special-ketchup burger. I just love it!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’"
		"t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve bee"
		"n coming here for years and you just started working here last month."
		<< std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}