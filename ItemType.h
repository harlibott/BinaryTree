class ItemType{

 public:
  enum Comparison {GREATER, LESS, EQUAL};
  explicit ItemType();
  explicit ItemType(int value);
  Comparison compareTo(ItemType &item);
  int getValue() const;
  void printValue();
 private: 
  int value;
};
