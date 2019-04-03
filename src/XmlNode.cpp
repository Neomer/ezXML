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

XmlNode::~XmlNode()
{
    while (_children.begin() != _children.end()) {
        delete *_children.begin();
    }
    while (_attributes.begin() != _attributes.end()) {
        delete *_attributes.begin();
    }
}

void XmlNode::append(XmlNode *node)
{
    _children.push_back(node);
}

void XmlNode::insert(NodeList::const_iterator before, XmlNode *node)
{
    _children.insert(before, node);
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

size_t XmlNode::where(XmlNode::NodeList &nodes, std::function<bool (const XmlNode *)> comparer) const
{
    auto it = std::find_if(_children.begin(), _children.end(), comparer);
    size_t count = 0;
    while (it != _children.end()) {
        nodes.push_back(*it);
        ++count;
        it = std::find_if(++it, _children.end(), comparer);
    }
    return count;
}

#ifdef CXX17
size_t XmlNode::where(XmlNode::NodeList &nodes, std::string_view name) const
{
    return where(nodes, [name](const XmlNode *node) {
        return node->name() == name;
    });
}
#else
size_t XmlNode::where(NodeList &nodes, const char *name) const
{
    return all(nodes, [name](const XmlNode *node) {
        return !strcmp(name, node->name());
    });
}
#endif
