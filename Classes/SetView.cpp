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

    Button  *closeBtn,  *reLoginBtn,  *helpBtn;
    ImageView*   imgClose;
    UIGet_Button("closeBtn", rootNode, closeBtn)
    UIGet_Button("reLoginBtn", rootNode, reLoginBtn)
    UIGet_Button("helpBtn", rootNode, helpBtn)
    UIGet_ImageView("Image_38", rootNode, imgClose)
    
    closeBtn->addClickEventListener([this](Ref*  pSender)
                                    {
                                        blueSkyDispatchEvent(14001);
                                    });

    reLoginBtn->addClickEventListener([this](Ref*  pSender)
                                    {
                                        blueSkyDispatchEvent(14005);
                                    });
    

    helpBtn->addClickEventListener([this](Ref*  pSender)
                                    {
                                        blueSkyDispatchEvent(14006);
                                    });
    

    imgClose->addClickEventListener([this](Ref*  pSender)
                                    {
                                        blueSkyDispatchEvent(14001);
                                    });
    
}

SetView::~SetView()
{
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
