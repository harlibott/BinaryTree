#include <iostream> struct TreeNode; typedef char ItemType;
#include <string>
#include "ItemType.h"
#include "BinaryTree.h"

//enum OrderType (PRE_ORDER, IN_ORDER, POST_ORDER);

using namespace std;

int countNodes(TreeNode* tree);
void deleteNode(TreeNode*& tree);
void deleteBoth(TreeNode*& tree, ItemType item);
void getPredecessor(TreeNode* tree, ItemType& data);
void destroy(TreeNode* root);

/* Constructor for the binary tree */
BinaryTree::BinaryTree(){
  length = 0;
  root = NULL;
}// constructor

/* Deconstructor recursive funtion for binary tree */
void destroy(TreeNode* root){
  if(root){
    destroy(root->left);
    destroy(root->right);
    delete root;
  }
}// destroy

/* Deconstructor binary tree */
BinaryTree::~BinaryTree(){
  destroy(root);
}// destructor

/* Insert recursive function for binary tree */
void BinaryTree::insert(TreeNode*& tree, ItemType item){
  if(tree == NULL){
    tree = new TreeNode(item);
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }else if(item.compareTo(tree->info) == ItemType::LESS){
    insert(tree->left, item);
  }else if(item.compareTo(tree->info) == ItemType::GREATER){
    insert(tree->right, item);
  }else if(item.compareTo(tree->info) == ItemType::EQUAL){
    cout << "Item already in the tree" << endl;
    return;
  }
}// insert

/* Insert function for binary tree */
void BinaryTree::putItem(ItemType item){
  insert(root, item);
}// put item

/* Delete recursive function for binary tree */
void deleteBoth(TreeNode*& tree, ItemType item){

  if(item.compareTo(tree->info) == ItemType::LESS){
    deleteBoth(tree->left, item);
  }else if(item.compareTo(tree->info) == ItemType::GREATER){
    deleteBoth(tree->right, item);
  }else{
    deleteNode(tree);
  }
}// deleteBoth

/* recursive delete node function for binary tree */
void deleteNode(TreeNode*& tree){
  ItemType data;
  TreeNode* temp;
  temp = tree;

  if(tree->left == NULL){
    tree = tree->right;
    delete temp;
  }else if(tree->right == NULL){
    tree = tree->left;
    delete temp;
  }else{
    getPredecessor(tree->left, data);
    tree->info = data;
    deleteBoth(tree->left, data);
  }
}// deletenode

/* get predecessor for binary tree */
void getPredecessor(TreeNode * tree, ItemType& data){
  while(tree->right != NULL){
    tree = tree->right;
    data = tree->info;
  }
}// getPredecessor

/* delete item function for binary tree */
void BinaryTree::deleteItem(ItemType item){
  deleteBoth(root, item);
}// delete item

/* recursive retrieve function for binary tree */
void BinaryTree::retrieve(TreeNode* tree, ItemType& item, bool& found) const{
  if(tree == NULL){
    found = false;
  }else if(item.compareTo(tree->info) == ItemType::LESS){
    retrieve(tree->left, item, found);
  }else if(item.compareTo(tree->info) == ItemType::GREATER){
    retrieve(tree->right, item, found);
  }else{
    item = tree->info;
    found = true;
  }
}// retrieve

/* recursive get item for binary tree */
bool BinaryTree::getItem(ItemType item, bool& found) const{
  retrieve(root, item, found);
  return found;
}// getitem type

/* get length of binary tree */
int BinaryTree::getLength() const{
  return countNodes(root);
}// get length

/* counts the number of nodes in a binary tree */
int countNodes(TreeNode* tree){
  if(tree == NULL){
    return 0;
  }else{
    return countNodes(tree->left) + countNodes(tree->right) + 1;
  }
}// count nodes

/* prints inorder */
void BinaryTree::inOrder(TreeNode * root) const{
  if(root == NULL){
    return;
  }

  inOrder(root->left);
  cout << root->info.getValue() << " ";
  inOrder(root->right);
}// inorder

/* prints preorder */
void BinaryTree::preOrder(TreeNode * root) const{
  if(root == NULL){
    return;
  }

  cout << root->info.getValue() << " ";
  preOrder(root->left);
  preOrder(root->right);
 
}// preorder

/* prints postorder */
void BinaryTree::postOrder(TreeNode * root) const{
  if(root == NULL){
    return;
  }

  postOrder(root->left);
  postOrder(root->right);

  cout << root->info.getValue() << " ";
}// postorder

/* print function for binary serach tree */
void BinaryTree::print(int num){

  if(num == 0){
    inOrder(root);
  }else if(num == 1){
    inOrder(root);
  }else if(num == 2){
    preOrder(root);
  }else if(num == 3){
    postOrder(root);
  }
}// print
