#include "AccountMediator.h"
#include "SGTools.h"
#include "TCPSocketService.h"
#include "DataManager.h"
#include "MusicService.h"
static DWORD   adwRewards[4] = { 10000, 6000, 2000, 1000 };
AccountMediator::AccountMediator(CMD_S_GameEnd data)
{
	if (DATA->bGameCate != DataManager::E_GameCateMatch)
	{
		//�Ȼ�ȡ��Ҷ�Ӧ�ķ���������ID
		PlayerInDeskModel *playerInDeskModel = ((PlayerInDeskModel*)getModel(PlayerInDeskModel::NAME));
		for (int i = 0; i < 4; i ++)
		{
			svrChairId[i] = playerInDeskModel->getServiceChairID(i);
			faceId[i] = playerInDeskModel->DeskPlayerInfo[svrChairId[i]].wFaceID;
			strNickName[i] = playerInDeskModel->DeskPlayerInfo[svrChairId[i]].szNickName;
			dwGold[i] = data.lGameScore[svrChairId[i]];
		}
		//��ȡ������ҵ�����(0~3)
		if (data.m_iGameResult[0] == 0 && data.m_iGameResult[1] == 0 && data.m_iGameResult[2] == 0 && data.m_iGameResult[3] == 0)
		{
			logV("all m_isGameResult 0");
			if (data.lGameScore[svrChairId[2]] < 0)
			{
				iGrade[0] = 0;
				iGrade[2] = 0;
			}
			else
			{
				iGrade[0] = 1;
				iGrade[2] = 1;
			}
		}
		else
		{
			for (int i = 0; i < 4; i ++)
			{
				iGrade[i] = data.Rank[svrChairId[i]];
			}
		}
		//��ʾ�Լ���ʤ�����
		if (iGrade[0] == 1 || iGrade[2] == 1)
		{
			isSuccess = true;
			((GameDataModel*)getModel(GameDataModel::NAME))->player[0].isSuccess = true;
		}
		else
		{
			isSuccess = false;
			((GameDataModel*)getModel(GameDataModel::NAME))->player[0].isSuccess = false;
		}
		DATA->myBaseData.lUserScore += data.lGameScore[svrChairId[0]];
	}
}

AccountMediator::AccountMediator()
{

}

AccountMediator::~AccountMediator()
{
	delete getView();
	setView(NULL);
}

void AccountMediator::OnRegister()
{
	accountView = (AccountView*)getView();
	accountView->initView();

	Size size = Director::getInstance()->getVisibleSize();
	getView()->rootNode->setPosition(size.width / 2, size.height / 2);

	if (DATA->bGameCate != DataManager::E_GameCateMatch )
	{
		//�ҵ���Ϸ������Ϣ
		successImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage1"));
		successImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage2"));
		failImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage1"));
		failImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage2"));
		UIGet_Sprite("Sprite_BloodSeccess", accountView->rootNode, SpBloodSeccess)
			UIGet_Sprite("Sprite_bloodNumSec", accountView->rootNode, SpBloodNumSec)
			UIGet_Sprite("Sprite_BloodFail", accountView->rootNode, SPBloodFail)
			UIGet_Sprite("Sprite_bloodNumFail", accountView->rootNode, SPBloodNumFail)
		
			grade = getView()->rootNode->getChildByName("grade");

		char temp[64];
		for (int i = 0; i < 4; i ++)
		{
			sprintf(temp, "NodeHead%d", i);
			UIGet_Node(temp, accountView->rootNode, ndHead[i])
				sprintf(temp, "Text_gold%d", i);
			UIGet_Text(temp, accountView->rootNode, txtGold[i])
				sprintf(temp, "Text_name%d", i);
			UIGet_Text(temp, accountView->rootNode, txtName[i])
				txtName[i]->setString(strNickName[i]);
			txtGold[i]->setString(Tools::parseInt2String(dwGold[i]));
			showHead(ndHead[i], faceId[i]);
			showGrade(iGrade[i]);
		}
		DATA->myBaseData.lUserScore += dwGold[0];

		successImage1->setVisible(isSuccess);
		failImage1->setVisible(!isSuccess);

		playAccountMusic(isSuccess);
		accountView->playAccountAction(isSuccess);

		successImage2->setVisible(false);
		failImage2->setVisible(false);
		SPBloodFail->setVisible(false);
		SPBloodNumFail->setVisible(false);
		SpBloodNumSec->setVisible(false);
		SpBloodSeccess->setVisible(false);

		if (DATA->bGameCate == DataManager::E_GameBlood && (DATA->GameEndData.bIsBlood == 1))
		{
				logV("blood throw");
				sprintf(temp, "lose%d.png", DATA->bGameCateSub);
				SPBloodNumFail->setTexture(temp);

				sprintf(temp, "win%d.png", DATA->bGameCateSub);
				SpBloodNumSec->setTexture(temp);

				SPBloodFail->setVisible(!isSuccess);
				SPBloodNumFail->setVisible(!isSuccess);

				SpBloodNumSec->setVisible(isSuccess);
				SpBloodSeccess->setVisible(isSuccess);
		}
		else
		{
			successImage2->setVisible(isSuccess);
			failImage2->setVisible(!isSuccess);
		}
	}
	else if (DATA->bGameCate == DataManager::E_GameCateMatch)  //��������
	{
		//����������Ϣ
		bool isSuccess;
		DWORD dwReword = 0;
		if (DATA->wCdRank > 0 && DATA->wCdRank < 5)  //1��4��
		{
			dwReword = adwRewards[(DATA->wCdRank) - 1];
			isSuccess = true;

		}
		else 
		{
			isSuccess = false;
		}
		successImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage1"));
		successImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("successImage2"));
		failImage1 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage1"));
		failImage2 = dynamic_cast<Sprite*>(getView()->rootNode->getChildByName("failImage2"));
		successImage1->setVisible(isSuccess);
		successImage2->setVisible(isSuccess);
		failImage1->setVisible(!isSuccess);
		failImage2->setVisible(!isSuccess);
		accountView->winLayout->setVisible(isSuccess);
		accountView->loseLayout->setVisible(!isSuccess);

		accountView->txtRanks->setString(Tools::parseInt2String(DATA->wCdRank));
		accountView->txtBestRanks->setString(Tools::parseInt2String(DATA->wBestRank));

		accountView->txtRewards->setString(Tools::parseInt2String(dwReword));

		playAccountMusic(isSuccess);
		accountView->playAccountAction(isSuccess);
		DATA->wMatchScore = 10;   //��һ������
		DATA->myBaseData.lUserScore += dwReword;
	}
}

/**
��������ִ�к���
*/
void AccountMediator::onRemove()
{

}

/*
�¼���Ӧ����
*//*
�¼���Ӧ����
*/
void AccountMediator::onEvent(int i, void* data)
{

	switch (i)
	{
	case 10501:
		removeView(this);
		break;

	}
}



//�ŵ����ֲ�
Layer* AccountMediator::getLayer()
{
	return ((UILayerService*)getService(UILayerService::NAME))->maskLayer;
}

//��ʾ���ͷ��
void AccountMediator::showHead(Node* head, int faceID)
{
	ImageView* image1 = dynamic_cast<ImageView*>(head->getChildByName("character_1"));
	ImageView* image2 = dynamic_cast<ImageView*>(head->getChildByName("character_2"));
	ImageView* image3 = dynamic_cast<ImageView*>(head->getChildByName("character_3"));
	ImageView* image4 = dynamic_cast<ImageView*>(head->getChildByName("character_4"));
	switch (faceID)
	{
	case 1:
		image1->setVisible(true);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 2:
		image1->setVisible(false);
		image2->setVisible(true);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 3:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(true);
		image4->setVisible(false);
		break;
	case 4:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(true);
		break;
	}
}

//��ʾ�������
void AccountMediator::showGrade(int rank)
{
	ImageView* image1 = dynamic_cast<ImageView*>(grade->getChildByName("first"));
	ImageView* image2 = dynamic_cast<ImageView*>(grade->getChildByName("second"));
	ImageView* image3 = dynamic_cast<ImageView*>(grade->getChildByName("third"));
	ImageView* image4 = dynamic_cast<ImageView*>(grade->getChildByName("fourth"));
	switch (iGrade[0])
	{
	case 0:
	case 4:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(true);
		break;
	case 1:
		image1->setVisible(true);
		image2->setVisible(false);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 2:
		image1->setVisible(false);
		image2->setVisible(true);
		image3->setVisible(false);
		image4->setVisible(false);
		break;
	case 3:
		image1->setVisible(false);
		image2->setVisible(false);
		image3->setVisible(true);
		image4->setVisible(false);
		break;
	}
}

//���Ž�����Ч
void AccountMediator::playAccountMusic(bool isSuccess)
{
	if (isSuccess)
	{
		PLayEffect(GAME_WIN)
	}
		
	else
	{
		PLayEffect(GAME_FAIL)
	}
	
}

