#include "LoginView.h"
#include "SGTools.h"
#include "ViewManager.h"


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
