#include "MultiplTree.h"

/**
 * @brief Main function of the XML Editor.
 *
 * This function handles the command-line interface for the XML Editor.
 * It provides a simple text-based interface for users to interact with the XML files.
 *
 * @return 0 on successful execution.
 */
int main() {
    MultiplTree* tree = nullptr; ///< Pointer to the root of the XML tree.
    std::string currentDir = ""; ///< Current directory in the XML tree.

    while (true) {
        std::cout << "XML Editor > " << currentDir << " > ";
        std::string command;
        std::cin >> command;

        // List subdirectories or nodes
        if (command == "ls") {
            if (tree) {
                for (int i = 0; i < tree->getCountSub(); i++) {
                    std::cout << tree->getSub(i)->getName() << std::endl;
                }
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Change directory
        else if (command == "cd") {
            std::string dir;
            std::cin >> dir;
            if (tree) {
                MultiplTree* node = tree->getSub(dir);
                if (node) {
                    tree = node;
                    currentDir += "/" + dir;
                } else {
                    std::cout << "Directory not found." << std::endl;
                }
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Edit node value
        else if (command == "edit") {
            std::string name;
            std::cin >> name;
            if (tree) {
                MultiplTree* node = tree->getSub(name);
                if (node) {
                    std::string value;
                    std::cin >> value;
                    node->setValue(value);
                } else {
                    std::cout << "Node not found." << std::endl;
                }
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Save XML tree to a file
        else if (command == "save") {
            if (tree) {
                tree->save("output.xml");
                std::cout << "File saved." << std::endl;
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Save XML tree to a specified file
        else if (command == "save_file") {
            std::string filename;
            std::cin >> filename;
            if (tree) {
                tree->save(filename);
                std::cout << "File saved." << std::endl;
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Delete a node
        else if (command == "delete") {
            std::string name;
            std::cin >> name;
            if (tree) {
                MultiplTree* node = tree->getSub(name);
                if (node) {
                    tree->subNodes_.erase(remove(tree->subNodes_.begin(), tree->subNodes_.end(), *node), tree->subNodes_.end());
                    std::cout << "Node deleted." << std::endl;
                } else {
                    std::cout << "Node not found." << std::endl;
                }
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Add a new node
        else if (command == "add") {
            std::string name;
            std::cin >> name;
            if (tree) {
                MultiplTree* node = new MultiplTree(name);
                tree->addSub(*node);
                std::cout << "Node added." << std::endl;
            } else {
                std::cout << "No file loaded." << std::endl;
            }
        } 
        // Load XML file into the tree
        else if (command == "load") {
            std::string filename;
            std::cin >> filename;
            tree = MultiplTree::load(filename);
            currentDir = "";
            std::cout << "File loaded." << std::endl;
        } 
        // Exit the program
        else if (command == "exit") {
            break;
        } 
        // Unknown command
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}