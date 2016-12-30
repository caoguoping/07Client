#include "ChatView.h"
#include "ViewManager.h"

ChatView::ChatView()
{
	rootNode = CSLoader::createNode("chat.csb");
	addChild(rootNode);
}
ChatView::~ChatView()
{

}
void ChatView::initView()
{
	char chatName[64];
	char imgName[64];

	layout = dynamic_cast<ScrollView*>(rootNode->getChildByName("ScrollView_1"));
	layout->setScrollBarEnabled(false);
	for (int i = 0; i < 9; i ++)
	{
		sprintf(imgName, "Image_%d", i + 1);
		UIGet_ImageView(imgName, layout, imgBgs[i])
			UIGet_Text("Text_1", imgBgs[i], txtChats[i])
		sprintf(chatName, "chat%d", i + 1);
		txtChats[i]->setString(UTF8String("chat", chatName));
		imgBgs[i]->setGlobalZOrder(GOrderPlayerHead + 1);
		UIClick(imgBgs[i], ChatView::clickChatImgBg)
			imgBgs[i]->setTag(i);
	}

	Size size = Director::sharedDirector()->getVisibleSize();
	rootNode->setPosition(Vec2(835 * size.width / 960, 183 * size.height / 540));
}

void ChatView::clickChatImgBg(Ref* pSender)
{
	ImageView* img = static_cast<ImageView*>(pSender);
	int tag = img->getTag();
	blueSkyDispatchEvent(11301 + tag); //11301 - 11309
}
