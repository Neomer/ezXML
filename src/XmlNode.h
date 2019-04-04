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
#include "IStringable.h"

namespace ezXml {

/**
 * @brief
 */
class SHARED XmlNode
{
    friend class XmlAttribute;

public:
    using NodeList = std::deque<XmlNode *>;
    using AttributeList = std::deque<XmlAttribute *>;

    NODISCARD_
    const char *name() const { return _name.c_str(); }
    NODISCARD_
    const char *text() const { return _text.c_str(); }

#ifdef CXX17
    XmlNode(std::string_view name);
#else
    XmlNode(const std::string &name);
#endif
    ~XmlNode();

    NODISCARD_
    inline bool anyChild() const { return _children.size(); }

    NODISCARD_
    inline bool anyAttribute() const { return _attributes.size(); }

    NODISCARD_
    inline const NodeList &children() const { return _children; }

    NODISCARD_
    inline const AttributeList &attributes() const { return _attributes; }

    void append(XmlNode *node);
    void insert(NodeList::const_iterator before, XmlNode *node);

    void appendAttribute(XmlAttribute *attribute);

    [[nodiscard]]
#ifdef CXX17
    std::optional<XmlNode *>
#else
    XmlNode *
#endif
    first(std::function<bool(const XmlNode *node)> comparer) const;

    NODISCARD_
#ifdef CXX17
    std::optional<XmlNode *>
#else
    XmlNode *
#endif
    first(const char *name) const;

    size_t where(NodeList &nodes, std::function<bool(const XmlNode *node)> comparer) const;
#ifdef CXX17
    size_t where(NodeList &nodes, std::string_view name) const;
#else
    size_t where(NodeList &nodes, const char *name) const;
#endif

    void setText(const IStringable *stringable);
#ifdef CXX17
    void setText(std::string_view value);
#else
    void setText(const char *value);
#endif

    void setName(const IStringable *stringable);
#ifdef CXX17
    void setName(std::string_view value);
#else
    void setName(const char *value);
#endif

private:
    std::string _name, _text;
    NodeList _children;
    AttributeList _attributes;

private:
    XmlNode *_parent;
    void onDestroy(XmlNode *node);
    void onDestroy(XmlAttribute *attribute);
};

}

#endif // XMLNODE_H
