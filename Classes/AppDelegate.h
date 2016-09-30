#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"
#include "BlueSky.h"
#include "UILayerService.h"

#include "GameStartCommand.h"
#include "SocketInitCommand.h"
#include "NetDataCommand.h"
#include "EventType.h"
#include "SendPokerCommand.h"
#include "SendDataService.h"
#include "RoomListModel.h"
#include "DataManager.h"
#include "GameDataModel.h"
#include "OutPokerCommand.h"
#include "LoginCompleteCommand.h"
#include "ConnectGameServiceCommand.h"
#include "InDeskService.h"
#include "PlayerInDeskModel.h"
#include "PokerGameModel.h"
#include "GameOverCommand.h"
#include "GetJingGongCommand.h"
#include "ReShowPokerCommand.h"
#include "MusicService.h"
#include "RegistCharacterCommand.h"
#include "AlertCommand.h"
#include "ReSortPokerCommand.h"
#include "ShowChatCommand.h"
#include "ShowDaoJuActionCommand.h"


/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  AppDelegate : private cocos2d::Application, public BlueSkyContext
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();
private:
	void init();
	void initModel();
	void initService();
	void initCommand();
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
};
#endif // _APP_DELEGATE_H_

