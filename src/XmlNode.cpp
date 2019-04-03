#include <algorithm>
#include <cstring>

#include "XmlNode.h"

using namespace ezXml;

#ifdef CXX17
XmlNode::XmlNode(std::string_view name) :
#else
XmlNode::XmlNode(const std::string &name) :
#endif
    _name{ name }
{

}

#ifdef CXX17
std::optional<XmlNode *>
#elif
XmlNode *
#endif
XmlNode::first(std::function<bool (const XmlNode *)> comparer) const
{
    auto it = std::find_if(_children.begin(), _children.end(), comparer);
    return it != _children.end() ?
#ifdef CXX17
    std::optional{ *it } : std::nullopt;
#elif
    *it : nullptr;
#endif
}

#ifdef CXX17
std::optional<XmlNode *>
#elif
XmlNode *
#endif
 XmlNode::first(const char *name) const
{
    return first([name](const XmlNode *node) {
        return !strcmp(name, node->name());
    });
}

