#ifndef  _MessageShowView_
#define  _MessageShowView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"
#include "UTF8.h"

class  MessageShowView : public BlueSkyView
{
public:
	MessageShowView();
	~MessageShowView();

	void initView();

	//type:���ͣ�1�������ʯ��2����ý�ң�3����õ��ߣ�
	void showMessage(int type,string name);


	void hideMessage();

private:
	ImageView* Image_38;
	Button   * getBtn  ;
	Button   * closeBtn;
	//
	Text* txtGold;
	Text* txtDiamond;
	Text* txtProp;   //������Ϣ


};

#endif