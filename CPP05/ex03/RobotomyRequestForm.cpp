#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45) {
    _target = target;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {
    _target = obj._target;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj) {
        _target = obj._target;
    }
    return (*this);
};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->check(executor);
    srand(time(NULL));
    bool success = (std::rand() % 2) == 0;

    std::cout << "Makes some drilling noises." << std::endl;
    if (success) {
        std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
    } else {
        std::cout << "Robotomy failed." << std::endl;
    }
};