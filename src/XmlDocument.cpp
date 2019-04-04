#include "XmlDocument.h"

using namespace ezXml;

XmlDocument::XmlDocument()
{

}

XmlDocument::XmlDocument(XmlNode *root) :
    _root{ root }
{

}

XmlDocument::~XmlDocument()
{
    delete _root;
}


#ifdef CXX17
void XmlDocument::setVersion(std::string_view value)
#else
void XmlDocument::setVersion(const char *value)
#endif
{
    _version = value;
}
