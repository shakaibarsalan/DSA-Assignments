#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    int age;
    Node *left;
    Node *right;
    Node(string n = "", int a = 0)
    {
        name = n;
        age = a;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, string name, int age)
{
    if (root == NULL)
    {
        return new Node(name, age);
    }

    if (age < root->age)
    {
        root->left = insert(root->left, name, age);
    }
    else if (age > root->age)
    {
        root->right = insert(root->right, name, age);
    }

    return root;
}

Node *search(Node *root, string name)
{
    if (root == NULL)
    {
        cout << " -> Currently, the family tree is empty." << endl;
        return NULL;
    }

    if (name < root->name)
    {
        return search(root->left, name);
    }
    else if (name > root->name)
    {
        return search(root->right, name);
    }
    else
    {
        return root;
    }
}

Node *addRelationship(Node *root, string parent, string child)
{

    if (root == NULL)
    {
        cout << "The family tree is empty." << endl;
        return root;
    }

    Node *parentNode = search(root, parent);

    if (parentNode == NULL)
    {
        cout << "The parent is not in the family tree." << endl;
        return root;
    }

    Node *childNode = search(root, child);

    if (childNode == NULL)
    {
        childNode = new Node(child, 0);
    }

    if (parentNode->left != NULL && parentNode->left->name == childNode->name)
    {
        cout << "The child is already a child of the parent." << endl;
        return root;
    }

    if (parentNode->right != NULL && parentNode->right->name == childNode->name)
    {
        cout << "The child is already a child of the parent." << endl;
        return root;
    }

    if (childNode->name < parentNode->name)
    {
        parentNode->left = childNode;
    }

    else
    {
        parentNode->right = childNode;
    }

    return root;
}


void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << "  Name: " << root->name << ", Age: " << root->age << endl;
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << "  Name: " << root->name << ", Age: " << root->age << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << "  Name: " << root->name << ", Age: " << root->age << endl;
}

Node *findOldest(Node *root)
{
    if (root == NULL)
    {
        cout << "Family tree is empty." << endl;
        return NULL;
    }

    Node *result = root;

    while (result->right != NULL)
    {
        result = result->right;
    }

    return result;
}

int main()
{
    Node *root = NULL;
    Node *result = NULL;

    int choice, age;
    string name, parent, child;

    while (true)
    {
        cout << endl
             << "1. Insert a new member" << endl
             << "2. Search for a member" << endl
             << "3. Print the family tree" << endl
             << "4. Find the oldest family member" << endl
             << "5. Add a relationship" << endl
             << "6. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the name of the member: ";
            cin >> name;
            cout << "Enter the age of the " << name << ": ";
            cin >> age;
            root = insert(root, name, age);
            break;

        case 2:
            cout << "Enter the name of the member: ";
            cin >> name;
            result = search(root, name);
            if (result != NULL)
            {
                cout << "Name: " << result->name << endl
                     << "Age: " << result->age << endl;
            }
            break;

        case 3:
            cout << "Inorder traversal: " << endl;
            inorder(root);
            cout << "Preorder traversal: " << endl;
            preorder(root);
            cout << "Postorder traversal: " << endl;
            postorder(root);
            break;

        case 4:
            cout << "Oldest member: ";
            result = findOldest(root);
            if (result != NULL)
            {
                cout << " -> Name: " << result->name << ", Age: " << result->age << endl;
            }
            break;

        case 5:
            cout << "Enter the name of the parent: ";
            cin >> parent;
            cout << "Enter the name of the child: ";
            cin >> child;
            root = addRelationship(root, parent, child);
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}