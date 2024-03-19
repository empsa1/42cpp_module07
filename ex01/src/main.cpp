#include "../includes/iter.hpp"

class Awesome {
    public:
        Awesome(void ) : _n (42 ) {return; }
        int get(void) const {return this->_n;}
    private:
        int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs)
{
    o << rhs.get();
    return o;
}


int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Int Array: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Double Array: ";
    iter(doubleArray, 5, print<double>);
    std::cout << std::endl;
    
    std::cout << "Char Array: ";
    iter(charArray, 5, print<char>);
    std::cout << std::endl;
    std::cout << GREEN SUCESS RESET << std::endl;
    {
        int tab[] = {0,1,2,3,4};
        Awesome tab2[5];
        iter(tab, 5, print<const int>);
        std::cout << std::endl;
        iter(tab2, 5, print<Awesome>);
        std::cout << std::endl;
    }

    return 0;
}