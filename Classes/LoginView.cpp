#include "LoginView.h"
#include "SGTools.h"

LoginView::LoginView()
{
	logP
	rootNode = CSLoader::createNode("LoginScene.csb");
	logV("after LoginView csb");
	addChild(rootNode);


}

LoginView::~LoginView()
{

}
void LoginView::runLogo()
{
	blueSkyDispatchEvent(10003);
}
