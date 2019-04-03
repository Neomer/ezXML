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

