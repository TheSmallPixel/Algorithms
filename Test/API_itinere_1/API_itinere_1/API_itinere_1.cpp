// API_itinere_1.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include <iostream>
#include <deque>
struct node
{
public:
	node() : data(0), left(nullptr), right(nullptr) {}
	node(int _data) : data(_data), left(nullptr), right(nullptr) {}
	int data;
	struct node* left;
	struct node* right;
};
bool checkConstantLevel(node& root) {
	std::deque<node> current;
	current.push_back(root);
	int currentSum = 0;
	int sum = root.data;
	while (!current.empty()) {
		currentSum = 0;
		for(int i = current.size()-1;i>=0;i--){
			currentSum += current.front().data;
			if (current.front().right != nullptr)
				current.push_back(*current.front().right);
			if (current.front().left != nullptr)
				current.push_back(*current.front().left);
			current.pop_front();
		}
		if (currentSum != sum) {
			return false;
		}
	}
	return true;
}
int main()
{
	node root = node(25);
	std::cout << "Check: " << checkConstantLevel(root);
}
