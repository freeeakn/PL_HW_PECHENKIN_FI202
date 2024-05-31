#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class MultiplTree {
private:
  /**
   * Private method to recursively generate an XML string representation of a
   * MultiplTree node.
   *
   * @param node The MultiplTree node to convert to XML.
   * @param xml A reference to the string where the XML representation will be
   * stored.
   * @post The XML representation of the node and its subnodes is appended to
   * the xml string.
   *
   * This method is a helper function for the toXML() method. It recursively
   * generates an XML string representation of a MultiplTree node and its
   * subnodes. The XML string is appended to the xml string passed as a
   * reference.
   *
   * The XML representation follows the format:
   * <node name="nodeName">value</node>
   * If the node has subnodes, the method is called recursively for each
   * subnode.
   *
   * Note: This method assumes that the MultiplTree node and its subnodes are
   * valid.
   */
  void toXML(const MultiplTree *node, std::string &xml) const {
    xml += "<node name=\"";
    xml += node->getName();
    xml += "\">";
    if (!node->getValue().empty()) {
      xml += node->getValue();
    }
    for (const auto &subNode : node->subNodes_) {
      toXML(&subNode, xml);
    }
    xml += "</node>";
  }

  std::string name_;
  std::string value_;
  std::vector<MultiplTree> subNodes_;

public:
  /**
   * Constructor for MultiplTree class.
   *
   * @param name The name of the tree node.
   * @post The tree node is created with the given name and an empty value.
   */
  MultiplTree(const std::string &name) : name_(name), value_() {}

  void setName(const std::string &name) { name_ = name; }
  std::string getName() const { return name_; }

  void setValue(const std::string &value) { value_ = value; }
  void setValue(double value) { value_ = std::to_string(value); }
  void setValue(int value) { value_ = std::to_string(value); }

  std::string getValue() const { return value_; }

  bool isInt() const {
    try {
      std::stoi(value_);
      return true;
    } catch (const std::invalid_argument &) {
      return false;
    }
  }

  bool isDouble() const {
    try {
      std::stod(value_);
      return true;
    } catch (const std::invalid_argument &) {
      return false;
    }
  }

  int getInt() const {
    if (isInt()) {
      return std::stoi(value_);
    } else {
      return 0;
    }
  }

  double getDouble() const {
    if (isDouble()) {
      return std::stod(value_);
    } else {
      return 0.0;
    }
  }

  int getCountSub() const { return subNodes_.size(); }

  MultiplTree *getSub(int i) {
    if (i < subNodes_.size()) {
      return &subNodes_[i];
    } else {
      return nullptr;
    }
  }

  MultiplTree *getSub(const std::string &name) {
    for (auto &node : subNodes_) {
      if (node.getName() == name) {
        return &node;
      }
    }
    return nullptr;
  }

  void addSub(MultiplTree node) { subNodes_.push_back(node); }

  /**
   * Static method to find a node in the tree by its name.
   *
   * @param tree The root of the tree to search in.
   * @param name The name of the node to find.
   * @return A pointer to the found node, or nullptr if the node is not found.
   *
   * This method recursively searches the tree for a node with the given name.
   * It compares the name of each node with the given name and returns a pointer
   * to the first node with a matching name. If no matching node is found, it
   * returns nullptr.
   *
   * Note: This method assumes that the tree does not contain duplicate node
   * names.
   */
  static MultiplTree *findNode(MultiplTree *tree, const std::string &name) {
    if (tree->getName() == name) {
      return tree;
    } else {
      for (auto &node : tree->subNodes_) {
        MultiplTree *found = findNode(&node, name);
        if (found != nullptr) {
          return found;
        }
      }
      return nullptr;
    }
  }

  /**
   * Static method to parse an XML string and create a MultiplTree object.
   *
   * @param xml The XML string to parse.
   * @return A pointer to the root of the created MultiplTree object.
   *
   * This method parses the given XML string and creates a MultiplTree object
   * representing the XML structure. The XML string should be well-formed and
   * contain valid node names and values.
   *
   * The method uses a simple parsing algorithm that iterates through the XML
   * string and extracts node names and values. It creates MultiplTree objects
   * for each node and adds them to the parent node's subNodes vector.
   *
   * Note: The method currently does not handle nested nodes or attributes.
   *
   * Note: The method uses dynamic memory allocation to create MultiplTree
   * objects. It is the responsibility of the caller to delete the returned
   * MultiplTree object and its subnodes to avoid memory leaks.
   */
  static MultiplTree *parseXML(const std::string &xml) {
    // TODO: implement XML parsing
    MultiplTree *root = new MultiplTree("root");
    size_t pos = 0;
    while (pos < xml.size()) {
      size_t nodeNameStart = xml.find("<node", pos);
      if (nodeNameStart == std::string::npos) {
        break;
      }
      size_t nodeNameEnd = xml.find(">", nodeNameStart);
      std::string nodeName =
          xml.substr(nodeNameStart + 5, nodeNameEnd - nodeNameStart - 5);
      size_t valueStart = xml.find(">", nodeNameEnd);
      size_t valueEnd = xml.find("</node", valueStart);
      std::string value = xml.substr(valueStart + 1, valueEnd - valueStart - 1);
      MultiplTree *node = new MultiplTree(nodeName);
      node->setValue(value);
      root->addSub(*node);
      pos = valueEnd;
    }
    return root;
  }

  std::string toXML() const {
    std::string xml;
    toXML(this, xml);
    return xml;
  }
  void save(const std::string &filename) {
    std::ofstream file(filename);
    file << toXML();
    file.close();
  }

  static MultiplTree *load(const std::string &filename) {
    std::ifstream file(filename);
    std::string xml(std::istream_iterator<char>(file),
                    std::istream_iterator<char>());
    file.close();
    return parseXML(xml);
  }
};