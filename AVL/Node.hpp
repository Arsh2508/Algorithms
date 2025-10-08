#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
struct Node {
    Node(const T& val, Node* _left = nullptr, Node* _right = nullptr) 
        : data{val} 
        , left{_left}
        , right{_right}
    {}
    
    T data;
    Node* left;
    Node* right;
};

#endif