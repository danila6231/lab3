#pragma once

#include <vector>

template <class T>
struct Node {
    T data;
    Node* r;
    Node* l;
};

template <class T>
std::vector<T> klp_node(Node<T>*& node) {
    std::vector<int> result = {};
    if (node != nullptr) {
        std::vector<T> vl = klp_node(node->l);
        std::vector<T> vr = klp_node(node->r);
        result.push_back(node->data);
        result.insert(result.end(), vl.begin(), vl.end());
        result.insert(result.end(), vr.begin(), vr.end());
    }
    return result;
}

template <class T>
std::vector<T> kpl_node(Node<T> *&node) {
    std::vector<int> result = {};
    if (node != nullptr) {
        std::vector<T> vl = kpl_node(node->l);
        std::vector<T> vr = kpl_node(node->r);
        result.push_back(node->data);
        result.insert(result.end(), vr.begin(), vr.end());
        result.insert(result.end(), vl.begin(), vl.end());
    }
    return result;
}

template <class T>
std::vector<T> lkp_node(Node<T> *&node) {
    std::vector<int> result = {};
    if (node != nullptr) {
        std::vector<T> vl = lkp_node(node->l);
        std::vector<T> vr = lkp_node(node->r);
        result.insert(result.end(), vl.begin(), vl.end());
        result.push_back(node->data);
        result.insert(result.end(), vr.begin(), vr.end());
    }
    return result;
}

template <class T>
std::vector<T> lpk_node(Node<T> *&node) {
    std::vector<int> result = {};
    if (node != nullptr) {
        std::vector<T> vl = lpk_node(node->l);
        std::vector<T> vr = lpk_node(node->r);
        result.insert(result.end(), vl.begin(), vl.end());
        result.insert(result.end(), vr.begin(), vr.end());
        result.push_back(node->data);
    }
    return result;
}

template <class T>
std::vector<T> plk_node(Node<T> *&node) {
    std::vector<int> result = {};
    if (node != nullptr) {
        std::vector<T> vl = plk_node(node->l);
        std::vector<T> vr = plk_node(node->r);
        result.insert(result.end(), vr.begin(), vr.end());
        result.insert(result.end(), vl.begin(), vl.end());
        result.push_back(node->data);
    }
    return result;
}

template <class T>
std::vector<T> pkl_node(Node<T> *&node) {
    std::vector<int> result = {};
    if (node != nullptr) {
        std::vector<T> vl = pkl_node(node->l);
        std::vector<T> vr = pkl_node(node->r);
        result.insert(result.end(), vr.begin(), vr.end());
        result.push_back(node->data);
        result.insert(result.end(), vl.begin(), vl.end());
    }
    return result;
}

template <class T>
void Add_Element(Node<T> *&node, T item) {
    if (node == nullptr) {
        node = new Node<T>;
        node->data = item;
        node->l = nullptr;
        node->r = nullptr;
    }
    else if (item < node->data) {
        if (node->l != nullptr) Add_Element(node->l, item);
        else {
            node->l = new Node<T>;
            node->l->l = nullptr;
            node->l->r = nullptr;
            node->l->data = item;
        }
    }
    else if (item > node->data) {
        if (node->r != nullptr) Add_Element(node->r, item);
        else {
            node->r = new Node<T>;
            node->r->l = nullptr;
            node->r->r = nullptr;
            node->r->data = item;
        }
    }
}

template <class T>
bool Search_Element(Node<T> *&node, T item) {
    bool result = false;
    if (node != nullptr) {
        if (node->data == item) {
            result = true;
        }
        else {
            if (item < node->data) {
                result = Search_Element(node->l, item);
            }
            else if (item > node->data) {
                result = Search_Element(node->r, item);
            }
        }
    }
    return result;
}

template <class T>
bool Delete_Element(Node<T> *&node, T item) {
    bool flag = false;
    if (node != nullptr) {
        if (node->l != nullptr or node->r != nullptr) {
            if ((node->l != nullptr) and (node->l->data == item)) {
                flag = true;
                std::vector<T> v = kpl_node(node->l);
                if (v.size() > 0) {
                    v.erase(v.begin());
                }
                node->l = nullptr;
                for (auto item_: v) {
                    Add_Element(node, item_);
                }
            }
            else if ((node->r != nullptr) and (node->r->data == item)) {
                flag = true;
                std::vector<T> v = kpl_node(node->r);
                if (v.size() > 0) {
                    v.erase(v.begin());
                }
                node->r = nullptr;
                for (auto item_: v) {
                    Add_Element(node, item_);
                }
            }
            else {
                flag = Delete_Element(node->l, item) || Delete_Element(node->r, item);
            }
        }
    }
    return flag;
}

template <class T>
void del(Node<T> *&node) {
    if (node != nullptr) {
        del(node->l);
        del(node->r);
        delete node;
    }
}

template <class T>
void Map_node(Node<T>*& node, T (*f)(T)) {
    if (node != nullptr) {
        node->data = f(node->data);
        Map_node(node->l, f);
        Map_node(node->r, f);
    }
}

template <class T>
std::vector<T> Where_node(Node<T> *&node, bool (*f)(T)) {
    std::vector<T> result = {};
    if (node != nullptr) {
        if (f(node->data)) {
            result.push_back(node->data);
        }
        std::vector<T> vl = Where_node(node->l, f);
        std::vector<T> vr = Where_node(node->r, f);
        result.insert(result.end(), vl.begin(), vl.end());
        result.insert(result.end(), vr.begin(), vr.end());
    }
    return result;
}

template <class T>
T Reduce_node(Node<T> *&node, T (*f)(T, T), T c) {
    std::vector<T> v = klp_node(node);
    if (v.size() == 0) return f(0, c);
    else {
        T result = f(*v.begin(), c);
        v.erase(v.begin());
        for (auto item: v) {
            result = f(item, result);
        }
        return result;
    }
}

template <class T>
Node<T>* Sub_Tree(Node<T>*& node, T new_root){
    Node<T>* result = nullptr;
    if (node != nullptr) {
        if (node->data == new_root) {
            result = node;
        }
        else {
            if (new_root < node->data) {
                result = Sub_Tree(node->l, new_root);
            }
            else if (new_root > node->data) {
                result = Sub_Tree(node->r, new_root);
            }
        }
    }
    return result;
}
