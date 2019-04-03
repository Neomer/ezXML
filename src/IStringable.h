#ifndef ISTRINGABLE_H
#define ISTRINGABLE_H

#include <string>

namespace ezXml {

class IStringable
{
public:
    IStringable() = default;
    virtual ~IStringable() = default;

    virtual void toString(std::string &buffer) const = 0;
};

}


#endif // ISTRINGABLE_H
