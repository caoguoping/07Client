#ifndef  _GongPaiActionView_
#define  _GongPaiActionView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  GongPaiActionView : public BlueSkyView
{
public:
	GongPaiActionView(int pokerID = -1);
	~GongPaiActionView();

	void initView(int fromUserID = -1, int toUserID = -1);

private:

	void remove();
};

#endif