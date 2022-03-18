#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>

using namespace std;

class Exception {
    public:
        Exception() {}
        Exception(const Exception& e) {}
        Exception& operator= (const Exception&) {}
        virtual ~Exception() {}
        virtual string what() = 0 const;
};

class EmptySourceException : public Exception {
    public:
        EmptySlotException() : Exception() {}
        string what() {
            return "Source slot is empty. Fails to perform operation.\n";
        }
};

class DifferentItemTargetException : public Exception {
    public:
        DifferentItemTargetException() : Exception() {}
        string what() {
            return "Target slot currently contains different item. Fails to perform operation.\n";
        }
};

#endif
