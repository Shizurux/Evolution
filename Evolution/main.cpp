#include <ctime>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> operations;

class Tree {
	struct Node {
		bool leaf;

		double value;

		std::string operation;
		std::vector<Node*> children;
	};

	Node *root;

	static void print2(Node *cur) {
		if (cur->leaf) {
			std::cout << cur->value;
		}
		else {
			std::cout << "(" << cur->operation;
			for (auto c : cur->children) {
				std::cout << " ";
				print2(c);
			}
			std::cout << ")";
		}
	}

public:
	Tree() {
		root = new Node;
		root->leaf = true;
		root->value = 0;

		for (auto i = 0; i < 10; i++) {
			auto n = findRandomLeaf();

			n->leaf = false;
			n->operation = operations[rand() % operations.size()];

			for (auto j = 0; j < 2; j++) {
				auto child = new Node;

				child->leaf = true;
				child->value = (rand() % 2000 + 1) / 2001.0 - 2;

				n->children.push_back(child);
			}
		}
	}

	Node *findRandomLeaf() const {
		auto cur = root;

		while (true) {
			if (cur->leaf) {
				return cur;
			}
			cur = cur->children[rand() % cur->children.size()];
		}
	}

	void print() const {
		print2(root);
	}
};

int main() {
	srand(time(nullptr));

	operations.push_back("+");
	operations.push_back("-");
	operations.push_back("*");
	operations.push_back("/");

	Tree t;
	t.print();

	std::cin.get();
	return 0;
}