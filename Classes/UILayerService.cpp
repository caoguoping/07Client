#include "UILayerService.h"
#include "SGTools.h"
#include "TCPSocketService.h"


const string UILayerService::NAME("UILayerService");
UILayerService::UILayerService()
{
	init();
}
UILayerService::~UILayerService()
{

}
 
void UILayerService::init()
{
	mainLayer = Layer::create();
	outPokerLayer = Layer::create();
	myPokerLayer = Layer::create();
	menuLayer = Layer::create();
	uiLayer = Layer::create();
	maskLayer = Layer::create();
	TopLayer = Layer::create();
	getcontainer()->addChild(mainLayer);
	getcontainer()->addChild(outPokerLayer);
	getcontainer()->addChild(myPokerLayer);
	getcontainer()->addChild(menuLayer);
	getcontainer()->addChild(uiLayer);
	getcontainer()->addChild(maskLayer);
	getcontainer()->addChild(TopLayer, 10000);
}

void UILayerService::onEvent(int i, void* data)
{
	switch (i)
	{
		case 30000:

			((TCPSocketService*)getService(TCPSocketService::LOGIN))->closeMySocket();
			((TCPSocketService*)getService(TCPSocketService::GAME))->closeMySocket();
			Director::getInstance()->end();
			break;
		case 30001:
			creatView(new ShopView(1),new ShopMediator());
			break;

			//×êÊ¯²»×ã£¬³äÖµ
		case 30002:
			creatView(new ShopView(0), new ShopMediator());
			break;
	}
}