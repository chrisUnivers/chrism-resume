#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <memory>
#include <iostream>
#include <algorithm>

template <typename T>
class BinaryNode {
private:
    T data;
    std::unique_ptr<BinaryNode<T>> leftChild;
    std::unique_ptr<BinaryNode<T>> rightChild;

    static int getHeightPrivate(const BinaryNode<T>* node) {
        if (!node)
            return 0;
        else
            return 1 + std::max(getHeightPrivate(node->leftChild.get()), getHeightPrivate(node->rightChild.get()));
    }

public:
    BinaryNode() : data() {}
    explicit BinaryNode(const T& dataPortion) : data(dataPortion) {}
    BinaryNode(const T& dataPortion, std::unique_ptr<BinaryNode<T>> newLeftChild, std::unique_ptr<BinaryNode<T>> newRightChild)
        : data(dataPortion), leftChild(std::move(newLeftChild)), rightChild(std::move(newRightChild)) {}
    ~BinaryNode() = default;

    T getData() const {
        return data;
    }

    BinaryNode<T>* getLeftChild() const {
        return leftChild.get();
    }

    BinaryNode<T>* getRightChild() const {
        return rightChild.get();
    }

    void setData(const T& newData) {
        data = newData;
    }
    // set rvalues
    void setLeftChild(std::unique_ptr<BinaryNode<T>> newLeftChild) {
        leftChild = std::move(newLeftChild);
    }
    // set lvalues
    void setLeftChild(BinaryNode<T>* newLeftChild) {
        leftChild = std::unique_ptr<BinaryNode<T>>(newLeftChild);
    }

    void setRightChild(std::unique_ptr<BinaryNode<T>> newRightChild) {
        rightChild = std::move(newLeftChild);
    }

    void setRightChild(BinaryNode<T>* newRightChild) {
        rightChild = std::unique_ptr<BinaryNode<T>>(newLeftChild);
    }

    bool hasLeftChild() const {
        return leftChild != nullptr;
    }

    bool hasRightChild() const {
        return rightChild != nullptr;
    }

    bool isLeaf() const {
        return !leftChild && !rightChild;
    }

    int getNumberOfNodes() const {
        int leftNumber = 0;
        int rightNumber = 0;

        if (leftChild)
            leftNumber = leftChild->getNumberOfNodes();

        if (rightChild)
            rightNumber = rightChild->getNumberOfNodes();

        return 1 + leftNumber + rightNumber;
    }

    int getHeight() const {
        return getHeightPrivate(this);
    }

    std::unique_ptr<BinaryNode<T>> copy() const {
        std::unique_ptr<BinaryNode<T>> newRoot = std::make_unique<BinaryNode<T>>(data);
        if (leftChild)
            newRoot->setLeftChild(leftChild->copy());
        if (rightChild)
            newRoot->setRightChild(rightChild->copy());
        return newRoot;
    }
};

#endif // BINARYNODE_H