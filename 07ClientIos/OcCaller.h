//
//  OcCaller.h
//  GameSanGuo
//
//  Created by bugcode on 14-5-12.
//
//

#ifndef __GameSanGuo__OcCaller__
#define __GameSanGuo__OcCaller__



//#include "cocos2d.h"


/*
 
 内部的OC的调用都映射到此类,工程内部全部使用c++调用,外围适配类使用oc相关调用
 
 */

class OcCaller
{
public:
	OcCaller();
       // GameIapStore*   iap;
public:
	static OcCaller *getInstance();
    void SDKLogin();
    void activeCharge();
    void ChargeHandle(int goodsId);

};

#endif /* defined(__GameSanGuo__OcCaller__) */
