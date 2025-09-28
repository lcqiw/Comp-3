#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Factorial function
int factorial(int n)
 {
	if (n < 0) throw std::invalid_argument("error negative input");
	int result = 1;
	for (int i = 2; i <= n; ++i)
		result *= i;
	return result;
}

// Generic bounded input function
template <typename T>
T getUserInput(const string& prompt, const string& errorMsg, T lower, T upper)
 {
	T input;
	while (true) 
    {
		cout << prompt;
		cin >> input;

		if (cin.fail() || input < lower || input > upper) 
        {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << errorMsg << "\n";
		} else {
			return input;
		}
	}
}

// Overloaded << for vector<T>
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec)
 {
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		out << *it << " ";
	return out;
}

// Template function to print all permutations
template <typename T>
void printPermutations(vector<T> vec) 
{
	std::sort(vec.begin(), vec.end());
	int total = factorial((int)vec.size());

	cout << "\nGenerating all " << total << " permutations for a collection of "
	     << (int)vec.size() << " items:\n";

	int index = 1;
	do {
		cout << "[" << index++ << "] ";
		for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
			cout << *it << " ";
		cout << "\n";
	} 
    while (std::next_permutation(vec.begin(), vec.end()));
}

// Derived class from vector<char>
class CharVector : public vector<char>
 {
public:
	void fill(const int numChars, const char firstChar)
     {
		if (numChars > 52)
			throw std::invalid_argument("Cannot exceed 52 characters.");
		this->clear();
		char c = firstChar;
		for (int i = 0; i < numChars; ++i) 
        {
			this->push_back(c);
			if (c == 'Z') c = 'a'; // switch case
			else ++c;
		}
	}
};


int main(void)
 {
	cout << "Welcome to the permutation generator!" << endl;

	CharVector charVec;
	int num = getUserInput<int>(
		"Enter number of characters to permute (1-52): ",
		"Error: Please enter a valid number within the range.",
		1, 52
	);

	charVec.fill(num, 'a');
	printPermutations(charVec);

	cout << "\nFinal state of char collection: " << charVec << "\n";

	// Manually assign strings since initializer_list is not allowed
	vector<string> words;
	words.push_back("Hello");
	words.push_back("goodbye");
	words.push_back("world");

	printPermutations(words);

	cout << "\nFinal state of string collection: " << words << "\n";

	return 0;
}
