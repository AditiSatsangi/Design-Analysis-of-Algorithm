#include <iostream>
using namespace std;

// Structure for BST node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to search for a value in the BST
bool search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else if (key > root->data) {
        return search(root->right, key);
    } else {
        return true;
    }
}

// Function to find predecessor and successor of a given key in the BST
void findPredecessorSuccessor(Node* root, int key, int& predecessor, int& successor) {
    if (root == nullptr) {
        return;
    }

    if (root->data == key) {
        if (root->left != nullptr) {
            Node* pred = findMin(root->left);
            predecessor = pred->data;
        }

        if (root->right != nullptr) {
            Node* succ = findMin(root->right);
            successor = succ->data;
        }
    } else if (key < root->data) {
        successor = root->data;
        findPredecessorSuccessor(root->left, key, predecessor, successor);
    } else {
        predecessor = root->data;
        findPredecessorSuccessor(root->right, key, predecessor, successor);
    }
}

// Function to find the minimum value in the BST
int findMinimum(Node* root) {
    if (root == nullptr) {
        cerr << "The tree is empty." << endl;
        return -1; // Assuming -1 as an invalid value in this context
    }

    Node* minNode = findMin(root);
    return minNode->data;
}

// Function to find the maximum value in the BST
int findMaximum(Node* root) {
    if (root == nullptr) {
        cerr << "The tree is empty." << endl;
        return -1; // Assuming -1 as an invalid value in this context
    }

    while (root->right != nullptr) {
        root = root->right;
    }

    return root->data;
}

int main() {
    Node* root = nullptr;

    char choice;
    do {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "a. Insertion" << endl;
        cout << "b. Deletion" << endl;
        cout << "c. Inorder Traversal" << endl;
        cout << "d. Searching" << endl;
        cout << "e. Predecessor and Successor" << endl;
        cout << "f. Minimum and Maximum" << endl;
        cout << "x. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            }
            case 'b': {
                int key;
                cout << "Enter the value to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            }
            case 'c': {
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            }
            case 'd': {
                int key;
                cout << "Enter the value to search: ";
                cin >> key;
                bool found = search(root, key);
                if (found) {
                    cout << "Value found in the BST." << endl;
                } else {
                    cout << "Value not found in the BST." << endl;
                }
                break;
            }
            case 'e': {
                int key;
                cout << "Enter the key to find predecessor and successor: ";
                cin >> key;

                int predecessor = -1, successor = -1;
                findPredecessorSuccessor(root, key, predecessor, successor);

                cout << "Predecessor: " << predecessor << endl;
                cout << "Successor: " << successor << endl;
                break;
            }
            case 'f': {
                int minVal = findMinimum(root);
                int maxVal = findMaximum(root);

                if (minVal != -1) {
                    cout << "Minimum value in the BST: " << minVal << endl;
                }

                if (maxVal != -1) {
                    cout << "Maximum value in the BST: " << maxVal << endl;
                }
                break;
            }

            case 'x': {
                cout << "Exiting the program." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 'x');

    return 0;
}
