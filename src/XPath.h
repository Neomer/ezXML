#ifndef XPATH_H
#define XPATH_H

#include "export.h"

#ifdef CXX17
#include <string_view>
#include <optional>
#endif

namespace ezXml {

class SHARED XPath
{
public:
#ifdef CXX17
    XPath(std::string_view xpath);
#else
    XPath(const char *xpath);
#endif
};

}


#endif // XPATH_H
