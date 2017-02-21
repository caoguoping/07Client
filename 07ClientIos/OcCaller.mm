
#include "OcCaller.h"
//
//using namespace std;
//USING_NS_CC;
#import "GameIapStore.h"

static OcCaller *caller = NULL;
static GameIapStore*   iap = NULL;

OcCaller::OcCaller()
{

}

OcCaller *OcCaller::getInstance()
{
	if (!caller)
	{
		caller = new OcCaller();
        iap = [[GameIapStore alloc] init];
	}
	return caller;
}

void OcCaller::SDKLogin()
{
    [iap SDKLogin];
}

void OcCaller::activeCharge()
{
    [iap activeCharge];
}

void OcCaller::ChargeHandle(int goodsId)
{
    [iap ChargeHandle:goodsId];
}






