#include "SetView.h"
#include "SGTools.h"
#include "MusicService.h"
#include "ViewManager.h"

SetView::SetView()
{
	rootNode = CSLoader::createNode("set.csb");
	addChild(rootNode);

	cocostudio::timeline::ActionTimeline*  timeLine = CSLoader::createTimeline("set.csb");
	timeLine->gotoFrameAndPlay(0, false);
	rootNode->runAction(timeLine);

	Sprite*  spBg;
	UIGet_Sprite("ImageFrame", rootNode, spBg)

		UIGet_CheckBox("musicBtn", spBg, chkMusic)
		UIGet_CheckBox("effectBtn", spBg, chkEffect)
	UIClick(chkMusic, SetView::clickChkMusic)
	UIClick(chkEffect, SetView::clickChkEffect)

    Button  *closeBtn,  *reLoginBtn,  *helpBtn;
    ImageView*   imgClose;
	UIGet_Button("closeBtn", spBg, closeBtn)
		UIGet_Button("reLoginBtn", spBg, reLoginBtn)
		UIGet_Button("helpBtn", spBg, helpBtn)
		UIGet_ImageView("Image_38", rootNode, imgClose)
    
	BTN_EVENT(imgClose, 14001)
	BTN_EVENT(closeBtn, 14001)
	BTN_EVENT(reLoginBtn, 14005)
	BTN_EVENT(helpBtn, 14006)

	//ѹסplayerInfo
	imgClose->setGlobalZOrder(GOrderPlayerHead + 2);
	closeBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	reLoginBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	helpBtn->setGlobalZOrder(GOrderPlayerHead + 2);
	chkMusic->setGlobalZOrder(GOrderPlayerHead + 2);
	chkEffect->setGlobalZOrder(GOrderPlayerHead + 2);

   
}

SetView::~SetView()
{
	
}

void SetView::initView()
{
	chkMusic->setSelected(MusicService::getInstance()->isMusicOn);
	chkEffect->setSelected(MusicService::getInstance()->isEffectOn);
}

void SetView::clickChkMusic(Ref* pSender)
{
	PLayEffect(BUTTON_CLICK)
	if (MusicService::getInstance()->isMusicOn)
	{
		MusicService::getInstance()->isMusicOn = false;
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
	else
	{
		MusicService::getInstance()->isMusicOn = true;
		PLayMUSIC(BG_MUSIC)
	}
	UserDefault::getInstance()->setBoolForKey("MusicOn", MusicService::getInstance()->isMusicOn);
	UserDefault::getInstance()->flush();
}

void SetView::clickChkEffect(Ref* pSender)
{
	PLayEffect(BUTTON_CLICK)
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
