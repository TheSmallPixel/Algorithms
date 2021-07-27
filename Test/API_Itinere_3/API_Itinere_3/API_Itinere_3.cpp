#include <iostream>
#include <math.h>
#include <limits>
#include <string>
#include <vector>


class Romanzo {
public:
	Romanzo(std::string name, int anno, int index) : Name(name), Anno(anno), Index(index) {}
	std::string Name;
	int Anno;
	int Index;
	int GetValue() {
		return Anno;
	}
};
void max_heapify(Romanzo* A[], int size, int index)
{
	int largest = index;				// largest = root
	int l = 2 * index + 1;				// left
	int r = 2 * index + 2;				// right

	if (l < size && A[l]->GetValue() > A[largest]->GetValue())	// If left child is larger than root
		largest = l;

	if (r < size && A[r]->GetValue() > A[largest]->GetValue())	// If right child is larger than largest so far
		largest = r;

	if (largest != index) {				// If largest is not root, swap and re-heapify
		std::swap(A[index], A[largest]);
		max_heapify(A, size, largest);	// Recursively heapify the affected sub-tree
	}
}

void sort(Romanzo* A[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		max_heapify(A, size, i);	// ok buy why half duah
	for (int i = size - 1; i > 0; i--) {// One by one extract an element from heap and removeit
		std::swap(A[0], A[i]);			// Remove current max
		max_heapify(A, i, 0);		// Reorder new sub-tree
	}
}
int remove_duplicates(Romanzo* arr[], int& n) {
	if (n == 0 || n == 1)
		return n;

	// To store index of next unique element
	int j = 0;

	for (int i = 0; i < n - 1; i++) {
		if (arr[i]->GetValue() != arr[i + 1]->GetValue()) {
			arr[j++] = arr[i];
		}
		else {
			if (arr[i]->Index < arr[i + 1]->Index)
				std::swap(arr[i], arr[i + 1]);
		}
	}

	arr[j++] = arr[n - 1];

	return j;
}


void Print(int n, Romanzo* romanzi[10]);

int main()
{
	int j = 0;
	Romanzo* romanzi[] = {
	new Romanzo("I dolori del giovane Werther",1774,j++),
	new Romanzo("Kim",1901,j++) ,
	new Romanzo("Il Corsaro Nero",1898,j++),
	new Romanzo("I Buddenbrock",1901,j++),
	new Romanzo("Don Chisciotte",1605,j++),
	new Romanzo("Cuore",1886,j++),
	new Romanzo("I viaggi di Gulliver",1726,j++),
	new Romanzo("Il piccolo Lord",1886,j++),
	new Romanzo("L’esclusa",1901,j++),
	new Romanzo("Senilità",1898,j++)
	};

	int n = 10;
	sort(romanzi, n);

	std::cout << "\nSort!\n";
	Print(n, romanzi);

	std::cout << "\nRemove Duplicates!\n";
	n = remove_duplicates(romanzi, n);
	Print(n, romanzi);
}

void Print(int n, Romanzo* romanzi[])
{
	for (int i = 0; i < n; i++) {
			std::cout << "[" << i << "]" << "(" << romanzi[i]->Anno << ", " << romanzi[i]->Name << ")" << std::endl;
		
	}
}


