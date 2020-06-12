#pragma once

#include <vector>
#include <algorithm>
#include "node.h"

template <class T>
class binary_tree {
public:
    binary_tree() : tree(nullptr) {}

    explicit binary_tree(Node<T>* node) : tree(node) {}

    explicit binary_tree(const std::vector<T> v) : tree(nullptr) {
        for (const auto item: v) {
            Add_Element(tree, item);
        }
    }

    ~binary_tree() {
        del(tree);
    }

    std::vector<T> klp_tree() {
        return klp_node(tree);
    }

    std::vector<T> kpl_tree() {
        return kpl_node(tree);
    }

    std::vector<T> lpk_tree() {
        return lpk_node(tree);
    }

    std::vector<T> lkp_tree() {
        return lkp_node(tree);
    }

    std::vector<T> plk_tree() {
        return plk_node(tree);
    }

    std::vector<T> pkl_tree() {
        return pkl_node(tree);
    }

    Node<T>* GetNode() {
        return tree;
    }

    void CopyTree(binary_tree* tree_) {
        tree = tree_->GetNode();
    }

    void AddElement(const T& item) {
        Add_Element(tree, item);
    }

    bool SearchElement(const T& item) {
        return Search_Element(tree, item);
    }

    bool DeleteElement(const T item) {
        return Delete_Element(tree, item);
    }

    void BalanceTree() {
        std::vector<T> v = kpl_node(tree);
        std::sort(v.begin(), v.end());
        std::vector<T> v_ = middle_elements(v);
        Node<T>* new_tree = nullptr;
        for (const auto item: v_) {
            Add_Element(new_tree, item);
        }
        del(tree);
        tree = new_tree;
        del(new_tree);
    }

    void Map(T (*f)(T)) {
        Map_node(tree, f);
    }

    void Where(bool (*f)(T)) {
        std::vector<T> v = Where_node(tree, f);
        Node<T>* new_tree = nullptr;
        for (const auto item: v) {
            Add_Element(new_tree, item);
        }
        tree = new_tree;
    }

    T Reduce(T (*f)(T, T), T c) {
        return Reduce_node(tree, f, c);
    }

    binary_tree<T>* SubTree(T new_root) {
        Node<T>* new_node = Sub_Tree(tree, new_root);
        auto new_tree = new binary_tree<T>;
        new_tree->tree = new_node;
        return new_tree;
    }
private:
    Node<T>* tree;
};
