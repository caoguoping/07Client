#include "AppDelegate.h"
#include "DataManager.h"
#include "ViewManager.h"
#include "TCPSocketService.h"
#include "SGTools.h"


USING_NS_CC;

void AppDelegate::init()
{
	logF("\n   GuanDan app is start  \n");
	logV("\n   GuanDan app is start  \n");
	srand((unsigned)time(NULL));   //随机数时间种子
	logV("cocos2d-x %s", FileUtils::getInstance()->getWritablePath().c_str());
	initModel();
	initService();
	initCommand();
	blueSkyDispatchEvent(EventType::GAME_START);
	
	
	DATA;  //初始化DataManager
	//添加按键监听
	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = CC_CALLBACK_2(AppDelegate::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener,1);

}
void AppDelegate::initModel()
{
	registerModel(RoomListModel::NAME, new RoomListModel());
	registerModel(GameDataModel::NAME, new GameDataModel());
	registerModel(PlayerInDeskModel::NAME, new PlayerInDeskModel());
	registerModel(PokerGameModel::NAME, new PokerGameModel());
}
void AppDelegate::initService()
{
	registerService(UILayerService::NAME,new UILayerService());
	registerService(TCPSocketService::LOGIN, new TCPSocketService());
	registerService(TCPSocketService::GAME, new TCPSocketService());
	registerService(SendDataService::NAME, new SendDataService());
	registerService(InDeskService::NAME, new InDeskService());
}
void AppDelegate::initCommand()
{
	registerCommand(EventType::GAME_START,new GameStartCommand());
	registerCommand(EventType::SEND_POKER, new SendPokerCommand());
	registerCommand(EventType::REV_PLAYER_OUT_POKER, new OutPokerCommand());
	registerCommand(EventType::SOCKET_INIT, new SocketInitCommand());
	registerCommand(EventType::SOCKET_REC_DATA, new NetDataCommand());
	registerCommand(EventType::LOGIN_COMPLETE, new LoginCompleteCommand());
	registerCommand(EventType::CONNECT_GAME_SERVICE, new ConnectGameServiceCommand());
	registerCommand(EventType::GAME_OVER,new GameOverCommand());
	registerCommand(EventType::GET_JING_GONG, new GetJingGongCommand());
	registerCommand(EventType::RE_SHOW_POKER, new ReShowPokerCommand());
	registerCommand(EventType::REGIST_CHARACTER, new RegistCharacterCommand());
	registerCommand(EventType::RE_SORT_POKER, new ReSortPokerCommand());
	registerCommand(EventType::ALERT, new AlertCommand());
	registerCommand(EventType::CHAT, new ShowChatCommand());
	registerCommand(EventType::SHOW_DAO_JU_ACTION, new ShowDaoJuActionCommand());


}

void AppDelegate::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
		//监听返回键
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			blueSkyDispatchEvent(EventType::ALERT, new AlertVO(1, "warning", "warning1", 30000, -1));
			break;
		//监听menu键
		case EventKeyboard::KeyCode::KEY_MENU:
			break;
	}
}


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLViewImpl::createWithRect("guandan", Rect(0, 0, 960, 540));
		//glview = GLViewImpl::createWithRect("guandan", Rect(0, 0, 2208, 1242));
		director->setOpenGLView(glview);
	}

	director->getOpenGLView()->setDesignResolutionSize(960, 540, ResolutionPolicy::SHOW_ALL);
	//director->getOpenGLView()->setDesignResolutionSize(2208, 1242, ResolutionPolicy::SHOW_ALL);

	// turn on display FPS
	director->setDisplayStats(false);
	// set FPS. the default value is 1.0/60 if you don't call this
	//director->setAnimationInterval(1.0 / 60);

	FileUtils::getInstance()->addSearchPath("res");
	FileUtils::getInstance()->addSearchPath("res/CSB_POKER");
	FileUtils::getInstance()->addSearchPath("res/CSBS");
	FileUtils::getInstance()->addSearchPath("res/customPng");
	//FileUtils::getInstance()->addSearchPath("res/CSB_GuanDanPoker");
	// create a scene. it's an autorelease object
	auto scene = Scene::create();

	// run
	director->runWithScene(scene);
	constructor(scene);//注册主场景
	VIEW->mainScene = scene;
    VIEW->createLayer();

	init();
// 	glEnable(GL_POINT_SMOOTH);
// 	glEnable(GL_LINE_SMOOTH);

	//自定义事件
#if 0
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto customListener = EventListenerCustom::create("custom_event", CC_CALLBACK_1(HelloWorld::onCustomEvent, this));
	dispatcher->addEventListenerWithFixedPriority(customListener, 1);

	EventCustom event = EventCustom("custom_event");
	event.setUserData(NULL);
	dispatcher->dispatchEvent(&event);


	//事件响应函数
	void HelloWorld::onCustomEvent(EventCustom* event)
	{
		event->getUserData();
		CCLOG("onCustomEvent");
	}
#endif




	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
   // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();
	if (VIEW->nowViewTag == ViewManager::eViewMain)
	{
		PLayMUSIC(BG_MUSIC)
	}

}
