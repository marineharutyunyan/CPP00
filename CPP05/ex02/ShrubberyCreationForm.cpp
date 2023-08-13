#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137) {
    _target = target;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) {
    _target = obj._target;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj) {
        _target = obj._target;
    }
    return (*this);
};



void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    this->check(executor);
    std::ofstream outputFile(_target + "_shrubbery.txt");
    if (outputFile.is_open() == false) {
        throw (std::runtime_error("file was not created"));
    }
    outputFile << "ASCII trees" << std::endl;  //TODO
    outputFile.close();
};