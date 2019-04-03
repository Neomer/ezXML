#include <algorithm>
#include <cstring>

#ifdef DEBUG_
#include <iostream>
#endif

#include "XmlNode.h"

using namespace ezXml;

#ifdef CXX17
XmlNode::XmlNode(std::string_view name) :
#else
XmlNode::XmlNode(const std::string &name) :
#endif
    _name{ name },
    _parent{ nullptr }
{

}

XmlNode::~XmlNode()
{
    if (_parent != nullptr) {
        _parent->onDestroy(this);
    }

    while (_children.begin() != _children.end()) {
        delete *_children.begin();
    }
    while (_attributes.begin() != _attributes.end()) {
        delete *_attributes.begin();
    }
}

void XmlNode::append(XmlNode *node)
{
#ifdef DEBUG_
    std::cout << "XmlNode::append(XmlNode *) - " << node->name() << std::endl;
#endif
    node->_parent = this;
    _children.push_back(node);
}

void XmlNode::insert(NodeList::const_iterator before, XmlNode *node)
{
#ifdef DEBUG_
    std::cout << "XmlNode::insert(NodeList::const_iterator, XmlNode *) - insert "
              << node->name() << "before " << (*before)->name() << std::endl;
#endif
    _children.insert(before, node);
}

void XmlNode::appendAttribute(XmlAttribute *attribute)
{
#ifdef DEBUG_
    std::cout << "XmlNode::appendAttribute(XmlAttribute *) - " << attribute->name() << std::endl;
#endif
    attribute->_node = this;
    _attributes.push_back(attribute);
}

#ifdef CXX17
std::optional<XmlNode *>
#elif
XmlNode *
#endif
XmlNode::first(std::function<bool (const XmlNode *)> comparer) const
{
#ifdef DEBUG_
    std::cout << "XmlNode::first(std::function<bool (const XmlNode *)>)" << std::endl;
#endif
    auto it = std::find_if(_children.begin(), _children.end(), comparer);
#ifdef DEBUG_
    std::cout << "XmlNode::first(std::function<bool (const XmlNode *)>) - result: " << (it != _children.end()) << std::endl;
#endif
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
#ifdef DEBUG_
    std::cout << "XmlNode::where(XmlNode::NodeList &, std::function<bool (const XmlNode *)>)" << std::endl;
#endif
    auto it = std::find_if(_children.begin(), _children.end(), comparer);
    size_t count = 0;
    while (it != _children.end()) {
        nodes.push_back(*it);
        ++count;
        it = std::find_if(++it, _children.end(), comparer);
    }
#ifdef DEBUG_
    std::cout << "found " << count << " value(s)" << std::endl;
#endif
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

void XmlNode::setText(const IStringable *stringable)
{
    stringable->toString(_text);
}

#ifdef CXX17
void XmlNode::setText(std::string_view value)
#else
void XmlNode::setText(const char *value)
#endif
{
#ifdef DEBUG_
    std::cout << "XmlNode::setText() - text changed from" << _text << " to " << value << std::endl;
#endif
    _text = value;
}

void XmlNode::setName(const IStringable *stringable)
{
    stringable->toString(_name);
}
#ifdef CXX17
void XmlNode::setName(std::string_view value)
#else
void XmlNode::setName(const char *value)
#endif
{
#ifdef DEBUG_
    std::cout << "XmlNode::setName() - name changed from " << _name << " to " << value << std::endl;
#endif
    _name = value;
}


void XmlNode::onDestroy(XmlNode *node)
{
#ifdef DEBUG_
    std::cout << "XmlNode::onDestroy(XmlNode *) - " << node->name() << std::endl;
#endif
    _children.erase(std::remove(_children.begin(), _children.end(), node));
}

void XmlNode::onDestroy(XmlAttribute *attribute)
{
#ifdef DEBUG_
    std::cout << "XmlNode::onDestroy(XmlAttribute *) - " << attribute->name() << std::endl;
#endif
    _attributes.erase(std::remove(_attributes.begin(), _attributes.end(), attribute));
}
