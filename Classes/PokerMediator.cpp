#include "PokerMediator.h"
#include "SGTools.h"

PokerMediator::PokerMediator(int id, bool isOutPoker, int desk, int DuiNum, int ZhangNum, int DuiAllNum, int ZhangAllNum, int isChangePos,bool isGongP)
{
	isPlayerOutPoker = isOutPoker;
	deskPos = desk;
	Dui = DuiNum;
	Zhang = ZhangNum;
	DuiAll = DuiAllNum;
	ZhangAll = ZhangAllNum;

	//
	poker.pokerNum = PokerLogic::getPokerNum(id);
	poker.pokerNum2 = PokerLogic::getPokerNum2(id);
	poker.pokerHuaSe = PokerLogic::getPokerHuaSe(id);
	poker.pokerID = id;
	poker.pokerID2 = ZhangNum;
	poker.isChangePosition = isChangePos;
	poker.isRemoveView = false;
	poker.isGongPai = isGongP;
	GameDataModel *gameDataModel = (GameDataModel*)getModel(GameDataModel::NAME);
	//
	if (!isPlayerOutPoker)
	{
		poker.isSelected = false;
		poker.canSelect = true;
		poker.deskID = -1;

		//��ӵ��ҵ�����
		gameDataModel->player[0].pokerArr.push_back(&poker);
	}
	else
	{
		poker.isSelected = false;
		poker.canSelect = false;
		poker.deskID = deskPos;
		//��ӵ���Ӧ��ұ��ֳ�����
		gameDataModel->player[deskPos].outPokerArr.push_back(&poker);
		//��ӵ���Ӧ��ұ��ֳ�����
		gameDataModel->player[deskPos].allOutPokerArrID.push_back(&(poker.pokerID));
	}
}

PokerMediator::~PokerMediator()
{
	delete getView();
	setView(NULL);
}

/*
��ʼִ�к���
*/
void PokerMediator::OnRegister()
{
	pokerView = (PokerView*)getView();
	pokerView->initView(poker.isGongPai, Dui);

	//�������
	if (!isPlayerOutPoker)
	{
		//������Ӧע��
		touchListener = EventListenerTouchOneByOne::create();//�������㴥���¼�������
		touchListener->onTouchBegan = CC_CALLBACK_2(PokerMediator::onTouchBegan, this);//������ʼ
		//touchListener->onTouchEnded = CC_CALLBACK_2(PokerMediator::onTouchEnd, this);   //��������
//		touchListener->onTouchMoved = CC_CALLBACK_2(PokerMediator::onTouchMoved, this);  //�����ƶ�
		touchListener->setSwallowTouches(true);//�����̲�����
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, getView()->rootNode);//ע��ַ���

		//�����Ƶ�λ��
		Size size = Director::getInstance()->getVisibleSize();
		if (pkWidth * DuiAll > 600 * size.width / 960)
		{
			pkJianJu = pkWidth - (pkWidth * DuiAll - 600 * size.width / 960) / (DuiAll - 1);
		}
		else  //Dui = 6��ʼ 6.89
		{
			pkJianJu = pkWidth;
		}
		float posx = (size.width - 360 * size.width / 960 - (DuiAll - 1) * pkJianJu - pkWidth) / 2 + 360 * size.width / 960 + (Dui - 1)*pkJianJu;
		float posy = 100 + 30 * (ZhangAll - Zhang - 1);
		getView()->rootNode->setPosition(Vec2(posx, posy));
		logV("jianju %d,x %f,y %f duiAll %d, dui %d, zhangAll %d, zhang %d", 
			pkJianJu, posx, posy, DuiAll, Dui, ZhangAll, Zhang);
	}

	//��ҳ�����
	else
	{
		Size size = Director::getInstance()->getVisibleSize();
		int num = 0;
		GameDataModel *gameDataModel  = ((GameDataModel*)getModel(GameDataModel::NAME));
		//�����Ƶ�λ��
		switch (deskPos)
		{
			//�����
			case 0:
				num = gameDataModel->player[0].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 2 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, 200));
				getView()->rootNode->setScale(0.5);
				break;
			//�ұߵ����
			case 3:
				num = gameDataModel->player[3].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width * 3 / 4 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, size.height * 2 / 5));
				getView()->rootNode->setScale(0.5);
				break;
			//��������
			case 2:
				num = gameDataModel->player[2].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 2 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, 280));
				getView()->rootNode->setScale(0.5);
				break;
			//��ߵ����
			case 1:
				num = gameDataModel->player[1].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 4 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, size.height * 2 / 5));
				getView()->rootNode->setScale(0.5);
				break;
		}
	}
}

/*
����ִ�к���
*/
void PokerMediator::onRemove()
{
	//�Ƴ�������Ӧ
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(getView()->rootNode);
}

/*
�¼���Ӧ����
*/
void PokerMediator::onEvent(int i, void* data)
{
	//int* id = static_cast<int*>(data);
	pokeridData Data;
	int opacity;
	//
	switch (i)
	{
		//
		case EventType::POKER_GONG_PAI_STATE:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				poker.isGongPai = true;
				pokerView = (PokerView*)getView();
				pokerView->changeToGongPai();
			}
			break;

		//��Ҫ�ı����Ƶ�ѡ��״̬
		case EventType::CHANGE_POKER_STATE:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				if (this->poker.isSelected)
					SelectPkSuoTou();
				else
					SelectPkLuTou();
			}
			break;
		//���������Ƴ�������
		case EventType::REMOVE_POKER:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				removeView(this);
			}
			break;
		//�Ƴ��Ƶ���ʾ
		case EventType::REMOVE_POKER_VIEW:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				getLayer()->removeChild(getView());
				poker.isRemoveView = true;
			}
			break;
		//�ı����Ƶ�λ��
		case EventType::CHANGE_POKER_POSITION:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				changePokerPosition();
			}
			break;
		//��������Ƶ���ʾ
		case EventType::REMOVE_OUT_POKER:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && this->poker.deskID == Data.deskID && isPlayerOutPoker && !poker.isRemoveView)
			{
				//removeView(this);
				getLayer()->removeChild(getView());
				poker.isRemoveView = true;
			}
			break;
		case EventType::SET_POKER_OPACITY:
			opacity = *(int*)(data);
			if (!isPlayerOutPoker && !poker.isRemoveView)
			{
				getView()->rootNode->setOpacity(opacity);
			}
			break;
		case EventType::GAME_OVER:
		case EventType::BACK_TO_HALL:
			removeView(this);
			break;
		default:
			break;
	}
}

/*
	�����Ƶ���ʾ��
*/
Layer* PokerMediator::getLayer()
{
	if (isPlayerOutPoker)
		return ((UILayerService*)getService(UILayerService::NAME))->outPokerLayer;
	else
		return ((UILayerService*)getService(UILayerService::NAME))->myPokerLayer;
}

//������
bool PokerMediator::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	Size size = getView()->rootNode->getChildByName("Sprite")->getContentSize();
	Rect rect(-size.width / 2, -size.height / 2, size.width, size.height);
	Point ptouch = getView()->rootNode->convertTouchToNodeSpaceAR(pTouch); //ת�� ���� �� �ڵ�ռ�
	if (rect.containsPoint(ptouch) && this->poker.canSelect)
	{
		if (!this->poker.isSelected){
			SelectPkLuTou();
		}
		else{

			SelectPkSuoTou();
		}
		return true;
	}
	return false;
	//������ﷵ��false���������̵�
}

void PokerMediator::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	Size size = getView()->rootNode->getChildByName("Sprite")->getContentSize();
	Rect rect(-size.width / 2, -size.height / 2, size.width, size.height);
	Point ptouch = getView()->rootNode->convertTouchToNodeSpaceAR(pTouch); //ת�� ���� �� �ڵ�ռ�
	if (rect.containsPoint(ptouch) && this->poker.canSelect)
	{
		if (!this->poker.isSelected){
			SelectPkLuTou();
		}
		else{

			SelectPkSuoTou();
		}
	}
	//������ﷵ��false���������̵�
}

void PokerMediator::onTouchEnd(Touch *pTouch, Event *pEvent)
{
// 	Size size = getView()->rootNode->getChildByName("Sprite")->getContentSize();
// 	Rect rect(-size.width / 2, -size.height / 2, size.width, size.height);
// 	Point ptouch = getView()->rootNode->convertTouchToNodeSpaceAR(pTouch); //ת�� ���� �� �ڵ�ռ�
// 	if (rect.containsPoint(ptouch) && this->poker.canSelect)
// 	{
// 		if (!this->poker.isSelected){
// 			SelectPkLuTou();
// 		}
// 		else{
// 
// 			SelectPkSuoTou();
// 		}
// 		return true;
// 	}
// 	return false;
// 	//������ﷵ��false���������̵�

}

//
void PokerMediator::SelectPkLuTou(){
	this->poker.isSelected = true;
	//getView()->rootNode->setPosition(Vec2(getView()->rootNode->getPositionX(), getView()->rootNode->getPositionY() + 10));
	//������Ӱ
	getView()->rootNode->setColor(Color3B(128, 128, 128));

	//��ӵ�ѡ��Ҫ��������
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	gameDataModel->player[0].selectedPokerArr.push_back(&(this->poker));

	//
	blueSkyDispatchEvent(10624);
}

//
void PokerMediator::SelectPkSuoTou(){
	this->poker.isSelected = false;
	//getView()->rootNode->setPosition(Vec2(getView()->rootNode->getPositionX(), getView()->rootNode->getPositionY() - 10));
	getView()->rootNode->setColor(Color3B(255, 255, 255));

	//��ѡ��Ҫ���������Ƴ�֮
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	gameDataModel->removeMySelectedPokerArr(&(this->poker));

	//
	if (gameDataModel->player[0].selectedPokerArr.size() == 0)
	{
		blueSkyDispatchEvent(10623);
	}
}

//�����Ƶ�λ��
void PokerMediator::changePokerPosition()
{

	vector<vector<PokerVO*>> pokerDui = PokerLogic::reFenPokerArr(((GameDataModel*)getModel(GameDataModel::NAME))->player[0].pokerArr);

	DuiAll = pokerDui.size();
	for (int i = 0; i < DuiAll; i++)
	{
		for (DWORD j = 0; j < pokerDui.at(i).size(); j++)
		{
			if (this->poker.pokerID == pokerDui.at(i).at(j)->pokerID && this->poker.pokerID2 == pokerDui.at(i).at(j)->pokerID2)
			{
				Dui = i;
				Zhang = j;
				ZhangAll = pokerDui.at(i).size();
				break;
			}
		}
	}
	Size size = Director::getInstance()->getVisibleSize();
	if (pkWidth * DuiAll > 600 * size.width / 960)
	{
		pkJianJu = pkWidth - (pkWidth * DuiAll - 600 * size.width / 960) / (DuiAll - 1);
	}
	else
	{
		pkJianJu = pkWidth;
	}
	getView()->rootNode->setPosition(Vec2((size.width - 360 * size.width / 960 - (DuiAll - 1) * pkJianJu - pkWidth) / 2 + 360 * size.width / 960 + (Dui - 1)*pkJianJu, 100 + 30 * (ZhangAll - Zhang - 1)));
}
