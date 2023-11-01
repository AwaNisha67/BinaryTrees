//CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL
#include<stdio.h>
#include<stdlib.h>
struct BST{
struct BST *left;
int data;
struct BST *right;
};

struct BST *buildTree(int *preorder,int *inorder,int preStart,int inStart,int inEnd){
 if(preStart >= 0 && inStart <= inEnd){
    struct BST *nn=(struct BST*)malloc(sizeof(struct BST));
    nn->data=preorder[preStart];
    nn->left=nn->right=NULL;

   int inIndex;//to check where is the root in inorder
   for(inIndex=inStart; inIndex<=inEnd; inIndex++){ 
   if(inorder[inIndex] == preorder[preStart]){
    break;
   }
}
//left tree using recursion
 nn->left=buildTree(preorder, inorder, preStart+1, inStart, inIndex-1);
//right tree using recursion
 nn->right=buildTree(preorder, inorder, preStart - inStart + inIndex+1, inIndex+1, inEnd);

 return nn;
}
return NULL;
}
void binarytreePrint(struct BST *root){
    if(root != NULL){
     binarytreePrint(root->left);
     printf("%d ",root->data);
     binarytreePrint(root->right);
    }
}
void main(){
    int i,size;
    printf("Enter size : ");
    scanf("%d",&size);
    int preorder[size],inorder[size];
    printf("Enter preorder elements : ");
    for(i=0;i<size;i++){
        printf("%d:",i+1);
        scanf("%d",&preorder[i]);
    }
    printf("Enter inorder elements : ");
    for(i=0;i<size;i++){
        printf("%d:",i+1);
        scanf("%d",&inorder[i]);
    }

    struct BST *root=buildTree(preorder,inorder,0,0,size-1);
    //traversing
    binarytreePrint(root);

}