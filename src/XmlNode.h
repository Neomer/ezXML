#ifndef XMLNODE_H
#define XMLNODE_H

#include "export.h"
#include <deque>
#include <functional>
#include <string>

#ifdef CXX17
#include <string_view>
#include <optional>
#endif

#include "XmlAttribute.h"

namespace ezXml {

class XmlNode
{
public:
    using NodeList = std::deque<XmlNode *>;
    using AttributeList = std::deque<XmlAttribute *>;

    const char *name() const { return _name.c_str(); }
    const char *text() const { return _text.c_str(); }

#ifdef CXX17
    XmlNode(std::string_view name);
#else
    XmlNode(const std::string &name);
#endif

    inline const NodeList &children() const { return _children; }
    inline const AttributeList &attributes() const { return _attributes; }

#ifdef CXX17
    std::optional<XmlNode *>
#else
    XmlNode *
#endif
    first(std::function<bool(const XmlNode *node)> comparer) const;

#ifdef CXX17
    std::optional<XmlNode *>
#else
    XmlNode *
#endif
    first(const char *name) const;

private:
    std::string _name, _text;
    NodeList _children;
    AttributeList _attributes;
};

}

#endif // XMLNODE_H
