//Binary Trees
#include<stdio.h>
#include<stdlib.h>
struct BinarySearchTree{
    struct BinarySearchTree *left;
    int data;
    struct BinarySearchTree *right;
};
typedef struct BinarySearchTree bst;
bst *start=NULL;
void insert(int value){
    //to check ki root bn rkha hai ki nahi 
    bst *nn,*sl,*search;
    nn=(bst*)malloc(sizeof(bst));
    if(start==NULL){
        start=(bst *)malloc(sizeof(bst));
        start->left=NULL;
        start->data=value;
        start->right=NULL;
    
        printf("\nRoot has been inserted");        
    }
    else{
        nn=(bst *)malloc(sizeof(bst));
        if(nn != NULL){
            nn->left=NULL;
            nn->data=value;
            nn->right=NULL;
        
            sl=NULL;
            search=start;
            while(search != NULL){
                if(search->data > value){
                    sl=search;
                    search=search->left;
                }
                else if(search->data < value){
                    sl=search;
                    search=search->right;
                }
                else if(search->data == value){
                    printf("***Value already exists***");
                    free(nn);
                    break;
                }
            }
            if(sl->data > value){
                sl->left=nn;
            }else{
                sl->right=nn;
            }
            printf("\nValue has been inserted");
        }
        else{
            printf("Memory is full");
        }
    }
}
void preorder(bst *t) {
    if (t == NULL) {
        return; // Base case: If the tree is empty or we've reached a leaf node, return.
    }

    printf("%d ", t->data);

    if (t->left != NULL) {
        preorder(t->left);
    }

    if (t->right != NULL) {
        preorder(t->right);
    }
}

void inorder(bst* t) {
    if (t != NULL) {

    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
    }        
}
void postorder(bst *t){
    
    if(t != NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->data);
    }
    else{
        return;
    }
}
void main(){
    int ch,value;
    printf("\nPress 1: Insert");
    printf("\nPress 2: Display in Preorder");
    printf("\nPress 3: Display in INorder");
    printf("\nPress 4: Display in Postorder");
    printf("\nPress 5: Exit");
    while(1){
        printf("\nEnter Choice");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:printf("\nEnter value");
            scanf("%d",&value);
            insert(value);
            break;
            
            case 2:printf("Preorder Traversal :\n");
            preorder(start);
            break;
            
            case 3:printf("INorder Traversal :\n");
            inorder(start);
            break;
            
            case 4:printf("Postorder Traversal :\n");
            postorder(start);
            break;
            
            case 5:printf("*****Code has been terminated*****");
            exit(1);
            break;
            
            default:printf("\n***Invalid Choice***");
            break;
            
        }
    }
}