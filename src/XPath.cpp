#include "XPath.h"

using namespace ezXml;

#ifdef CXX17
XPath::XPath(std::string_view xpath)
#else
XPath::XPath(const char *xpath)
#endif
{

}
