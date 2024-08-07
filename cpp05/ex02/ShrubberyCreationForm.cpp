#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm ()
 {
 }

 ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm ("ShrubberyCreationForm", 145, 137)
 {
    setTarget(target);
 }

 ShrubberyCreationForm:: ShrubberyCreationForm(const  ShrubberyCreationForm &toCopy) : AForm(toCopy)
{
    // If ShrubberyCreationForm has any additional members not in AForm,
    // initialize them here. Otherwise, leave this empty.
}

 ShrubberyCreationForm &ShrubberyCreationForm::operator=(const  ShrubberyCreationForm &toCopy)
 {
    if (this == &toCopy)
        return (*this);
    AForm::operator=(toCopy); //copy itself 
    return(*this);
}

 ShrubberyCreationForm::~ ShrubberyCreationForm()
 {
 }

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > AForm::getgradeExecReq())
        throw GradeTooLowException();
    if (getIndicator() == false)
        throw FormNotSignedException();
    else
	    {
            std::ofstream File(_target + "_shrubbery");

            File << "                    ___" << std::endl;
            File << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
            File << "             ,-'          __,,-- \\" << std::endl;
            File << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
            File << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
            File << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
            File << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
            File << "     (     ,-'                  `." << std::endl;
            File << "      `._,'     _   _             ;" << std::endl;
            File << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
            File << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
            File << "        `--\'   \"Hb  HH  dF\"" << std::endl;
            File << "                \"Hb HH dF" << std::endl;
            File << "                 \"HbHHdF" << std::endl;
            File << "                  |HHHF" << std::endl;
            File << "                  |HHH|" << std::endl;
            File << "                  |HHH|" << std::endl;
            File << "                  |HHH|" << std::endl;
            File << "                  |HHH|" << std::endl;
            File << "                  dHHHb" << std::endl;
            File << "                .dFd|bHb.               o" << std::endl;
            File << "      o       .dHFdH|HbTHb.          o /" << std::endl;
            File << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
            File << "##########################################" << std::endl;
            File.close();
        }
	
}

