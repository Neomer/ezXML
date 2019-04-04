#include <iostream>

#include <src/XmlNode.h>

int main() {
    {
        ezXml::XmlNode node("test");
        { // Bad idea!
            ezXml::XmlNode innerNode("innerWeakNode");
            node.append(&innerNode);
            ezXml::XmlAttribute innerAttr("attr");
            node.appendAttribute(&innerAttr);
        }
        auto child = node.first("innerWeakNode");
        if (child) {
            std::cout << child.value()->name() << std::endl;
        } else {
            std::cout << "not found!" << std::endl;
        }
        node.setText("New XML Text");
        node.setName("NewName");
        ezXml::XmlAttribute attr("some_attribute");
        node.appendAttribute(&attr);
        std::cout << attr.value().value() << std::endl;
    }
    std::cout << "The end!" << std::endl;
    return 0;
}
