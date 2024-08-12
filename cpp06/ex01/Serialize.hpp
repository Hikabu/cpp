#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>

struct Data{
    std::string s1;
    std::string s2;
    int i;
}

class Serialize{
    private:
        Serialize ();
        Serialize (const Serialize  &toCopy);
        Serialize  &operator=(const Serialize  &value);
        ~Serialize ();

    public:
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);

};

#endif
