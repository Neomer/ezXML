#ifndef XMLATTRIBUTE_H
#define XMLATTRIBUTE_H

#include "export.h"

#ifdef CXX17
#include <string_view>
#include <optional>
#endif

#include "IStringable.h"

namespace ezXml {

class XmlNode;

class SHARED XmlAttribute
{
    friend class XmlNode;

public:
#ifdef CXX17
    XmlAttribute(std::string_view name);
#else
    XmlAttribute(const char *name);
#endif
    ~XmlAttribute();

    NODISCARD_
    const char *name() const { return _name.c_str(); }

    NODISCARD_
    bool hasValue() const
    {
#ifdef CXX17
    return _value.has_value();
#else
    return !_value.empty();
#endif
    }

    void setValue(const IStringable *stringable);
#ifdef CXX17
    void setValue(std::string_view value);
#else
    void setValue(const char *value);
#endif

    NODISCARD_
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
    XmlNode *_node;
};

}


#endif // XMLATTRIBUTE_H
