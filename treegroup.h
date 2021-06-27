#ifndef TREEGROUP_H
#define TREEGROUP_H
#pragma once

#include "key.h"

class TreeGroup
{
	private:
		Node* m_ROOT;
		std::vector<Node*> allNodes;

		Node* most_recent_node;

	public:

		Node* getMostRecentNode();
		Node* getRootNode();
		Node* createLeaf(Node*, std::string);
		Node* createLeafAtAddress( std::string, std::string );
		Node* findNodeFromAddress( std::string );

		std::string getName				( Node* );
		std::string getScope			( Node* );
		std::string getAddress			( Node* );
		std::string getValueAsString	( Node* );
		std::string recalculateAddress	( Node* );


		void setValue(Node*, Super);
		void setParent( Node*, Node* );		
		TreeGroup();
		~TreeGroup();
};

#endif
