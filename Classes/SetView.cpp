#include "SetView.h"
#include "SGTools.h"
#include "MusicService.h"

SetView::SetView()
{
	rootNode = CSLoader::createNode("set.csb");
	addChild(rootNode);
	rootNode->setScale(0.8f, 0.8f);
	rootNode->runAction(Sequence::create(
		ScaleTo::create(0.2f, 1.03f),
		ScaleTo::create(0.15f, 1.0f),
		nullptr));
	UIGet_CheckBox("musicBtn", rootNode, chkMusic)
	UIGet_CheckBox("effectBtn", rootNode, chkEffect)
	UIClick(chkMusic, SetView::clickChkMusic)
	UIClick(chkEffect, SetView::clickChkEffect)


	BTN_ADD_TOUCH_EVENTLISTENER(Button,SetView, closeBtn, 14001, "closeBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, SetView, reLoginBtn, 14005, "reLoginBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, SetView, helpBtn, 14006, "helpBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(ImageView, SetView, Image_38, 14001, "Image_38", NULL)
}

SetView::~SetView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, closeBtn, 14001);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, reLoginBtn, 14005);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, helpBtn, 14006);
	BTN_REMOVE_TOUCH_EVENTLISTENER(SetView, Image_38, 14001);


	delete rootNode;
	rootNode = NULL;
}

void SetView::initView()
{
	chkMusic->setSelected(MusicService::getInstance()->isMusicOn);
	chkEffect->setSelected(MusicService::getInstance()->isEffectOn);
}

void SetView::clickChkMusic(Ref* pSender)
{
	if (MusicService::getInstance()->isMusicOn)
	{
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		MusicService::getInstance()->isMusicOn = false;
	}
	else
	{
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		MusicService::getInstance()->isMusicOn = true;
	}
	UserDefault::getInstance()->setBoolForKey("MusicOn", MusicService::getInstance()->isMusicOn);
	UserDefault::getInstance()->flush();
}

void SetView::clickChkEffect(Ref* pSender)
{
	if (MusicService::getInstance()->isEffectOn)
	{
		MusicService::getInstance()->isEffectOn = false;
	} 
	else
	{
		MusicService::getInstance()->isEffectOn = true;
	}
	UserDefault::getInstance()->setBoolForKey("EffectOn", MusicService::getInstance()->isEffectOn);
	UserDefault::getInstance()->flush();
}