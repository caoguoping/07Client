#ifndef _CGPTOOLS_H_
#define _CGPTOOLS_H_
#include "cocos2d.h"
#include "BlueSky.h"
/*#include "cocos2d/cocos/ui/UIWidget.h"*/


#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>

USING_NS_CC;
//using namespace ui;
using namespace std;



#define   DWORD unsigned int   
#define   WORD  unsigned short 
#define   BYTE  unsigned char  
#define   SCORE  long long								//积分类型
#define   LONG  int            
#define   TCHAR unsigned  short



#define UIGet_Layout(itemName, father, me)      me = static_cast<Layout*>(father->getChildByName(itemName));
#define UIGet_Label(itemName, father, me)       me = static_cast<Label*>(father->getChildByName(itemName));
#define UIGet_Button(itemName, father, me)      me = static_cast<Button*>(father->getChildByName(itemName));
#define UIGet_ImageView(itemName, father, me)   me = static_cast<ImageView*>(father->getChildByName(itemName));
#define UIGet_LoadingBar(itemName, father, me)  me = static_cast<LoadingBar*>(father->getChildByName(itemName));
#define UIGet_Slider(itemName, father, me)      me = static_cast<Slider*>(father->getChildByName(itemName));
#define UIGet_ListView(itemName, father, me)    me = static_cast<ListView*>(father->getChildByName(itemName));
#define UIGet_PageView(itemName, father, me)    me = static_cast<PageView*>(father->getChildByName(itemName));
#define UIGet_ScrollView(itemName, father, me)  me = static_cast<ScrollView*>(father->getChildByName(itemName));
#define UIGet_Armature(itemName, father, me)    me = static_cast<Armature*>(father->getChildByName(itemName));
#define UIGet_TextField(itemName, father, me)    me = static_cast<TextField*>(father->getChildByName(itemName));
#define UIGet_Text(itemName, father, me)    me = static_cast<Text*>(father->getChildByName(itemName));
#define UIGet_Node(itemName, father, me)    me = static_cast<Node*>(father->getChildByName(itemName));
#define UIGet_ParticleSystemQuad(itemName, father, me)    me = static_cast<ParticleSystemQuad*>(father->getChildByName(itemName));
#define UIGet_TextBMFont(itemName, father, me)    me = static_cast<TextBMFont*>(father->getChildByName(itemName));
#define UIGet_CheckBox(itemName, father, me)    me = static_cast<CheckBox*>(father->getChildByName(itemName));
#define UIGet_Sprite(itemName, father, me)    me = static_cast<Sprite*>(father->getChildByName(itemName));




//sequences frames
#define UIFrameDef(name)  cocostudio::timeline::ActionTimeline*  name##Timeline; \
	Node*  name##Node;

#define UIFrameInit(name) 	name##Node = NULL;

#define UIFrameCreate(name, CsbName,father,loop) name##Timeline = CSLoader::createTimeline(CsbName); \
	name##Node = CSLoader::createNode(CsbName); \
	father->addChild(name##Node); \
	father->runAction(name##Timeline); \
	name##Timeline->gotoFrameAndPlay(0, loop);

#define UIFrameRemove(name, father) 	if (name##Node) \
{ \
	father->stopAction(name##Timeline); \
	name##Node->removeFromParentAndCleanup(true); \
	name##Node = NULL; \
}

#define UIClick(itemName, callFunc) itemName->addClickEventListener(CC_CALLBACK_1(callFunc, this));
#define UIClickCheck(itemName, callFunc) itemName->addEventListener(CC_CALLBACK_2(callFunc, this));

#define UIDisableClick(itemName, className, funcName) 	itemName->setTouchEnabled(false); \
	this->scheduleOnce(schedule_selector(className::funcName), 0.5f);
#define UIEnableClick(itemName, className, funcName) void className::funcName(float dt) \
{ \
	itemName->setTouchEnabled(true); \
}

#define UIDefClick(classType ,name) classType * mBtn##name;  void clickBtn##name(Ref*  psender);

//延迟0.5s可以再次点击的
#define UIDefDelayClick(classType, name) classType * mBtn##name;  void clickBtn##name(Ref*  psender); \
	void enableBtn##name(float dt);


#define HScreen (Director::getInstance()->getWinSize().height)
#define WScreen (Director::getInstance()->getWinSize().width)




#define SYSMSG_TAGBEGIN   70000    //sysMsg tag 开始
#define SYSMSG_TAGBEGIN_TOUMING 71000
class Tools :public Node, public BlueSkyCommand
{

public:
	static Tools*  getInstance();
	void initTools(void);
	void showSysMsg(std::string msg, std::function<void(Ref*)> callFunc);
	void showSysMsgTouming(std::string msg, float x = 0, float y = 0);
	void closeSysMsgTouming(Node*  psender);
	void closeSysMsg(Ref*  psender);
	static void shakeWnd(Node* layout);
	static string parseInt2String(int param);
	static string parseLL2String(long long param);
	static int parseString2Int(string& param);
	static void split(const string& src, const string& separator, vector<string>& dest);
    static int createRandom(int start , int end);    
    static bool isDayOrLight();     

    static string getFileByName(string pFileName);
    
	
	// 格式化时间返回
	static void getCurrentTime(char* times);
	// 获取系统毫秒时间
	static double getMillSecond();


	//写文件
	static void logFile(const char * lpFormat, ...);
    static bool saveFile(const char* pContent,string pFileName);
	static bool myWriteFile(const char* pcontent);
	static bool createFileLog(char* pcontent, unsigned short mainCmd = 0, unsigned short subCmd = 0);
    
};

#define LogFile( format,  ... )  Tools::logFile(format,   ##__VA_ARGS__); 
#define  MYFileInfo(mainCmd, subCmd) // 	sprintf(tempTemp, "%s %s:%d  main %d sub %d\n", __FILE__, __FUNCTION__, __LINE__, mainCmd, subCmd);
#define  MyWriteFile  //Tools::myWriteFile;

#define PRINT_LOG 1
#if(PRINT_LOG == 1)

//打印过程
#define logP log("cocos2d-x %s %s %d", __FILE__, __FUNCTION__, __LINE__);	
//打印其他
#define logV log
#define logT char temp[64]; Tools::getCurrentTime(temp); log("cocos2d-x %s %s", temp, __FUNCTION__);
#else
#define logP //
#define logV //
#define logT //
#endif



#endif



