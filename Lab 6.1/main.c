#include <stdio.h>
#include <stdlib.h>

typedef struct SNode {
    int key;
    struct SNode *left, *right, *parent;
} *PNode;

PNode myRoot;

int recCount(PNode node, int count) {
    if(node != NULL) {
        if(node->left != NULL) {
            count = recCount(node->left, count);
        }
        if(node->right == NULL || node->left == NULL) {
            count++;
        }
        if(node->right != NULL) {
            count = recCount(node->right, count);
        }
    }
    return count;
}

int countIncompleteNodes(PNode root) {
    return recCount(root, 0);
}

PNode findInTree(PNode root, int key) {
    PNode current = root;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        if (current->key < key) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return NULL;
}

PNode addNode(PNode root, int key) {
    PNode node = malloc(sizeof(struct SNode));

    node->key = key;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;

    PNode current = root;

    if (current) {
        while (current != NULL) {
            if (current->key == node->key) {
                printf("Element is already placed in the tree\n");
                return root;
            }
            if (current->key > node->key) {

                if (current->left == NULL) {
                    current->left = node;
                    node->parent = current;
                    return root;
                } else {
                    current = current->left;
                }

            } else {

                if (current->right == NULL) {
                    current->right = node;
                    node->parent = current;
                    return root;
                } else {
                    current = current->right;
                }

            }
        }
    } else {
        root = node;
    }
    return root;
}

PNode removeNode(PNode root, int key) {
    PNode deletable = findInTree(root, key);
    if (deletable == NULL) {
        printf("There is no element with key \"%d\" in the tree.\n", key);
        return root;
    } else {
        if(deletable == root) {
            return NULL;
        }
        char isLeft;
        if (deletable->parent->left == deletable) {
            isLeft = 1;
        } else {
            isLeft = 0;
        }
        if (deletable->left == NULL) {
            if (deletable->right != NULL) {
                PNode successor = deletable->right;
                if(successor->left == NULL) {
                    if (isLeft) {
                        deletable->parent->left = successor;
                    } else {
                        deletable->parent->right = successor;
                    }
                    successor->parent = deletable->parent;
                    successor->left = deletable->left;
                    return root;
                }

                while (successor->left != NULL) {
                    successor = successor->left;
                }
                if (isLeft) {
                    deletable->parent->left = successor;
                } else {
                    deletable->parent->right = successor;
                }
                successor->parent = deletable->parent;
                successor->left = deletable->left;
                successor->right = deletable->right;
                return root;
            }
        } else {
            PNode successor = deletable->left;
            if(successor->right == NULL) {
                if (isLeft) {
                    deletable->parent->left = successor;
                } else {
                    deletable->parent->right = successor;
                }
                successor->parent = deletable->parent;
                successor->right = deletable->right;
                return root;
            }

            while (successor->right != NULL) {
                successor = successor->right;
            }
            if (isLeft) {
                deletable->parent->left = successor;
            } else {
                deletable->parent->right = successor;
            }
            successor->parent = deletable->parent;
            successor->left = deletable->left;
            successor->right = deletable->right;
            return root;
        }
    }
    if(deletable->parent->left == deletable) {
        deletable->parent->left = NULL;
    } else {
        deletable->parent->right = NULL;
    }
    return root;
}

void recPrint(PNode node) {
    if(node != NULL) {
        if(node->left != NULL) {
            recPrint(node->left);
        }
            printf("%d ", node->key);
        if(node->right != NULL) {
            recPrint(node->right);
        }
    }
}

void printTree(PNode root) {
    printf("Tree as array:\n");
    recPrint(root);
}

int inputKey() {
    printf("Input key:\n");
    int key;
    scanf("%d", &key);
    return key;
}

int choose() {
    printf("Choose action: \n1. Add node.\n2. Remove node.\n3. Print a tree.\n4. Count incomplete nodes in tree.\n5. Exit.\n");
    fflush(stdin);
    switch (getchar()) {
        case '1':
            myRoot = addNode(myRoot, inputKey());
            return 1;
        case '2':
            myRoot = removeNode(myRoot, inputKey());
            return 1;
        case '3':
            printTree(myRoot);
            return 1;
        case '4':
            countIncompleteNodes(myRoot);
            return 1;
        case '5':
            return 0;
        default:
            return 1;
    }
}

int main() {
    /*myRoot = addNode(myRoot, 5);
    myRoot = addNode(myRoot, 7);
    myRoot = addNode(myRoot, 6);
    myRoot = addNode(myRoot, 4);
    myRoot = addNode(myRoot, 10);
    myRoot = addNode(myRoot, 11);
    myRoot = addNode(myRoot, 8);
    myRoot = addNode(myRoot, 9);
    myRoot = addNode(myRoot, 3);
    printTree(myRoot);
    printf("\n%d\n", countIncompleteNodes(myRoot));*/
    while (choose()) {
        printf("\n");
    }
    return 0;
}