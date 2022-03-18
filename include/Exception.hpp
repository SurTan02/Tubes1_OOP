#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>

using namespace std;

class Exception {
    public:
        Exception() {}
        virtual ~Exception() {}
        virtual string what()  = 0;
};


class EmptySourceException : public Exception {
    public:
        EmptySourceException() : Exception() {}
        string what() {
            return "Source slot is empty. Fails to perform operation.\n";
        }
        ~EmptySourceException(){}
};

class FullInventoryException : public Exception {
    public:
        FullInventoryException() : Exception() {}
        string what() {
            return "Inventory is Full. Fails to insert item.\n";
        }
        ~FullInventoryException(){}
};

class DifferentItemTargetException : public Exception {
    public:
        DifferentItemTargetException() : Exception() {}
        string what() {
            return "Target slot currently contains different item. Fails to perform operation.\n";
        }
        ~DifferentItemTargetException() {}
};

class NotEnoughItemException : public Exception {
    public:
        NotEnoughItemException() : Exception() {}
        string what() {
            return "Source slot does not have enough item quantity. Fails to perform operation.\n";
        }
        ~NotEnoughItemException() {}
};

#endif
