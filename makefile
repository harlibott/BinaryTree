executable: Main.o ItemType.o BinaryTree.o
	g++ Main.o ItemType.o BinaryTree.o -o main

run: main
	./main test.txt

Main.o: Main.cpp
	g++ -c Main.cpp

ItemType.o: ItemType.cpp
	g++ -c ItemType.cpp

BinaryTree.o: BinaryTree.cpp
	g++ -c BinaryTree.cpp
clean:
	rm *.o main
