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
            return "Source slot is empty. Fail to perform operation.\n\n";
        }
        ~EmptySourceException(){}
};

class FullInventoryException : public Exception {
    public:
        FullInventoryException() : Exception() {}
        string what() {
            return "Destination is Full. Fail to perform operation.\n\n";
        }
        ~FullInventoryException(){}
};

class DifferentItemTargetException : public Exception {
    public:
        DifferentItemTargetException() : Exception() {}
        string what() {
            return "Target slot currently contains different item. Fail to perform operation.\n\n";
        }
        ~DifferentItemTargetException() {}
};

class NotEnoughItemException : public Exception {
    public:
        NotEnoughItemException() : Exception() {}
        string what() {
            return "Source slot does not have enough item quantity. Fail to perform operation.\n\n";
        }
        ~NotEnoughItemException() {}
};

class InvalidQuantityException : public Exception {
    public:
        InvalidQuantityException() : Exception() {}
        string what() {
            return "Item quantity is invalid. Fail to perform operation.\n\n";
        }
        ~InvalidQuantityException() {}
};

class FailedCraftException : public Exception {
    public:
        FailedCraftException() : Exception() {}
        string what() {
            return "Crafting table does not match any recipe. Fail to perform operation.\n\n";
        }
};

#endif
