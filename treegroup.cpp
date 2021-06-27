#include <iostream>
#include "treegroup.h"
#include "key.h"

TreeGroup::TreeGroup()
	: m_ROOT()
{
	m_ROOT = new Node();
	allNodes.push_back(m_ROOT);
	most_recent_node = m_ROOT;
}
TreeGroup::~TreeGroup()
{
	int amt = allNodes.size();
	for (int i = 0; i < amt; i++)
	{
		std::cout << allNodes[i] << " " << i << std::endl;
		delete allNodes[i];
	}
	std::cout << (*m_ROOT).n_child[9];
	std::cout << "\nDeletion successful" << std::endl;
	std::cout << "-------------------\nDeleted " << amt << " nodes." << std::endl;
}

Node* TreeGroup::getMostRecentNode()
{
	return most_recent_node;
}

Node* TreeGroup::createLeaf(Node* parent, std::string name)
{
	Node* temp;
	temp = new Node(parent, name);

	temp->n_scope = getAddress(parent);

	((*parent).n_child).push_back(temp);

	allNodes.push_back(temp);
	most_recent_node = temp;

	return temp;
}

Node* TreeGroup::createLeafAtAddress( std::string address, std::string name )
{
	Node* pointer = findNodeFromAddress( address );
	if ( pointer == NULL )
	{
		std::cout << "Could not find Node at address " << address << std::endl;
		return NULL;
	}
	return createLeaf( pointer, name );
}

Node* TreeGroup::getRootNode()
{
	return m_ROOT;
}

Node* TreeGroup::findNodeFromAddress( std::string addr )
{
	std::vector<std::string> splitAddress;
	std::string temp = "";

	Node* currentPointer = m_ROOT;
	bool isFound;								// Loop through every char in string "addr", every time we find a '/', check if the current state of "temp
												// is equal to any one of the addresses in the "currentPointers" children.  
	for (int i = 0; i < addr.length(); ++i)
	{	
		if ( addr[i] == '/' ) { 
			if ( temp == "/ROOT" )
			{
				temp = "/ROOT/";
				continue;
			}
			for (int j = 0; j < ((*currentPointer).n_child).size(); ++j)
			{
				if ( getAddress( (*currentPointer).n_child[j] ) == temp )
				{
					currentPointer = (*currentPointer).n_child[j];
					isFound = true;
					break;
				}
			}
		}
		temp += addr[i];
	}

	if ( getAddress(currentPointer)+"/" != addr ) {
		std::cout << getAddress(currentPointer)+"/" << "  =/=  " << addr << std::endl;
		return NULL;
	}

	std::cout << "We found " << (*currentPointer).n_name << " at " << addr << std::endl;
	return currentPointer;
}

std::string TreeGroup::getName(Node* a)
{
	return (*a).n_name;
}
std::string TreeGroup::getScope(Node* a)
{
	return (*a).n_scope;
}
std::string TreeGroup::getAddress(Node* a)
{
	return ((*a).n_scope + "/" + (*a).n_name);
}

std::string TreeGroup::getValueAsString(Node* a)
{
	std::string temp_str = "";

	for (int i = 0; i < (((*a).n_value).value).size(); i++)
	{
		temp_str += ((*a).n_value).value[i];
	}

	return temp_str;
}

std::string TreeGroup::recalculateAddress( Node* n )
{
	std::cout << (*n).n_name << std::endl;	
	if ( (*n).n_name == "ROOT" )
	{
		return "ROOT";
	} else 
	{
		return recalculateAddress( (*n).n_parent ) + "/" + (*n).n_name;	
	}
}

void TreeGroup::setValue(Node* a, Super value)
{
	(*a).n_value = value;
}

void TreeGroup::setParent( Node* src, Node* dest)
{
	(*dest).n_parent = src;
	(*dest).n_scope = recalculateAddress( src );
	(*dest).n_child.push_back( dest );
}
