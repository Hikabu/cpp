#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
//  the conversion doesn't depend on any instance-specific data
//  i need to  prevent instantiation of the class.


class ScalarConverter{
    private: //to prevent instantiation 
        ScalarConverter ();
        ScalarConverter (std::string av);
        ScalarConverter (const ScalarConverter  &toCopy);
        ScalarConverter  &operator=(const ScalarConverter  &value);
        ~ScalarConverter ();

        static int  _count;
        static int  _dot;
        static int  _float;
        //

        std::string _av;


    public:
        static void convert (const std::string &input);
        static int  forNumber (const std::string &digit);

        class OutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
	                return ("it is out of range...");
                }
        };
};

#endif
