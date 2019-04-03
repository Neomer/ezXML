#include <iostream>

#include <src/XmlNode.h>

int main() {
    ezXml::XmlNode node("test");

    node.append(new ezXml::XmlNode("innerNode1"));
    node.append(new ezXml::XmlNode("innerNode2"));
    node.append(new ezXml::XmlNode("innerNode3"));
    node.append(new ezXml::XmlNode("innerNode4"));

    return 0;
}
