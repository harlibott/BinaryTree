#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "ItemType.h"
#include "BinaryTree.h"

using namespace std;

const char INSERT = 'i';
const char DELETE = 'd';
const char RETRIEVE = 'r';
const char LENGTH = 'l';
const char INORDER = 'n';
const char PREORDER = 'p';
const char POSTORDER = 'o';
const char QUIT = 'q';
const char COMMANDS = 'c';
const char SHOW_TREE = 's';

char commands[10] = {INSERT, DELETE, RETRIEVE, LENGTH, INORDER, PREORDER, POSTORDER, QUIT, COMMANDS, SHOW_TREE};

BinaryTree tree;

void commandsList(){
  cout << endl;
  cout << "COMMANDS: " << endl;
  // handles printing out the commands 
  string example = "";
  for (int i = 0; i < 9; i++){
    cout << "   " << "(" << commands[i] << ") " << "- "; 
    switch(i){
    case 0:
      example = "Insert Value";
      break;
    case 1:
      example = "Delete Value";
      break;
    case 2:
      example = "Retrieve Value";
      break;
    case 3:
      example = "Print Length";
      break;
    case 4:
      example = "Inorder";
      break;
    case 5:
      example = "Preorder";
      break;
    case 6: 
      example = "Postorder";
      break;
    case 7:
      example = "Quit Program";
      break;

    case 8:
      example = "Commands List";
      break;

    default: 
      example = "No options availible";
    }
    cout << example << endl;
  }// print commands
}//commands list

void commandDirection(char command){
  // quit(done)
  if(command == 'q'){
    cout << "\nQUITTING...\n" << endl;
    exit(EXIT_SUCCESS);
  }else if(command == 'c'){
    commandsList();

    // insert(done)
  }else if(command == 'i'){
    int insert;
    cout << "Item to insert: ";
    cin >> insert;

    ItemType temp(insert);
    tree.putItem(temp);
    cout << "In-order: ";
    tree.print(0);
    cout << endl;
    // delete(done)

  }else if(command == 'd'){
    int del;
    cout << "Item to delete: ";
    cin >> del;

    ItemType temp(del);
    bool search = false;
    bool found = tree.getItem(temp, search);

    if(found){
      tree.deleteItem(temp);

      cout << "In-Order: ";
      tree.print(0);
      cout << endl;
    }else{
      cout << "Item is not in list." << endl; 
    }
    // length(done)
  }else if(command == 'l'){
    cout << "\nLength of binary tree: " << tree.getLength() << endl;

    // retrieve(done)
  }else if(command == 'r'){
    int r;
    cout << "Item to be retrieved: ";
    cin >> r;

    ItemType temp(r);
    bool search = false;
    bool found = tree.getItem(temp, search);

    if(found){
      cout << "Item was found in tree" << endl;
    }else{
      cout << "Item was not found in tree" << endl;
    }
  }else if(command == 'p'){
    cout << "Pre-Order: ";
    tree.print(2);
    cout << endl;
  }else if(command == 'o'){
    cout << "Post-Order: ";
    tree.print(3);
    cout << endl;
  }else if(command == 'n'){
    cout << "In-Order: ";
    tree.print(1);
    cout << endl;
  }
}// command direction

void prompt(){
  // handles prompt
  char command;
  string err = "There was an error. Please type only char letters listed in commands list (c) in lower case form...";
  
  cout << "\nEnter a command: ";
  cin >> command;
  
  if(command == 'i' || command == 'd' || command == 'r' || command == 'l' || command == 'n' || command == 'p' ||
     command == 'o' || command == 'q' || command == 's' || command == 'c'){
    commandDirection(command);
  }else{
    cout << "\n" << err << endl;
  }
  
}// prompt

int main(int argc, char* argv[]){

  //opens file
  if (argc > 1) {
    string fn = argv[1];
    int file;
    ifstream fin;
    
    fin.open(fn.c_str());
    assert(fin.is_open());
    
    //inserts list into linked list
    while(fin >> file){
      ItemType temp(file);
      tree.putItem(temp);
    }

  } else {
    cout << "No file entered. Please enter a file containing a list. Exiting..."<< endl;
    return -1;
  }
  
  cout << endl;
  cout << "Welcome to the binary search tree program..."<< endl;
  
  commandsList();

  while(true){
    prompt();
  }
}
