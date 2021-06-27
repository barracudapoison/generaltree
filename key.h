#ifndef KEY_H
#define KEY_H
#pragma once

#include <vector>
#include <string>
#include "super.h"

struct Node;
struct Key;

struct Node
{
	Node* n_parent;
	Node* n_inheritor;
	std::vector<Node*> n_child;

	Super n_value;

	bool n_hasBeenDefined;
	bool n_doesObjectInherit;

	std::string n_name;
	std::string n_scope;

	Node();							// reserved mainly for the root node.  Sets points to NULL
	Node(Node*, std::string);					// Node* parentPtr, Key* keyPtr.  Duh.
	
	~Node();
};

#endif
