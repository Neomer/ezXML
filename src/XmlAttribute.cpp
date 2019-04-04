#include "XmlAttribute.h"

#include "XmlNode.h"

using namespace ezXml;

#ifdef CXX17
XmlAttribute::XmlAttribute(std::string_view name) :
#else
XmlAttribute::XmlAttribute(const char *name) :
#endif
    _name{ name },
    _node{ nullptr }
{

}

XmlAttribute::~XmlAttribute()
{
    if (_node != nullptr) {
        _node->onDestroy(this);
    }
}

void XmlAttribute::setValue(const IStringable *stringable)
{
#ifdef CXX17
    std::string tmp;
    stringable->toString(tmp);
    _value = std::make_optional(tmp);
#else
    stringable->toString(_value);
#endif
}

#ifdef CXX17
void XmlAttribute::setValue(std::string_view value)
#else
void XmlAttribute::setValue(const char *value)
#endif
{
    _value = value;
}

