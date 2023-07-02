#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct SNode {
    int key;
    int level;
    struct SNode *left, *right, *parent;
} *PNode;

PNode myRoot;
int myI;
int maxLevel;
int counter;

int recCount(PNode node, int count);
int countIncompleteNodes(PNode root);
PNode findInTree(PNode root, int key);
PNode addNode(PNode root, int key);
PNode removeNode(PNode root, int key);
void recPrint(PNode node);
void recArr(PNode node, PNode * arr);
void printSpaces(int c);
void printAsTree(PNode root);
void arrToMatr(PNode *arr, int **matrix, int countOnMaxLevel);
void printTree(PNode root);
int inputKey();
int choose();
void printm(int **matrix, int countI, int countJ);

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
    if(key < -998) {
        return root;
    }
    PNode node = malloc(sizeof(struct SNode));

    node->key = key;
    node->right = NULL;
    node->left = NULL;
    node->parent = NULL;

    PNode current = root;
    int newLevel = 0;

    if (current) {
        while (current != NULL) {
            if (current->key == node->key) {
                printf("Element is already placed in the tree\n");
                return root;
            }
            newLevel++;
            if (current->key > node->key) {

                if (current->left == NULL) {
                    current->left = node;
                    node->parent = current;
                    node->level = newLevel;
                    if(newLevel > maxLevel) {
                        maxLevel = newLevel;
                    }
                    counter++;
                    return root;
                } else {
                    current = current->left;
                }

            } else {

                if (current->right == NULL) {
                    current->right = node;
                    node->parent = current;
                    node->level = newLevel;
                    if(newLevel > maxLevel) {
                        maxLevel = newLevel;
                    }
                    counter++;
                    return root;
                } else {
                    current = current->right;
                }

            }
        }
    } else {
        root = node;
    }
    node->level = newLevel;
    if(newLevel > maxLevel) {
        maxLevel = newLevel;
    }
    counter++;
    return root;
}

PNode removeNode(PNode root, int key) {
    PNode deletable = findInTree(root, key);
    if (deletable == NULL) {
        printf("There is no element with key \"%d\" in the tree.\n", key);
        return root;
    } else {
        if(deletable == root) {
            counter--;
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
                    successor->parent->left = NULL;
                    successor->parent = deletable->parent;
                    successor->left = deletable->left;
                    successor->level = deletable->level;
                    deletable->left->parent = successor;
                    counter--;
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
                successor->parent->left = NULL;
                successor->parent = deletable->parent;
                successor->left = deletable->left;
                successor->right = deletable->right;
                successor->level = deletable->level;
                deletable->left->parent = successor;
                counter--;
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
                successor->parent->right = NULL;
                successor->parent = deletable->parent;
                successor->right = deletable->right;
                successor->level = deletable->level;
                deletable->right->parent = successor;
                counter--;
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
            successor->parent->right = NULL;
            successor->parent = deletable->parent;
            successor->left = deletable->left;
            successor->right = deletable->right;
            successor->level = deletable->level;
            deletable->right->parent = successor;
            counter--;
            return root;
        }
    }
    if(deletable->parent->left == deletable) {
        deletable->parent->left = NULL;
    } else {
        deletable->parent->right = NULL;
    }
    counter--;
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

void recArr(PNode node, PNode * arr) {
    if(node != NULL) {
        if(node->left != NULL) {
            recArr(node->left, arr);
        }
        arr[myI] = node;
        myI++;
        if(node->right != NULL) {
            recArr(node->right, arr);
        }
    }
}

void printSpaces(int c) {
    for(int i = 0; i < c; i++) {
        printf(" ");
    }
}

void printAsTree(PNode root) {
    myI = 0;
    int countOnMaxLevel = (int) pow(2, maxLevel);
    PNode * arr = calloc(counter, sizeof(int));
    recArr(root, arr);

    int ** matrix = calloc(maxLevel + 1, sizeof(int));
    arrToMatr(arr, matrix, countOnMaxLevel);
    for(int i = 0; i < maxLevel + 1; i++) {
        for(int j = 0; j < countOnMaxLevel; j++) {
            printSpaces(5);
            if(matrix[i][j] > -999) {
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void printm(int **matrix, int countI, int countJ) {
    for(int i = 0; i < countI; i++) {
        for(int j = 0; j < countJ; j++) {
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void arrToMatr(PNode *arr, int **matrix, int countOnMaxLevel) {
    for(int i = 0; i < maxLevel + 1; i++) {
        matrix[i] = calloc(countOnMaxLevel, sizeof(int));
        for(int j = 0; j < countOnMaxLevel; j++) {
            matrix[i][j] = -999;
        }
    }
    for(int i = 0; i < counter; i++) {
        matrix[arr[i]->level][i] = arr[i]->key;
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
            printf("Count of incomplete nodes: %d\n", countIncompleteNodes(myRoot));
            return 1;
        case '5':
            return 0;
        default:
            return 1;
    }
}

int main() {
    maxLevel = -1;
    myRoot = addNode(myRoot, 10);
    myRoot = addNode(myRoot, 20);
    myRoot = addNode(myRoot, 15);
    myRoot = addNode(myRoot, 14);
    myRoot = addNode(myRoot, 16);
    myRoot = addNode(myRoot, 17);
    myRoot = addNode(myRoot, 18);
    myRoot = addNode(myRoot, 19);
    myRoot = addNode(myRoot, 21);
    myRoot = addNode(myRoot, 9);
    myRoot = addNode(myRoot, 7);
    myRoot = addNode(myRoot, 3);
    myRoot = addNode(myRoot, 1);
    myRoot = addNode(myRoot, 8);
    myRoot = addNode(myRoot, -3);
    myRoot = addNode(myRoot, -4);
    printAsTree(myRoot);
    while (choose()) {
        printf("\n");
    }
    return 0;
}