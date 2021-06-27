#include <vector>
#include <string>
#include <cstring>
#include <cstdint>
#include <iostream>
#include "key.h"

Node::Node()
	: n_parent(NULL), n_inheritor(NULL), n_child({}), n_hasBeenDefined(0), n_doesObjectInherit(0),
	n_value(), n_name("ROOT"), n_scope("")
{
}

Node::Node(Node* parentPtr, std::string name)
	: n_parent(parentPtr), n_inheritor(NULL), n_child({}), n_hasBeenDefined(0), n_doesObjectInherit(0),
	n_value(), n_name(name), n_scope("")
{}

Node::~Node()
{}
