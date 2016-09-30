#include "PokerActionView.h"
PokerActionView::PokerActionView()
{
	rootNode = CSLoader::createNode("pokerAction.csb");
	addChild(rootNode);
}
PokerActionView::~PokerActionView()
{
	delete rootNode;
	rootNode = NULL;
}