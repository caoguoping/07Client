#ifndef  _AccountView_
#define  _AccountView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  AccountView : public BlueSkyView
{
public:
	AccountView();
	~AccountView();

	void initView();
	void playAccountAction(bool isSuccess);

public:
	Layout*  winLayout;    //����ʤ������
	Layout*  loseLayout;   //����ʧ�ܽ���
	Text*    txtRanks;    //����
	Text*    txtBestRanks;  //�������
	Text*   txtPeoples;   //�����˳�����

	Text*   txtRewards;   //�������
private:
	BTN_TOUCH_HANDLE(Button, fanHuiBtn, 10501);
	BTN_TOUCH_HANDLE(Button, continueBtn, 10502);
	//BTN_TOUCH_HANDLE(ImageView, Image_1, 10501);
	BTN_TOUCH_HANDLE(Button, nextMatchBtn, 10503);

	//ʧ�ܶ���
	cocostudio::timeline::ActionTimeline* failAction;
	Node* failActionNode;

	//ʤ������
	ParticleSystemQuad* winParticle;
	ParticleSystemQuad* glodParticle;

	void showSuccessAction(float dt);
};

#endif