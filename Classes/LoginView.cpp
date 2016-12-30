#include "LoginView.h"
#include "SGTools.h"
#include "ViewManager.h"
#include "TCPSocketService.h"
#include "SendDataService.h"
#include "DataManager.h"
#include "SocketInitCommand.h"


LoginView::LoginView()
{
	rootNode = CSLoader::createNode("LoginScene.csb");
	addChild(rootNode);


}

LoginView::~LoginView()
{

}
void LoginView::runLogo()
{
	blueSkyDispatchEvent(10003);
}

void LoginView::createRoleTest()
{
	schedule(schedule_selector(LoginView::createRoleUpdate), 10.0f);
}

void LoginView::delayCreateRoleTest()
{
 	DATA->dwRoleCreate++;
	SEND->sendRegisterTest(DATA->dwRoleCreate);
// 	registLogin *rLogin = new registLogin();
// 	rLogin->type = 2;
// 	rLogin->szAccounts = "adsfljliijk";
// 	rLogin->szLogonPass = "123543444";
// 	blueSkyDispatchEvent(EventType::SOCKET_INIT, rLogin);
}

void LoginView::createRoleUpdate(float dt)
{
	DATA->dwRoleCreate++;
// 	registLogin *rLogin = new registLogin();
// 	rLogin->type = 1;
// 	rLogin->szAccounts = "adsfljliijk";
// 	rLogin->szLogonPass = "123543444";
// 	blueSkyDispatchEvent(EventType::SOCKET_INIT, rLogin);
	SEND->sendLoginTest(DATA->dwRoleCreate);
	FiniteTimeAction* seq = Sequence::create(
		DelayTime::create(5.0f),
		CallFunc::create(CC_CALLBACK_0(LoginView::delayCreateRoleTest,this)),
		NULL
		);
	this->runAction(seq);

}
