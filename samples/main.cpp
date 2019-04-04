#include <iostream>

#include <src/XmlDocument.h>
#include <src/XmlNode.h>

int main() {
    ezXml::XmlNode node("test");

    ezXml::XmlAttribute attr("some_attribute");
    node.appendAttribute(&attr);

    ezXml::XmlDocument doc(&node);
    doc.setVersion("1.1");

    std::cout << "The end!" << std::endl;
    return 0;
}
