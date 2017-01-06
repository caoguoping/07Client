#include "JiPaiView.h"
JiPaiView::JiPaiView()
{
	rootNode = CSLoader::createNode("jiPai.csb");
	addChild(rootNode);
}
JiPaiView::~JiPaiView()
{

}