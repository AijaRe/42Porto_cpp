#include <iostream>
#include <string>

//noexcept specifier - what() will not throw an exception
//this function helps to define exception nype, not throw it
class   CustomException : public std::exception{
    virtual const char * what() const noexcept{
        return "My custom error...";
    }
};

//this function may throw something
class CustomExceptionThrow : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "This is a custom exception that will throw!";
        }
};

void    errorFunction()
{
    std::cout << "My very special error message.." << std::endl;
    throw CustomExceptionThrow();
}

int main()
{
    std::string word = "test";

    try {
        //std::cout << word.at(4) << std::endl;
        //int *array = new int[99999999999];
        //(void)array;
        //throw std::exception();
        //throw CustomException();
        errorFunction();
    } catch (std::out_of_range &e){
        std::cout << "Out of range exception: " << e.what() << std::endl;
    } catch (std::bad_alloc& e){
        std::cout << "Bad alloc exception: " << e.what() << std::endl;
    } catch (CustomExceptionThrow& e){
        std::cout << "CustomExceptionThrow caught: " << e.what() << std::endl;
    } catch (std::exception& e){ //generic catch
        std::cout << "Exception thrown: " << e.what() << std::endl;
    } catch(...){ //not cool, avoid using, deal with types of errors instead
        std::cout << "Default catch case" << std::endl;
    }

    return 0;
}
