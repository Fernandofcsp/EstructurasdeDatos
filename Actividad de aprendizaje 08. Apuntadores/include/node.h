#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<class T>
class Node
    {
    private:
        T data;
        Node* next;

    public:
        Node();
        Node(const T&);

        T& getData();

        void setData(const T&);
    };

#endif // NODE_H_INCLUDED
