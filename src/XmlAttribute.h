#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include "export.h"

#ifdef CXX17
#include <string_view>
#include <optional>
#endif

namespace ezXml {

class SHARED XmlAttribute
{
public:
#ifdef CXX17
    XmlAttribute(std::string_view name);
#else
    XmlAttribute(const char *name);
#endif
    ~XmlAttribute() = default;

    bool hasValue() const
    {
#ifdef CXX17
    return _value.has_value();
#else
    return !_value.empty();
#endif
    }

#ifdef CXX17
    std::optional<const std::string>
#else
    const std::string &
#endif
    value() const { return _value; }

private:
    std::string _name;
#ifdef CXX17
    std::optional<std::string> _value;
#else
    std::string _value;
#endif
};

}


#endif // XMLATTRIBUTE_H
