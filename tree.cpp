#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
        } else {
            Node* temp = root;
            while (true) {
                if (value < temp->data) {
                    if (temp->left) {
                        temp = temp->left;
                    } else {
                        temp->left = newNode;
                        break;
                    }
                } else {
                    if (temp->right) {
                        temp = temp->right;
                    } else {
                        temp->right = newNode;
                        break;
                    }
                }
            }
        }
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.inorderTraversal();

    cout << "Preorder traversal: ";
    tree.preorderTraversal();

    cout << "Postorder traversal: ";
    tree.postorderTraversal();

    return 0;
}
