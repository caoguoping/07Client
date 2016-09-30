#include "OutPokerLogicRule.h"
#include "SGTools.h"

OutPokerLogicRule::OutPokerLogicRule()
{

}

OutPokerLogicRule::~OutPokerLogicRule()
{

}

/*
	判断出牌的牌型（错误牌型返回nullptr）
	数字需重小到大权重顺序排序
	1.单张 2.对子 3.3张  4.3带2 5.顺子 6.连队 7.飞机  8.炸弹 9.同花顺 10.火箭
*/
PokerTypeVO OutPokerLogicRule::outPokerType(vector<PokerVO*> outPokerArr)
{
	PokerTypeVO pokerType;

	int len = outPokerArr.size();

	//扑克容器
	vector<PokerVO*> pokerArr = {};

	//这边先将扑克按照牌值从小到大排序
	pokerArr = BubbleSort2(outPokerArr);

	//先判断是否是炸弹
	if (len >= 4)
	{
		pokerType = isBoom(pokerArr);
		if (pokerType.type != 0)
			return pokerType;
		//不是炸弹不能出超过6张牌
		else if (len > 6)
		{
			pokerType.type = 0;
			return pokerType;
		}
	}

	//连对、飞机
	if (len == 6)
	{
		//先判断是否是连队
		pokerType = isLianDui(pokerArr);
		if (pokerType.type != 0)
		{
			return pokerType;
		}
		//
		return (isFeiJi(pokerArr));
	}
	//顺子、三带二、同花顺
	else if (len == 5)
	{
		//先判断是否是三带二
		pokerType = isSanDaiEr(pokerArr);
		if (pokerType.type != 0)
			return pokerType;
		//在判断是否是同花顺
		pokerType = isTongHuaShun(pokerArr);
		if (pokerType.type != 0)
			return pokerType;
		//
		return (isShunZi(pokerArr));
	}
	//火箭
	else if (len == 4)
	{
		return (isHuoJian(pokerArr));
	}
	//3张
	else if (len == 3)
	{
		return (isSanZhang(pokerArr));
	}
	//对子
	else if (len == 2)
	{
		return (isDuiZi(pokerArr));
	}
	//单张
	else
	{
		return (isDanZhang(pokerArr));
	}

}

//这边先将扑克按照牌值从小到大排序
vector <PokerVO*> OutPokerLogicRule::BubbleSort(vector<PokerVO*> outpokerArr)
{
	//
	int len = outpokerArr.size();
	//从后往前冒泡
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			int pkID1 = outpokerArr.at(j)->pokerNum;
			int pkID2 = outpokerArr.at(j-1)->pokerNum;
			if (pkID1 < pkID2)
			{
				PokerVO* pk = outpokerArr.at(j);
				outpokerArr[j] = outpokerArr[j - 1];
				outpokerArr[j - 1] = pk;
			}
		}
	}
	return outpokerArr;
}

//这边先将扑克按照pokerNum2从小到大排序
vector <PokerVO*> OutPokerLogicRule::BubbleSort2(vector<PokerVO*> outpokerArr)
{
	//
	int len = outpokerArr.size();
	//从后往前冒泡
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			int pkID1 = outpokerArr.at(j)->pokerNum2;
			int pkID2 = outpokerArr.at(j - 1)->pokerNum2;
			if (pkID1 < pkID2)
			{
				PokerVO* pk = outpokerArr.at(j);
				outpokerArr[j] = outpokerArr[j - 1];
				outpokerArr[j - 1] = pk;
			}
		}
	}
	return outpokerArr;
}

//判断是否能跟上牌
bool OutPokerLogicRule::canFollowPoker(vector<PokerVO*> otherPokerIDArr, vector<PokerVO*> myPokerArray)
{
	//先判断出牌型
	PokerTypeVO otherPokerType = outPokerType(otherPokerIDArr);
	PokerTypeVO myPokerType = outPokerType(myPokerArray);

	//
	if (myPokerType.type == 0)
		return false;

	//先考虑别人的牌是炸弹的情况
	if (otherPokerType.type == 8)
	{
		//
		if (otherPokerType.len <= 5)
		{
			if (myPokerType.type == 9)
				return true;
			else
			{
				if (myPokerType.type == 8)
				{
					if (myPokerType.len == otherPokerType.len && myPokerType.value > otherPokerType.value)
						return true;
					if (myPokerType.len > otherPokerType.len)
						return true;
				}
			}
			return false;
		}
		else
		{
			if (myPokerType.type == 8)
			{
				if (myPokerType.len == otherPokerType.len && myPokerType.value > otherPokerType.value)
					return true;
				if (myPokerType.len > otherPokerType.len)
					return true;
			}
			return false;
		}
	}
	
	//接着考虑别人是同花顺的情况
	if (otherPokerType.type == 9)
	{
		if (myPokerType.type == 9 && myPokerType.value > otherPokerType.value)
			return true;
		if (myPokerType.type == 8 && myPokerType.len > 5)
			return true;
		return false;
	}

	//别人是火箭
	if (otherPokerType.type == 10)
		return false;

	//接下来如果牌型不同就只能是炸弹
	//如果牌型相同，只需要比较权值
	if (otherPokerType.type == myPokerType.type)
	{
		if (myPokerType.value > otherPokerType.value)
			return true;
		return false;
	}
	else
	{
		if (myPokerType.type == 8 || myPokerType.type == 9 || myPokerType.type == 10)
			return true;
		return false;
	}
}

/*
	是否是炸弹
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isBoom(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	//
	int value = pokerArr.at(0)->pokerNum;
	for (DWORD i = 1; i < pokerArr.size(); i++)
	{
		if (pokerArr.at(i)->pokerNum > ZhuPai || (pokerArr.at(i)->pokerNum != value && (pokerArr.at(i)->pokerNum != ZhuPai || pokerArr.at(i)->pokerHuaSe != HongXing)))
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}
	outPokerType.len = pokerArr.size() + laiZiNum;
	outPokerType.type = 8;
	outPokerType.value = value;
	return outPokerType;
}

/*
	是否是连队
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isLianDui(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	int value = pokerArr.at(0)->pokerNum2;

	//没有癞子
	if (laiZiNum == 0)
	{
		if (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == pokerArr.at(3)->pokerNum2 && pokerArr.at(4)->pokerNum2 == pokerArr.at(5)->pokerNum2
			&& pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(4)->pokerNum2 == value + 2)
		{
			outPokerType.len = 6;
			outPokerType.type = 6;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	//有一张癞子
	if (laiZiNum == 1)
	{
		if ((pokerArr.at(1)->pokerNum2 == pokerArr.at(2)->pokerNum2 && pokerArr.at(3)->pokerNum2 == pokerArr.at(4)->pokerNum2 && pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == value + 2)
			|| (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == pokerArr.at(4)->pokerNum2 && pokerArr.at(3)->pokerNum2 == value + 2)
			|| (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == pokerArr.at(3)->pokerNum2 && pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(4)->pokerNum2 == value + 2))
		{
			outPokerType.len = 6;
			outPokerType.type = 6;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	//有2张癞子
	if (laiZiNum == 2)
	{
		// 2+2/1+1+2/1+2+1/2+1+1
		if ((pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == pokerArr.at(3)->pokerNum2 && pokerArr.at(2)->pokerNum2 == value + 1)
			|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 2 && pokerArr.at(2)->pokerNum2 == pokerArr.at(3)->pokerNum2)
			|| (pokerArr.at(1)->pokerNum2 == pokerArr.at(2)->pokerNum2 && pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == value + 2)
			|| (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == value + 2))
		{
			outPokerType.len = 6;
			outPokerType.type = 6;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	return outPokerType;
}

/*
	是否是飞机
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isFeiJi(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	int value = pokerArr.at(0)->pokerNum2;
	//没有癞子
	if (laiZiNum == 0)
	{
		if (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value && pokerArr.at(3)->pokerNum2 == value + 1
			&& pokerArr.at(4)->pokerNum2 == value + 1 && pokerArr.at(5)->pokerNum2 == value + 1 )
		{
			outPokerType.len = 6;
			outPokerType.type = 7;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	//有一张癞子
	if (laiZiNum == 1)
	{
		if ((pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value && pokerArr.at(3)->pokerNum2 == value + 1 && pokerArr.at(4)->pokerNum2 == value + 1)
			|| (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == value + 1 && pokerArr.at(4)->pokerNum2 == value + 1))
		{
			outPokerType.len = 6;
			outPokerType.type = 7;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	//有2张癞子
	if (laiZiNum == 2)
	{
		// 2+2/1+3/3+1
		if ((pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == value + 1)
			|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 1 && pokerArr.at(3)->pokerNum2 == value + 1)
			|| (pokerArr.at(1)->pokerNum2 == value && pokerArr.at(2)->pokerNum2 == value && pokerArr.at(3)->pokerNum2 == value + 1))
		{
			outPokerType.len = 6;
			outPokerType.type = 7;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	return outPokerType;
}

/*
	是否是三带二
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isSanDaiEr(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	//没有癞子
	if (laiZiNum == 0)
	{
		int value = pokerArr.at(0)->pokerNum;
		int value1 = pokerArr.at(2)->pokerNum;
		int value2 = pokerArr.at(3)->pokerNum;
		int num = 1;
		for (DWORD i = 1; i < pokerArr.size(); i++)
		{
			if (pokerArr.at(i)->pokerNum == value)
				num++;
			else
				break;
		}
		switch (num)
		{
			//2+3
			case 2:
				if (pokerArr.at(3)->pokerNum == value1 && pokerArr.at(4)->pokerNum == value1)
				{
					outPokerType.len = 5;
					outPokerType.type = 4;
					outPokerType.value = value1;
				}
				else
				{
					outPokerType.type = 0;
					return outPokerType;
				}
				break;
				//3+2
			case 3:
				if (pokerArr.at(4)->pokerNum == value2)
				{
					outPokerType.len = 5;
					outPokerType.type = 4;
					outPokerType.value = value;
				}
				else
				{
					outPokerType.type = 0;
					return outPokerType;
				}
				break;
			//错误牌型
			default:
				outPokerType.type = 0;
				return outPokerType;
				break;
		}
	}

	//有一张癞子
	if (laiZiNum == 1)
	{
		//判断剩下来的牌是两个对子或者是3张加单张
		if (pokerArr.at(0)->pokerNum == pokerArr.at(1)->pokerNum && pokerArr.at(2)->pokerNum == pokerArr.at(3)->pokerNum)
		{
			outPokerType.len = 5;
			outPokerType.type = 4;
			outPokerType.value = pokerArr.at(3)->pokerNum;
		}
		else if (pokerArr.at(0)->pokerNum == pokerArr.at(1)->pokerNum && 
			pokerArr.at(0)->pokerNum == pokerArr.at(2)->pokerNum && pokerArr.at(0)->pokerNum != pokerArr.at(3)->pokerNum
			&& pokerArr.at(3)->pokerNum < XiaoGui)
		{
			outPokerType.len = 5;
			outPokerType.type = 4;
			outPokerType.value = pokerArr.at(0)->pokerNum;
		}
		else if (pokerArr.at(0)->pokerNum != pokerArr.at(1)->pokerNum &&
			pokerArr.at(1)->pokerNum == pokerArr.at(2)->pokerNum && pokerArr.at(1)->pokerNum == pokerArr.at(3)->pokerNum
			&& pokerArr.at(0)->pokerNum < XiaoGui)
		{
			outPokerType.len = 5;
			outPokerType.type = 4;
			outPokerType.value = pokerArr.at(3)->pokerNum;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}

	}

	//有两张癞子
	if (laiZiNum == 2)
	{
		int value1 = pokerArr.at(1)->pokerNum;
		//只需要判断剩下来的牌是一个对子和一张单牌就OK
		if ((pokerArr.at(0)->pokerNum == value1 && pokerArr.at(2)->pokerNum != value1 && pokerArr.at(2)->pokerNum < XiaoGui)
			|| (pokerArr.at(0)->pokerNum != value1 && pokerArr.at(2)->pokerNum == value1))
		{
			outPokerType.len = 5;
			outPokerType.type = 4;
			outPokerType.value = value1;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}


	return outPokerType;
}

/*
	是否是同花顺
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isTongHuaShun(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}
	//
	int value = pokerArr.at(0)->pokerNum2;
	int hua = pokerArr.at(0)->pokerHuaSe;

	//没有癞子
	if (laiZiNum == 0)
	{
		//
		bool isTongHuaShun = true;
		for (DWORD i = 1; i < pokerArr.size(); i++)
		{
			if (pokerArr.at(i)->pokerNum2 != value + i || pokerArr.at(i)->pokerHuaSe != hua)
				isTongHuaShun = false;
		}
		if (!isTongHuaShun)
		{
			outPokerType.type = 0;
			return outPokerType;
		}
		else
		{
			outPokerType.len = 5;
			outPokerType.type = 9;
			outPokerType.value = value;
		}
	}

	//有一张癞子
	if (laiZiNum == 1)
	{
		//1  *  3   4   5
		//1  2  *   4   5
		//1  2  3   *   5
		//1  2  3   4   *
		bool isTonghua = true;
		for (DWORD i = 1; i < pokerArr.size(); i++)
		{
			if (pokerArr.at(i)->pokerHuaSe != hua)
				isTonghua = false;
		}
		if (!isTonghua)
		{
			outPokerType.type = 0;
			return outPokerType;
		}

		else
		{
			if ((pokerArr.at(1)->pokerNum2 == value + 2 && pokerArr.at(2)->pokerNum2 == value + 3 && pokerArr.at(3)->pokerNum2 == value + 4)
				|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 3 && pokerArr.at(3)->pokerNum2 == value + 4)
				|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 2 && pokerArr.at(3)->pokerNum2 == value + 4)
				|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 2 && pokerArr.at(3)->pokerNum2 == value + 3))
			{
				outPokerType.len = 5;
				outPokerType.type = 9;
				outPokerType.value = value;
			}
			else
			{
				outPokerType.type = 0;
				return outPokerType;
			}
		}
	}

	//有2张癞子
	if (laiZiNum == 2)
	{
		bool isTonghua = true;
		for (DWORD i = 1; i < pokerArr.size(); i++)
		{
			if (pokerArr.at(i)->pokerHuaSe != hua)
				isTonghua = false;
		}
		if (!isTonghua)
		{
			outPokerType.type = 0;
			return outPokerType;
		}
		else
		{
			if (pokerArr.at(2)->pokerNum2 - value < 5 && pokerArr.at(1)->pokerNum2 - value < 4 && pokerArr.at(2)->pokerNum2 != value
				&& pokerArr.at(1)->pokerNum2 != value && pokerArr.at(2)->pokerNum2 != pokerArr.at(1)->pokerNum2)
			{
				outPokerType.len = 5;
				outPokerType.type = 9;
				outPokerType.value = value;
			}
			else
			{
				outPokerType.type = 0;
				return outPokerType;
			}
		}
	}


	return outPokerType;
}

/*
	是否是顺子
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isShunZi(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}
	//
	int value = pokerArr.at(0)->pokerNum2;

	//没有癞子
	if (laiZiNum == 0)
	{
		//
		bool isShunZi = true;
		for (DWORD i = 1; i < pokerArr.size(); i++)
		{
			if (pokerArr.at(i)->pokerNum2 != value + i)
				isShunZi = false;
		}
		if (!isShunZi)
		{
			outPokerType.type = 0;
			return outPokerType;
		}
		else
		{
			outPokerType.len = 5;
			outPokerType.type = 5;
			outPokerType.value = value;
		}
	}

	//有一张癞子
	if (laiZiNum == 1)
	{
		//1  *  3   4   5
		//1  2  *   4   5
		//1  2  3   *   5
		//1  2  3   4   *
		if ((pokerArr.at(1)->pokerNum2 == value + 2 && pokerArr.at(2)->pokerNum2 == value + 3 && pokerArr.at(3)->pokerNum2 == value + 4)
			|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 3 && pokerArr.at(3)->pokerNum2 == value + 4)
			|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 2 && pokerArr.at(3)->pokerNum2 == value + 4)
			|| (pokerArr.at(1)->pokerNum2 == value + 1 && pokerArr.at(2)->pokerNum2 == value + 2 && pokerArr.at(3)->pokerNum2 == value + 3))
		{
			outPokerType.len = 5;
			outPokerType.type = 5;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	//有2张癞子
	if (laiZiNum == 2)
	{
		if (pokerArr.at(2)->pokerNum2 - value < 5 && pokerArr.at(1)->pokerNum2 - value < 4 && pokerArr.at(2)->pokerNum2 != value
			&& pokerArr.at(1)->pokerNum2 != value && pokerArr.at(2)->pokerNum2 != pokerArr.at(1)->pokerNum2)
		{
			outPokerType.len = 5;
			outPokerType.type = 5;
			outPokerType.value = value;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}
	return outPokerType;
}

/*
	是否是火箭
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isHuoJian(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//
	int huase1 = pokerArr.at(0)->pokerHuaSe;
	int huase2 = pokerArr.at(1)->pokerHuaSe;
	int huase3 = pokerArr.at(2)->pokerHuaSe;
	int huase4 = pokerArr.at(3)->pokerHuaSe;

	//
	if (huase1 == Gui && huase2 == Gui && huase3 == Gui && huase4 == Gui)
	{
		outPokerType.len = pokerArr.size();
		outPokerType.type = 10;
		return outPokerType;
	}
	else
	{
		outPokerType.type = 0;
		return outPokerType;
	}
}

/*
	是否是3张同值的牌
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isSanZhang(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	//
	if (laiZiNum == 0)
	{
		//
		int value1 = pokerArr.at(0)->pokerNum;
		int value2 = pokerArr.at(1)->pokerNum;
		int value3 = pokerArr.at(2)->pokerNum;

		if (value1 == value2 && value1 == value3)
		{
			outPokerType.len = 3;
			outPokerType.type = 3;
			outPokerType.value = value1;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	else if (laiZiNum == 1)
	{
		int value1 = pokerArr.at(0)->pokerNum;
		int value2 = pokerArr.at(1)->pokerNum;

		if (value1 == value2 && value1 < XiaoGui)
		{
			outPokerType.len = 3;
			outPokerType.type = 3;
			outPokerType.value = value1;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}

	else if (laiZiNum == 2)
	{
		int value1 = pokerArr.at(0)->pokerNum;

		if (value1 < XiaoGui)
		{
			outPokerType.len = 3;
			outPokerType.type = 3;
			outPokerType.value = value1;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}
	return outPokerType;
}

/*
	是否是对子
	不是则返回nullptr
*/
PokerTypeVO OutPokerLogicRule::isDuiZi(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	//先剔除其中的癞子
	int laiZiNum = 0;
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->pokerNum == ZhuPai && (*it)->pokerHuaSe == HongXing)
		{
			laiZiNum++;
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	//
	if (laiZiNum == 0)
	{
		int value1 = pokerArr.at(0)->pokerNum;
		int value2 = pokerArr.at(1)->pokerNum;

		if (value1 == value2)
		{
			outPokerType.len = 2;
			outPokerType.type = 2;
			outPokerType.value = value1;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}
	}
	else if (laiZiNum == 1)
	{
		int value1 = pokerArr.at(0)->pokerNum;

		if (value1 < XiaoGui)
		{
			outPokerType.len = 2;
			outPokerType.type = 2;
			outPokerType.value = value1;
		}
		else
		{
			outPokerType.type = 0;
			return outPokerType;
		}

	}
	else if (laiZiNum == 2)
	{
		outPokerType.len = 2;
		outPokerType.type = 2;
		outPokerType.value = ZhuPai;
	}

	return outPokerType;
}

/*
	是否是单张
*/
PokerTypeVO OutPokerLogicRule::isDanZhang(vector<PokerVO*> pokerArr)
{
	PokerTypeVO outPokerType;

	if (pokerArr.size() == 0)
	{
		outPokerType.type = 0;
		return outPokerType;
	}
	//
	int value = pokerArr.at(0)->pokerNum;

	outPokerType.len = pokerArr.size();
	outPokerType.type = 1;
	outPokerType.value = value;
	return outPokerType;
}

/************************************************************************/
/* 下面用于实现提示功能	                                                */
/************************************************************************/

/*
	跟其他玩家的牌，用于提示
	return:用于跟牌的牌组的所有可能
*/
vector<vector<PokerVO*>> OutPokerLogicRule::FollowPoker(vector<PokerVO*> otherPokerArr, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//先判断其他玩家的牌型
	PokerTypeVO otherPokerType = outPokerType(otherPokerArr);

	switch (otherPokerType.type)
	{
		//单张
		case 1:
			return TiQuDanPai(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//对子
		case 2:
			return TiQuDuiZi(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//三张
		case 3:
			return TiQuSanZhang(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//三带二
		case 4:
			return TiQuSanDaiEr(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//顺子
		case 5:
			return TiQuShunZi(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//连对
		case 6:
			return TiQuLianDui(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//飞机
		case 7:
			return TiQuFeiJi(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//炸弹
		case 8:
			return TiQuBoom(otherPokerType.value, otherPokerType.len, myPokerTypeArr, LaiZiArr);
			break;
		//同花顺
		case 9:
			return TiQuTongHuaShun(otherPokerType.value, myPokerTypeArr, LaiZiArr);
			break;
		//火箭直接不出
		default:
			return {};
			break;
	}
}


/*
	预先判断所有手牌的牌型，用于提示和AI自动跟牌
	注意：这边的牌型中剔除了癞子！！！！
*/
vector<PokerTypeVO> OutPokerLogicRule::fenXiShouPai(vector<PokerVO*> pokerArr)
{
	//
	vector<PokerTypeVO> pokerTypeArr = {};
	vector<PokerVO*> mypokerArr = {};

	if (pokerArr.size() == 0)
		return pokerTypeArr;

	//剔除癞子
	vector<PokerVO*>::iterator it1;
	for (it1 = pokerArr.begin(); it1 != pokerArr.end(); it1++)
	{
		if ((*it1)->pokerNum != ZhuPai || (*it1)->pokerHuaSe != HongXing)
		{
			mypokerArr.push_back(*it1);
		}
	}


	//这边先将扑克按照牌值从小到大排序
	//mypokerArr = BubbleSort(pokerArr);
	mypokerArr = BubbleSort2(mypokerArr);

	//先提取火箭
	vector<PokerVO*>::iterator it;
	if (mypokerArr.size() > 3)
	{
		for (it = mypokerArr.begin(); it != mypokerArr.end() - 3; it++)
		{
			PokerTypeVO pokerType;
			if ((*it)->pokerHuaSe == Gui && (*it + 1)->pokerHuaSe == Gui && (*it + 2)->pokerHuaSe == Gui && (*it + 3)->pokerHuaSe == Gui)
			{
				pokerType.pokerArr.push_back(*it);
				pokerType.pokerArr.push_back(*(it + 1));
				pokerType.pokerArr.push_back(*(it + 2));
				pokerType.pokerArr.push_back(*(it + 3));
				pokerType.len = 4;
				pokerType.type = 10;

				mypokerArr.erase(it);
				mypokerArr.erase(it + 1);
				mypokerArr.erase(it + 2);
				mypokerArr.erase(it + 3);

				pokerTypeArr.push_back(pokerType);
				break;
			}
		}
	}

	//提取炸弹,3张，对子，单张（其中不能包括癞子）
	for (it = mypokerArr.begin(); it != mypokerArr.end();)
	{
		PokerTypeVO pokerType;
		pokerType.pokerArr.clear();

		int len = 1;
		vector<PokerVO*>::iterator it1;
		for (it1 = it + 1; it1 != mypokerArr.end();)
		{
			if ((*it1)->pokerNum == (*it)->pokerNum)
			{
				pokerType.pokerArr.push_back(*it1);
				it1 = mypokerArr.erase(it1);
				len++;
			}
			else
				break;
		}
		pokerType.pokerArr.push_back(*it);
		pokerType.value = (*it)->pokerNum;
		pokerType.len = len;
		mypokerArr.erase(it);
		if (pokerType.len >= 4)
			pokerType.type = 8;
		else if (pokerType.len == 3)
			pokerType.type = 3;
		else if (pokerType.len == 2)
			pokerType.type = 2;
		else
			pokerType.type = 1;

		it = mypokerArr.begin();
		//
		pokerTypeArr.push_back(pokerType);
	}

	//
	return pokerTypeArr;
}

/************************************************************************/
/* 下面实现提取牌型				                                        */
/************************************************************************/
//提取单张
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuDanPai(int value, vector<PokerTypeVO> myPokerTypeArr,vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
	{
		vector<PokerVO*> pokerArr = myPokerTypeArr.at(i).pokerArr;
		for (DWORD j = 0; j < pokerArr.size(); j++)
		{
			if (pokerArr.at(j)->pokerNum > value)
				TypeArr.push_back({ pokerArr.at(j) });
		}
	}

	//考虑癞子
	if (LaiZiArr.size() > 0 && value < ZhuPai)
	{
		for (DWORD i = 0; i < LaiZiArr.size(); i++)
		{
			TypeArr.push_back({ LaiZiArr.at(i) });
		}
	}

	return TypeArr;
}

//提取对子
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuDuiZi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//先考虑有对子的情况
	for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
	{
		if (myPokerTypeArr.at(i).type == 2 && myPokerTypeArr.at(i).value > value)
		{
			TypeArr.push_back(myPokerTypeArr.at(i).pokerArr);
		}
	}

	//下面需要拆牌
	//从3张里面拆
	vector<vector<PokerVO*>> arr = TiQuSanZhang(value, myPokerTypeArr, {});
	if (arr.size() > 0)
	{
		for (DWORD i = 0; i < arr.size(); i++)
		{
			vector<PokerVO*> pokerArr = arr.at(i);
			if (pokerArr.at(0)->pokerNum > value)
				TypeArr.push_back({ pokerArr.at(0), pokerArr.at(1) });
		}
	}

	//接下来就需要考虑癞子的情况   
	if (LaiZiArr.size() > 0)
	{
		vector<vector<PokerVO*>> danPaiArr = {};
		//先取一张单张，然后再搭配一张癞子
		for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
		{
			if (myPokerTypeArr.at(i).type == 1 && myPokerTypeArr.at(i).value > value && myPokerTypeArr.at(i).value < XiaoGui)
				danPaiArr.push_back(myPokerTypeArr.at(i).pokerArr);
		}
		for (DWORD i = 0; i < danPaiArr.size(); i++)
		{
			TypeArr.push_back({ danPaiArr.at(i).at(0), LaiZiArr.at(0) });
		}

		//2张癞子成对
		if (LaiZiArr.size() == 2 && value < ZhuPai)
		{
			TypeArr.push_back(LaiZiArr);
		}
	}

	return TypeArr;
}

//提取3张
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuSanZhang(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//先考虑有三张的情况
	for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
	{
		if (myPokerTypeArr.at(i).type == 3 && myPokerTypeArr.at(i).value > value)
		{
			TypeArr.push_back(myPokerTypeArr.at(i).pokerArr);
		}
	}

	//接下来考虑癞子的情况
	//有癞子
	if (LaiZiArr.size() > 0)
	{
		//先提取对子，再搭配一张癞子
		vector<vector<PokerVO*>> duiZiArr = {};
		for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
		{
			if (myPokerTypeArr.at(i).type == 2 && myPokerTypeArr.at(i).value > value && myPokerTypeArr.at(i).value < XiaoGui)
			{
				duiZiArr.push_back(myPokerTypeArr.at(i).pokerArr);
			}
		}
		for (DWORD i = 0; i < duiZiArr.size(); i++)
		{
			TypeArr.push_back({ duiZiArr.at(i).at(0), duiZiArr.at(i).at(1), LaiZiArr.at(0) });
		}
		
		//有2张癞子
		if (LaiZiArr.size() == 2)
		{
			//先提取单张，再搭配2张癞子
			vector<vector<PokerVO*>> danZhangArr = {};
			for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
			{
				if (myPokerTypeArr.at(i).type == 1 && myPokerTypeArr.at(i).value > value && myPokerTypeArr.at(i).value < XiaoGui)
				{
					danZhangArr.push_back(myPokerTypeArr.at(i).pokerArr);
				}
			}
			for (DWORD i = 0; i < danZhangArr.size(); i++)
			{
				TypeArr.push_back({ danZhangArr.at(i).at(0), LaiZiArr.at(0), LaiZiArr.at(1) });
			}
		}
	}

	return TypeArr;
}

//提取3带2
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuSanDaiEr(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//先考虑不用癞子
	//提取三张（3张不从炸弹里面拆）
	vector<vector<PokerVO*>> SanZhangArr = TiQuSanZhang(value, myPokerTypeArr, {});

	if (SanZhangArr.size() > 0)
	{

		for (DWORD i = 0; i < SanZhangArr.size(); i++)
		{
			//提取对子
			//这边需要剔除已提取的三张
			vector<PokerTypeVO>::iterator it;
			vector<PokerTypeVO> pokerArr = myPokerTypeArr;
			for (it = pokerArr.begin(); it != pokerArr.end();)
			{
				if ((*it).type == 3 && (*it).value == SanZhangArr.at(i).at(0)->pokerNum)
					it = pokerArr.erase(it);
				else
					it++;
			}
			//
			vector<vector<PokerVO*>> DuiZiArr = TiQuDuiZi(-1, pokerArr, {});
			vector<PokerVO*> SanZhangPokerArr = SanZhangArr.at(i);
			for (DWORD j = 0; j < DuiZiArr.size(); j++)
			{
				vector<PokerVO*> DuiZiPokerArr = DuiZiArr.at(j);
				TypeArr.push_back({ SanZhangPokerArr.at(0), SanZhangPokerArr.at(1), SanZhangPokerArr.at(2), DuiZiPokerArr.at(0), DuiZiPokerArr.at(1) });
			}
		}
	}

	//用癞子来凑
	if (LaiZiArr.size() > 0)
	{
		vector<vector<PokerVO*>> SanZhangPokerArr = TiQuSanZhang(value, myPokerTypeArr, LaiZiArr);
		vector<vector<PokerVO*>> DuiZiPokerArr = TiQuDuiZi(-1, myPokerTypeArr, LaiZiArr);

		//
		for (DWORD i = 0; i < SanZhangPokerArr.size(); i++)
		{
			//
			for (DWORD j = 0; j < DuiZiPokerArr.size(); j++)
			{
				vector<PokerVO*> SanZhangPoker = SanZhangPokerArr.at(i);
				vector<PokerVO*> DuiZiPoker = DuiZiPokerArr.at(j);
				if (SanZhangPoker.at(0)->pokerID != DuiZiPoker.at(0)->pokerID)
				{
					//
					int num1 = 0;
					vector<PokerVO*> pokerArr1 = {};
					for (DWORD m = 0; m < SanZhangPoker.size(); m++)
					{
						pokerArr1.push_back(SanZhangPoker.at(m));
						if (SanZhangPoker.at(m)->pokerNum == ZhuPai && SanZhangPoker.at(m)->pokerHuaSe == HongXing)
							num1++;
					}
					for (DWORD n = 0; n < DuiZiPoker.size(); n++)
					{
						pokerArr1.push_back(DuiZiPoker.at(n));
						if (DuiZiPoker.at(n)->pokerNum == ZhuPai && DuiZiPoker.at(n)->pokerHuaSe == HongXing)
							num1++;
					}
					if (num1 < (LaiZiArr.size() + 1))
					{
						TypeArr.push_back(pokerArr1);
					}
				}
			}
		}
	}

	return TypeArr;
}

//提取顺子
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuShunZi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//提取单牌
	vector<vector<PokerVO*>> DanPaiArr = TiQuDanPai(value, myPokerTypeArr, {});

	//判断单张能否组成顺子
	for (DWORD i = 0; i < DanPaiArr.size(); i++)
	{
		vector<PokerVO*> ShunZiArr = {};
		ShunZiArr.push_back(DanPaiArr.at(i).at(0));
		for (DWORD j = i + 1; j < DanPaiArr.size(); j++)
		{
			if (DanPaiArr.at(j).at(0)->pokerNum2 == DanPaiArr.at(i).at(0)->pokerNum2 + 1)
			{
				ShunZiArr.resize(1);
				ShunZiArr.push_back(DanPaiArr.at(j).at(0));
				for (DWORD m = j + 1; m < DanPaiArr.size(); m++)
				{
					if (DanPaiArr.at(m).at(0)->pokerNum2 == DanPaiArr.at(i).at(0)->pokerNum2 + 2)
					{
						ShunZiArr.resize(2);
						ShunZiArr.push_back(DanPaiArr.at(m).at(0));
						for (DWORD n = m + 1; n < DanPaiArr.size(); n++)
						{
							if (DanPaiArr.at(n).at(0)->pokerNum2 == DanPaiArr.at(i).at(0)->pokerNum2 + 3)
							{
								ShunZiArr.resize(3);
								ShunZiArr.push_back(DanPaiArr.at(n).at(0));
								for (DWORD k = n + 1; k < DanPaiArr.size(); k++)
								{
									if (DanPaiArr.at(k).at(0)->pokerNum2 == DanPaiArr.at(i).at(0)->pokerNum2 + 4)
									{
										ShunZiArr.resize(4);
										ShunZiArr.push_back(DanPaiArr.at(k).at(0));
										TypeArr.push_back(ShunZiArr);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//下面考虑癞子的情形
	if (LaiZiArr.size() > 0)
	{
		//先用一张癞子
		if (DanPaiArr.size() > 3)
		{
			vector<vector<PokerVO*>> allArr = {};
			for (DWORD i = 0; i < DanPaiArr.size(); i++)
			{
				vector<PokerVO*> SiZhangArr = {};
				SiZhangArr.push_back(DanPaiArr.at(i).at(0));
				for (DWORD j = i + 1; j < DanPaiArr.size(); j++)
				{
					if (DanPaiArr.at(j).at(0)->pokerNum2 - DanPaiArr.at(i).at(0)->pokerNum2 < 3)
					{
						SiZhangArr.resize(1);
						SiZhangArr.push_back(DanPaiArr.at(j).at(0));
						for (DWORD m = j + 1; m < DanPaiArr.size(); m++)
						{
							if (DanPaiArr.at(m).at(0)->pokerNum2 - DanPaiArr.at(j).at(0)->pokerNum2 < 3)
							{
								SiZhangArr.resize(2);
								SiZhangArr.push_back(DanPaiArr.at(m).at(0));
								for (DWORD n = m + 1; n < DanPaiArr.size(); n++)
								{
									if (DanPaiArr.at(n).at(0)->pokerNum2 - DanPaiArr.at(m).at(0)->pokerNum2 < 3)
									{
										SiZhangArr.resize(3);
										SiZhangArr.push_back(DanPaiArr.at(n).at(0));
										allArr.push_back(SiZhangArr);
									}
								}
							}
						}
					}
				}
			}

			for (DWORD i = 0; i < allArr.size(); i++)
			{
				//1  *  3   4   5
				//1  2  *   4   5
				//1  2  3   *   5
				//1  2  3   4   *
				vector<PokerVO*> pokerArr = allArr.at(i);
				int num = pokerArr.at(0)->pokerNum2;
				if ((pokerArr.at(1)->pokerNum2 == num + 2 && pokerArr.at(2)->pokerNum2 == num + 3 && pokerArr.at(3)->pokerNum2 == num + 4)
					|| (pokerArr.at(1)->pokerNum2 == num + 1 && pokerArr.at(2)->pokerNum2 == num + 3 && pokerArr.at(3)->pokerNum2 == num + 4)
					|| (pokerArr.at(1)->pokerNum2 == num + 1 && pokerArr.at(2)->pokerNum2 == num + 2 && pokerArr.at(3)->pokerNum2 == num + 4)
					|| (pokerArr.at(1)->pokerNum2 == num + 1 && pokerArr.at(2)->pokerNum2 == num + 2 && pokerArr.at(3)->pokerNum2 == num + 3))
				{
					TypeArr.push_back({ pokerArr.at(0), pokerArr.at(1), pokerArr.at(2), pokerArr.at(3), LaiZiArr.at(0) });
				}
			}
		}

		//用2张癞子
		if (DanPaiArr.size() > 2 && LaiZiArr.size() == 2)
		{
			vector<vector<PokerVO*>> allArr = {};
			for (DWORD i = 0; i < DanPaiArr.size(); i++)
			{
				vector<PokerVO*> SanZhangArr = {};
				SanZhangArr.push_back(DanPaiArr.at(i).at(0));
				for (DWORD j = i + 1; j < DanPaiArr.size(); j++)
				{
					if (DanPaiArr.at(j).at(0)->pokerNum2 - DanPaiArr.at(i).at(0)->pokerNum2 < 4)
					{
						SanZhangArr.resize(1);
						SanZhangArr.push_back(DanPaiArr.at(j).at(0));
						for (DWORD m = j + 1; m < DanPaiArr.size(); m++)
						{
							if (DanPaiArr.at(m).at(0)->pokerNum2 - DanPaiArr.at(j).at(0)->pokerNum2 < 4)
							{
								SanZhangArr.resize(2);
								SanZhangArr.push_back(DanPaiArr.at(m).at(0));
								allArr.push_back(SanZhangArr);
							}
						}
					}
				}
			}

			for (DWORD i = 0; i < allArr.size(); i++)
			{
				vector<PokerVO*> pokerArr = allArr.at(i);
				int num = pokerArr.at(0)->pokerNum2;
				if (pokerArr.at(2)->pokerNum2 - num < 5 && pokerArr.at(1)->pokerNum2 - num < 4 && pokerArr.at(2)->pokerNum2 != num
					&& pokerArr.at(1)->pokerNum2 != num && pokerArr.at(2)->pokerNum2 != pokerArr.at(1)->pokerNum2)
				{
					TypeArr.push_back({ pokerArr.at(0), pokerArr.at(1), pokerArr.at(2), LaiZiArr.at(0), LaiZiArr.at(1) });
				}
			}
		}
	}

	return TypeArr;
}

//提取连对
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuLianDui(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//先考虑不用癞子的情形
	//提取对子
	vector<vector<PokerVO*>> DuiZiArr = TiQuDuiZi(value, myPokerTypeArr, {});

	//这边需要将提取的对子先根据权值从小到大排序
	DuiZiArr = SortGroupArr(DuiZiArr);

	//判断对子能否组成连对
	if (DuiZiArr.size() < 3)
		return TypeArr;
	for (DWORD i = 2; i < DuiZiArr.size(); i++)
	{
		//最多3连对
		vector<PokerVO*> pokerArr1 = DuiZiArr.at(i);
		vector<PokerVO*> pokerArr2 = DuiZiArr.at(i - 1);
		vector<PokerVO*> pokerArr3 = DuiZiArr.at(i - 2);
		int num = pokerArr3.at(0)->pokerNum2;
		if (num > value && pokerArr1.at(0)->pokerNum2 == num + 2 && pokerArr2.at(0)->pokerNum2 == num + 1)
		{
			TypeArr.push_back({ pokerArr3.at(0), pokerArr3.at(1), pokerArr2.at(0), pokerArr2.at(1), pokerArr1.at(0), pokerArr1.at(1) });
		}
	} 


	//接下来考虑癞子的情形
	if (LaiZiArr.size() > 0)
	{
		//提取对子
		vector<vector<PokerVO*>> DuiZiArr1 = TiQuDuiZi(value, myPokerTypeArr, LaiZiArr);
		//这边需要将提取的对子先根据权值从小到大排序
		DuiZiArr1 = SortGroupArr(DuiZiArr1);

		for (DWORD i = 2; i < DuiZiArr1.size(); i++)
		{
			//最多3连对
			vector<PokerVO*> pokerArr1 = DuiZiArr1.at(i);
			vector<PokerVO*> pokerArr2 = DuiZiArr1.at(i - 1);
			vector<PokerVO*> pokerArr3 = DuiZiArr1.at(i - 2);
			int num = pokerArr3.at(0)->pokerNum2;
			if (num > value && pokerArr1.at(0)->pokerNum2 == num + 2 && pokerArr2.at(0)->pokerNum2 == num + 1)
			{
				int num1 = 0;
				vector<PokerVO*> pokerArr4 = {};
				for (DWORD j = 0; j < pokerArr3.size(); j++)
				{
					pokerArr4.push_back(pokerArr3.at(j));
					if (pokerArr3.at(j)->pokerNum == ZhuPai && pokerArr3.at(j)->pokerHuaSe == HongXing)
						num1++;
				}
				for (DWORD j = 0; j < pokerArr2.size(); j++)
				{
					pokerArr4.push_back(pokerArr2.at(j));
					if (pokerArr2.at(j)->pokerNum == ZhuPai && pokerArr2.at(j)->pokerHuaSe == HongXing)
						num1++;
				}
				for (DWORD j = 0; j < pokerArr1.size(); j++)
				{
					pokerArr4.push_back(pokerArr1.at(j));
					if (pokerArr1.at(j)->pokerNum == ZhuPai && pokerArr1.at(j)->pokerHuaSe == HongXing)
						num1++;
				}
				if (num1 < (LaiZiArr.size() + 1))
					TypeArr.push_back(pokerArr4);
			}
		}
	}


	return TypeArr;
}

//提取飞机
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuFeiJi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};


	//先不考虑癞子
	//提取3张
	vector<vector<PokerVO*>> SanZhangArr = TiQuSanZhang(value, myPokerTypeArr, {});
	SanZhangArr = SortGroupArr(SanZhangArr);

	//判断3张能否组成飞机
	if (SanZhangArr.size() < 2)
		return TypeArr;
	for (DWORD i = 1; i < SanZhangArr.size(); i++)
	{
		//最多6张牌
		vector<PokerVO*> pokerArr1 = SanZhangArr.at(i);
		vector<PokerVO*> pokerArr2 = SanZhangArr.at(i - 1);
		if (pokerArr1.at(0)->pokerNum2 - 1 == pokerArr2.at(0)->pokerNum2 && pokerArr2.at(0)->pokerNum2 > value)
		{
			TypeArr.push_back({ pokerArr2.at(0), pokerArr2.at(1), pokerArr2.at(2), pokerArr1.at(0), pokerArr1.at(1), pokerArr1.at(2) });
		}
	}

	//接下来考虑癞子的情形
	if (LaiZiArr.size() > 0)
	{
		//提取3张
		vector<vector<PokerVO*>> SanZhangArr1 = TiQuSanZhang(value, myPokerTypeArr, LaiZiArr);
		SanZhangArr1 = SortGroupArr(SanZhangArr1);
		for (DWORD i = 1; i < SanZhangArr1.size(); i++)
		{
			//最多6张牌
			vector<PokerVO*> pokerArr1 = SanZhangArr1.at(i);
			vector<PokerVO*> pokerArr2 = SanZhangArr1.at(i - 1);
			if (pokerArr1.at(0)->pokerNum2 - 1 == pokerArr2.at(0)->pokerNum2)
			{
				int num1 = 0;
				vector<PokerVO*> pokerArr4 = {};
				for (DWORD j = 0; j < pokerArr1.size(); j++)
				{
					pokerArr4.push_back(pokerArr1.at(j));
					if (pokerArr1.at(j)->pokerNum == ZhuPai && pokerArr1.at(j)->pokerHuaSe == HongXing)
						num1++;
				}
				for (DWORD j = 0; j < pokerArr2.size(); j++)
				{
					pokerArr4.push_back(pokerArr2.at(j));
					if (pokerArr2.at(j)->pokerNum == ZhuPai && pokerArr2.at(j)->pokerHuaSe == HongXing)
						num1++;
				}
				if (num1 < (LaiZiArr.size() + 1))
					TypeArr.push_back(pokerArr4);
			}
		}
	}


	return TypeArr;

}

//提取炸弹
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuBoom(int value, int len, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//先考虑有炸弹能跟的情况
	for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
	{
		if (myPokerTypeArr.at(i).type == 8 && (myPokerTypeArr.at(i).len > len || (myPokerTypeArr.at(i).len == len && myPokerTypeArr.at(i).value > value)))
		{
			TypeArr.push_back(myPokerTypeArr.at(i).pokerArr);
		}
	}

	//接下来考虑癞子的情况
	if (LaiZiArr.size() > 0)
	{
		//先用一张癞子
		int num = len - 1;
		if (num > 3)
		{
			//炸弹加1癞子
			for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
			{
				if (myPokerTypeArr.at(i).type == 8 && (myPokerTypeArr.at(i).len > num || (myPokerTypeArr.at(i).len == num && myPokerTypeArr.at(i).value > value)))
				{
					vector<PokerVO*> pokerArr = myPokerTypeArr.at(i).pokerArr;
					pokerArr.push_back(LaiZiArr.at(0));
					TypeArr.push_back(pokerArr);
				}
			}
		}
		else
		{
			//3张加一张癞子
			vector<vector<PokerVO*>> SanZhangArr = TiQuSanZhang(value, myPokerTypeArr, {});
			for (DWORD i = 0; i < SanZhangArr.size(); i++)
			{
				vector<PokerVO*> pokerArr = SanZhangArr.at(i);
				pokerArr.push_back(LaiZiArr.at(0));
				TypeArr.push_back(pokerArr);
			}
		}

		//用2张癞子
		if (LaiZiArr.size() == 2)
		{
			num = len - 2;

			if (num > 3)
			{
				//炸弹加2癞子
				for (DWORD i = 0; i < myPokerTypeArr.size(); i++)
				{
					if (myPokerTypeArr.at(i).type == 8 && (myPokerTypeArr.at(i).len > num || (myPokerTypeArr.at(i).len == num && myPokerTypeArr.at(i).value > value)))
					{
						vector<PokerVO*> pokerArr = myPokerTypeArr.at(i).pokerArr;
						pokerArr.push_back(LaiZiArr.at(0));
						pokerArr.push_back(LaiZiArr.at(1));
						TypeArr.push_back(pokerArr);
					}
				}
			}
			else if (num == 3)
			{
				//3张加2癞子
				vector<vector<PokerVO*>> SanZhangArr = TiQuSanZhang(value, myPokerTypeArr, {});
				for (DWORD i = 0; i < SanZhangArr.size(); i++)
				{
					vector<PokerVO*> pokerArr = SanZhangArr.at(i);
					pokerArr.push_back(LaiZiArr.at(0));
					pokerArr.push_back(LaiZiArr.at(1));
					TypeArr.push_back(pokerArr);
				}
			}
			else
			{
				//对子加2癞子
				vector<vector<PokerVO*>> DuiZiArr = TiQuDuiZi(value, myPokerTypeArr, {});
				for (DWORD i = 0; i < DuiZiArr.size(); i++)
				{
					vector<PokerVO*> pokerArr = DuiZiArr.at(i);
					if (pokerArr.at(0)->pokerNum < XiaoGui)
					{
						pokerArr.push_back(LaiZiArr.at(0));
						pokerArr.push_back(LaiZiArr.at(1));
						TypeArr.push_back(pokerArr);
					}
				}
			}
		}
	}

	return TypeArr;

}

//提取同花顺
vector<vector<PokerVO*>> OutPokerLogicRule::TiQuTongHuaShun(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr)
{
	//保存所有的能跟牌的牌组
	vector<vector<PokerVO*>> TypeArr = {};

	//先提取顺子
	vector<vector<PokerVO*>> ShunZiArr = TiQuShunZi(value, myPokerTypeArr, LaiZiArr);

	//再从顺子中筛选同花顺
	if (ShunZiArr.size() == 0)
		return TypeArr;
	for (DWORD i = 0; i < ShunZiArr.size(); i++)
	{
		bool isTongHua = true;
		vector<PokerVO*> pokerArr = ShunZiArr.at(i);
		int huaSe = pokerArr.at(0)->pokerHuaSe;
		for (DWORD j = 1; j < pokerArr.size(); j++)
		{
			if (pokerArr.at(j)->pokerHuaSe != huaSe && (pokerArr.at(j)->pokerNum != ZhuPai || pokerArr.at(j)->pokerHuaSe != HongXing))
				isTongHua = false;
		}
		if (isTongHua)
			TypeArr.push_back(ShunZiArr.at(i));
	}

	return TypeArr;
}

//将提取到的某种牌型的所有可能的组合按照权值从小到大排序
vector<vector<PokerVO*>> OutPokerLogicRule::SortGroupArr(vector<vector<PokerVO*>> groupArr)
{
	//
	int len = groupArr.size();
	//从后往前冒泡
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			int pkID1 = groupArr.at(j).at(0)->pokerNum2;
			int pkID2 = groupArr.at(j - 1).at(0)->pokerNum2;
			if (pkID1 < pkID2)
			{
				vector<PokerVO*> pkArr = groupArr.at(j);
				groupArr[j] = groupArr[j - 1];
				groupArr[j - 1] = pkArr;
			}
		}
	}
	return groupArr;
}