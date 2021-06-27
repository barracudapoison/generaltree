#include <iostream>
#include "treegroup.h"

int main()
{
	TreeGroup nodeTree;	
	nodeTree.createLeaf( nodeTree.getRootNode(), "Test" );
	nodeTree.createLeaf( nodeTree.getRootNode(), "NewGuy" );
	nodeTree.createLeaf( nodeTree.getMostRecentNode(), "Findme" );
	nodeTree.createLeaf( nodeTree.getMostRecentNode(), "Hiding" );

	nodeTree.createLeafAtAddress( "/ROOT/NewGuy/", "Hello" );

	Super test;
	test.setStringValue( 's', "test" );
	nodeTree.setValue( nodeTree.getMostRecentNode(), test );

	nodeTree.findNodeFromAddress( "/ROOT/NewGuy/Findme/Hiding/" );

	//	Current available functions
	//		1).	TreeGroup::createLeaf	( Node* parent, std::string Name );
	//		2). TreeGroup::getName		( Node* );
	//		3). TreeGroup::getScope		( Node* );
	//		4).	TreeGroup::getAddress	( Node* );
	//		5).	TreeGroup::getMostRecentNode()		RETURNS NODE POINTER
	//		6).	Super::setValueRaw		( char, std::vector<unsigned char> )
	//		7).	Super::setValue<type> 	( char, type)
	//		8). Super::setStringValue	( char, std::string )
	//		9).	TreeGroup::getValueAsString( Node* )	Returns string
	//		10).TreeGroup::setValue( Node*, Super ) 	Set dat value using Super struct.
	//		
	//		Desired Functions
	//		a).	TreeGroup::recalculateScope( Node* )
	//		b). 	

	return 0;
}
