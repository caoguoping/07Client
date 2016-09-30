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

		//添加到我的手牌
		gameDataModel->player[0].pokerArr.push_back(&poker);
	}
	else
	{
		poker.isSelected = false;
		poker.canSelect = false;
		poker.deskID = deskPos;
		//添加到对应玩家本轮出的牌
		gameDataModel->player[deskPos].outPokerArr.push_back(&poker);
		//添加到对应玩家本局出的牌
		gameDataModel->player[deskPos].allOutPokerArrID.push_back(&(poker.pokerID));
	}
}

PokerMediator::~PokerMediator()
{
	delete getView();
	setView(NULL);
}

/*
开始执行函数
*/
void PokerMediator::OnRegister()
{
	pokerView = (PokerView*)getView();
	pokerView->initView(poker.isGongPai, Dui);

	//玩家手牌
	if (!isPlayerOutPoker)
	{
		//触摸响应注册
		touchListener = EventListenerTouchOneByOne::create();//创建单点触摸事件监听器
		touchListener->onTouchBegan = CC_CALLBACK_2(PokerMediator::onTouchBegan, this);//触摸开始
		//touchListener->onTouchEnded = CC_CALLBACK_2(PokerMediator::onTouchEnd, this);   //触摸结束
//		touchListener->onTouchMoved = CC_CALLBACK_2(PokerMediator::onTouchMoved, this);  //触摸移动
		touchListener->setSwallowTouches(true);//向下吞并触摸
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, getView()->rootNode);//注册分发器

		//设置牌的位置
		Size size = Director::getInstance()->getVisibleSize();
		if (pkWidth * DuiAll > 600 * size.width / 960)
		{
			pkJianJu = pkWidth - (pkWidth * DuiAll - 600 * size.width / 960) / (DuiAll - 1);
		}
		else  //Dui = 6开始 6.89
		{
			pkJianJu = pkWidth;
		}
		float posx = (size.width - 360 * size.width / 960 - (DuiAll - 1) * pkJianJu - pkWidth) / 2 + 360 * size.width / 960 + (Dui - 1)*pkJianJu;
		float posy = 100 + 30 * (ZhangAll - Zhang - 1);
		getView()->rootNode->setPosition(Vec2(posx, posy));
		logV("jianju %d,x %f,y %f duiAll %d, dui %d, zhangAll %d, zhang %d", 
			pkJianJu, posx, posy, DuiAll, Dui, ZhangAll, Zhang);
	}

	//玩家出的牌
	else
	{
		Size size = Director::getInstance()->getVisibleSize();
		int num = 0;
		GameDataModel *gameDataModel  = ((GameDataModel*)getModel(GameDataModel::NAME));
		//设置牌的位置
		switch (deskPos)
		{
			//本玩家
			case 0:
				num = gameDataModel->player[0].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 2 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, 200));
				getView()->rootNode->setScale(0.5);
				break;
			//右边的玩家
			case 3:
				num = gameDataModel->player[3].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width * 3 / 4 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, size.height * 2 / 5));
				getView()->rootNode->setScale(0.5);
				break;
			//对面的玩家
			case 2:
				num = gameDataModel->player[2].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 2 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, 280));
				getView()->rootNode->setScale(0.5);
				break;
			//左边的玩家
			case 1:
				num = gameDataModel->player[1].outPokerArr.size();
				getView()->rootNode->setPosition(Vec2(size.width / 4 - (4 / 2 * pkJianJu2) + (num - 1)*pkJianJu2, size.height * 2 / 5));
				getView()->rootNode->setScale(0.5);
				break;
		}
	}
}

/*
结束执行函数
*/
void PokerMediator::onRemove()
{
	//移除触摸响应
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(getView()->rootNode);
}

/*
事件响应函数
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

		//需要改变手牌的选中状态
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
		//在手牌中移除这张牌
		case EventType::REMOVE_POKER:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				removeView(this);
			}
			break;
		//移除牌的显示
		case EventType::REMOVE_POKER_VIEW:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				getLayer()->removeChild(getView());
				poker.isRemoveView = true;
			}
			break;
		//改变手牌的位置
		case EventType::CHANGE_POKER_POSITION:
			Data = *(pokeridData*)(data);
			if (Data.pokerID == this->poker.pokerID && Data.pokerID2 == this->poker.pokerID2 && !isPlayerOutPoker && !poker.isRemoveView)
			{
				changePokerPosition();
			}
			break;
		//清除出的牌的显示
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
	设置牌的显示层
*/
Layer* PokerMediator::getLayer()
{
	if (isPlayerOutPoker)
		return ((UILayerService*)getService(UILayerService::NAME))->outPokerLayer;
	else
		return ((UILayerService*)getService(UILayerService::NAME))->myPokerLayer;
}

//触摸牌
bool PokerMediator::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	Size size = getView()->rootNode->getChildByName("Sprite")->getContentSize();
	Rect rect(-size.width / 2, -size.height / 2, size.width, size.height);
	Point ptouch = getView()->rootNode->convertTouchToNodeSpaceAR(pTouch); //转换 触摸 到 节点空间
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
	//如果这里返回false触摸不被吞掉
}

void PokerMediator::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	Size size = getView()->rootNode->getChildByName("Sprite")->getContentSize();
	Rect rect(-size.width / 2, -size.height / 2, size.width, size.height);
	Point ptouch = getView()->rootNode->convertTouchToNodeSpaceAR(pTouch); //转换 触摸 到 节点空间
	if (rect.containsPoint(ptouch) && this->poker.canSelect)
	{
		if (!this->poker.isSelected){
			SelectPkLuTou();
		}
		else{

			SelectPkSuoTou();
		}
	}
	//如果这里返回false触摸不被吞掉
}

void PokerMediator::onTouchEnd(Touch *pTouch, Event *pEvent)
{
// 	Size size = getView()->rootNode->getChildByName("Sprite")->getContentSize();
// 	Rect rect(-size.width / 2, -size.height / 2, size.width, size.height);
// 	Point ptouch = getView()->rootNode->convertTouchToNodeSpaceAR(pTouch); //转换 触摸 到 节点空间
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
// 	//如果这里返回false触摸不被吞掉

}

//
void PokerMediator::SelectPkLuTou(){
	this->poker.isSelected = true;
	//getView()->rootNode->setPosition(Vec2(getView()->rootNode->getPositionX(), getView()->rootNode->getPositionY() + 10));
	//蒙上阴影
	getView()->rootNode->setColor(Color3B(128, 128, 128));

	//添加到选的要出的牌中
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

	//在选的要出的牌中移除之
	GameDataModel* gameDataModel = ((GameDataModel*)getModel(GameDataModel::NAME));
	gameDataModel->removeMySelectedPokerArr(&(this->poker));

	//
	if (gameDataModel->player[0].selectedPokerArr.size() == 0)
	{
		blueSkyDispatchEvent(10623);
	}
}

//调整牌的位置
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
