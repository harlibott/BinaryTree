struct TreeNode{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
  TreeNode(ItemType &info) : info(info){}
};// struct

class BinaryTree{
  
public:
  BinaryTree();
  ~BinaryTree();
  void putItem(ItemType item);
  void insert(TreeNode * &tree, ItemType item);
  void deleteItem(ItemType item);
  void retrieve(TreeNode * tree, ItemType &item, bool &found) const;
  void preOrder(TreeNode * root) const;
  void inOrder(TreeNode * root) const;
  void postOrder(TreeNode * root) const;
  int getLength() const;
  int count(TreeNode * tree) const;
  bool getItem(ItemType item, bool &found) const;
  void print(int num);
private:
  TreeNode* root;
  int length;
};

