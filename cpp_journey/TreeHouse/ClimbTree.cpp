// main.cpp
#include "BinaryNode.h"
#include <iostream>
#include <string>

int main() {
    std::string arrTree[] = {"A", "B", "C", "D", "E", "F", "G"};

    std::unique_ptr<BinaryNode<std::string>> nodeA = std::make_unique<BinaryNode<std::string>>(arrTree[0]);
    std::unique_ptr<BinaryNode<std::string>> nodeB = std::make_unique<BinaryNode<std::string>>(arrTree[1]);
    std::unique_ptr<BinaryNode<std::string>> nodeC = std::make_unique<BinaryNode<std::string>>(arrTree[2]);
    std::unique_ptr<BinaryNode<std::string>> nodeD = std::make_unique<BinaryNode<std::string>>(arrTree[3]);
    std::unique_ptr<BinaryNode<std::string>> nodeE = std::make_unique<BinaryNode<std::string>>(arrTree[4]);
    std::unique_ptr<BinaryNode<std::string>> nodeF = std::make_unique<BinaryNode<std::string>>(arrTree[5]);
    std::unique_ptr<BinaryNode<std::string>> nodeG = std::make_unique<BinaryNode<std::string>>(arrTree[6]);

    nodeA->setLeftChild(std::move(nodeB)); 
    nodeA->setRightChild(std::move(nodeC));

    nodeA->getLeftChild()->setLeftChild(std::move(nodeD));
    nodeA->getLeftChild()->setRightChild(std::move(nodeE));
    nodeA->getRightChild()->setLeftChild(std::move(nodeF));
    nodeA->getRightChild()->getLeftChild()->setRightChild(std::move(nodeG));

    std::cout << "Running Code" << std::endl;
    std::cout << "Node B's right child: " << nodeA->getLeftChild()->getRightChild()->getData() << std::endl;

    return 0;
}