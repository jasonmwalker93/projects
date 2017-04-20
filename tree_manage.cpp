# include <string>
# include "BST.h"
# include "BST_imp.h"

int input;

int menu()
{
	cout << "\n1 - Add a new name\n2 - Delete a name\n3 - List the contents in ascending order\n"
		 << "4 - Display the number of nodes in the tree\n5 - Display the number of leaves in the tree\n"
		 << "6 - Create and display (in breadth-first traversal) a mirror image of the tree\n7 - Exit the system\n\n"
		 << "Please enter your choice (as a single number): ";
	cin >> input;
	cout << endl;
	return input;
}


int main()
{
	BST<string> b;
	string data;

	cout << "Tree management system" << endl;

	while(menu() != 7)
	{
		if (input == 1)
		{
			cout << "Enter a new name to add to the tree: ";
			cin >> data;
			if(b.search(data) == 0)
			{
				b.insert(data);
				cout << data << " has been added to the tree." << endl;
			}
			else
				cout << "This name already exists in the tree. Please enter a valid name to add." << endl;
		}
		else if (input == 2)
		{
			cout << "Enter a new name to delete from the tree: ";
			cin >> data;
			if (b.search(data) != 0)
			{
				cout << data;
				b.findAndDeleteByMerging(data);
				cout << " has been deleted from the tree." << endl;
			}
			else
				cout << "This name does not exist in the tree. Please enter a valid name to delete." << endl;
		}
		else if (input == 3)
		{
			cout << "The contents of the tree in ascending order are: ";
			b.inorder();
			cout << endl;
		}
		else if (input == 4)
			cout << "The number of nodes in the tree is: " << b.nodeCount() << endl;
		else if (input == 5)
			cout << "The number of leaves in the tree is: " << b.leafCount() << endl;
		else if (input == 6)
		{
			cout << "Creating a mirror image of the tree..." << endl;
			b.reverse();
			b.breadthFirst();
			cout << endl;
		}
		else
			cout << "You have entered an incorrect number. Please enter a valid menu entry." << endl;
	}


	system("pause");
	return 0;
}