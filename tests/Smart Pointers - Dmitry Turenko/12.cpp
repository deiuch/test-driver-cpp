/**
 * Test for custom deleter of smart pointer
 * 
 * Done by Turenko Dmitry
*/
#include <memory>
#include <iostream>

int q = 0;
int q1_del = 0, q2_del = 0;

struct C {
    int v;
    ~C() { 
        if (q == 0) q1_del++;
        else q2_del++;
    }
};

struct Node {
    int size;
    C* values;
};

void point_deleter(Node* n) {
    delete[] n->values;
    delete n;
}

int test_custom_deleter() {
    q = 0;
    {
        std::shared_ptr<Node> n(new Node{ 2, new C[2]{ C{1}, C{2} }});
    }
    q = 1;
    {
        std::shared_ptr<Node> n(new Node{ 2, new C[2]{ C{1}, C{2} }}, point_deleter);
    }
    return !(q1_del == 0 && q2_del == 2);
}

int main() {
    return test_custom_deleter();
}