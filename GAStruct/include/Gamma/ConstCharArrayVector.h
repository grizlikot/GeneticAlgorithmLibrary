//
// Created by Deiwid on 2017-03-11.
//

#ifndef GAMMA_CONSTCHARARRAYVECTOR_H
#define GAMMA_CONSTCHARARRAYVECTOR_H


#include <vector>
#include <string>

class ConstCharArrayVector {
private:
    char** arr = nullptr;
    unsigned long long int sz = 0;
    std::vector<unsigned long long int> szs;
    void alloc(unsigned long long int size);
    void realloc(unsigned long long int newSize);
    void destroy();
public:
    ConstCharArrayVector(unsigned long long int size=0);
    ConstCharArrayVector(const std::vector<std::string> &other);
    void push_back(const std::string &str);
    void assign(const std::string str, unsigned long long int index);
    unsigned long long int size();
    bool empty();
    const char* operator[](unsigned long long int index);
    operator const char**();
    ConstCharArrayVector& operator=(const std::vector<std::string> &other);
    virtual ~ConstCharArrayVector();
};


#endif //GAMMA_CONSTCHARARRAYVECTOR_H
