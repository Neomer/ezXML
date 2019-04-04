#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H

#include "export.h"

#include <string>

#ifdef CXX17
#include <string_view>
#include <optional>
#endif

#include "XmlNode.h"

namespace ezXml {

class SHARED XmlDocument
{
public:
    XmlDocument();
    XmlDocument(XmlNode *root);
    ~XmlDocument();

    const XmlNode *croot() const { return _root; }
    XmlNode *root() { return _root; }

#ifdef CXX17
    void setVersion(std::string_view value);
#else
    void setVersion(const char *value);
#endif

#ifdef CXX17
    std::optional<std::string_view>
#else
    const char *
#endif
    getVersion() const { return _version; }

private:
    XmlNode *_root;
#ifdef CXX17
    std::optional<std::string>
#else
    std::string
#endif
    _version;

};

}


#endif // XMLDOCUMENT_H
