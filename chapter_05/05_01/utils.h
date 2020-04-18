#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

struct Title
{
    std::string begining;
    std::string end;
};

bool compare (const Title&, const Title&);
std::string::size_type max_begining_for (const std::vector<Title>&);

#endif