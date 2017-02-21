package org.cocos2dx.cpp;

public class SDKPlugin{
	
	static native void LoginCallback(String uid, String access_token);
	static native void paySecessCallback(String orderNum, String save);   //充值成功回调
}
