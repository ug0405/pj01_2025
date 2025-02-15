// include/sample.h
#ifndef SAMPLE_H
#define SAMPLE_H

#include <string>

class Sample
{
public:
    int add(int a, int b);
    std::string concatenate(const std::string &str1, const std::string &str2);
};

#endif // SAMPLE_H
