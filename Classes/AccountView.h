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
	void clickBtnBack(Ref*  pSender);
	void clickBtnContinune(Ref*  pSender);
	void clickBtnNextMatch(Ref*  pSender);
public:
	Layout*  winLayout;    //����ʤ������
	Layout*  loseLayout;   //����ʧ�ܽ���
	Text*    txtRanks;    //����
	Text*    txtBestRanks;  //�������
	Text*   txtPeoples;   //�����˳�����

	Text*   txtRewards;   //�������

	Button  *btnBack, *btnContinue, *btnNextMatch;
	//ʧ�ܶ���
	cocostudio::timeline::ActionTimeline* failAction;
	Node* failActionNode;

	//ʤ������
	ParticleSystemQuad* winParticle;
	ParticleSystemQuad* glodParticle;

	void showSuccessAction(float dt);
};

#endif