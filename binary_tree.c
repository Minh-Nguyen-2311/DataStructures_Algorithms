/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Binary tree
struct Node{
  int data;  
  struct Node *left, *right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

void correctOrder(struct Node* root){
    if(root != NULL){
        correctOrder(root->left);
        printf("%d", root->data);
        correctOrder(root->right);
    }
}

void freeMem(struct Node* root){
    if(root != NULL){
        freeMem(root->left);
        freeMem(root->right);
        free(root);
    }
}

int main(){
    int arr[] = {5, 3, 7, 2, 8, 1, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    struct Node* root = NULL;
    
    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }
    
    printf("Sorted order: /n");
    correctOrder(root);
    
    freeMem(root);
    
    return 0;
}