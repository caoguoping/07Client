#include "PokerLogic.h"
#include "SGTools.h"

int PokerLogic::zhuPaiNum = -1;
vector<vector<int>> PokerLogic::num10Arr = 
{
	/*对应的十进制  2~A 小王  大王   方、梅、红、黑
		2		18		34		50 
		3		19		35		51
		4		20		36		52
		5		21		37		53
		6		22		38		54
		7		23		39		55
		8		24		40		56
		9		25		41		57
		10		26		42		58
		11		27		43		59
		12		28		44		60
		13		29		45		61
		1		17		33		49
		65
		66
	*/
	{ 0x32, 0x22, 0x12, 0x02 },			//2
	{ 0x33, 0x23, 0x13, 0x03 },			//3
	{ 0x34, 0x24, 0x14, 0x04 },			//4
	{ 0x35, 0x25, 0x15, 0x05 },			//5
	{ 0x36, 0x26, 0x16, 0x06 },			//6
	{ 0x37, 0x27, 0x17, 0x07 },			//7
	{ 0x38, 0x28, 0x18, 0x08 },			//8
	{ 0x39, 0x29, 0x19, 0x09 },			//9
	{ 0x3A, 0x2A, 0x1A, 0x0A },			//10
	{ 0x3B, 0x2B, 0x1B, 0x0B },			//J
	{ 0x3C, 0x2C, 0x1C, 0x0C },			//Q
	{ 0x3D, 0x2D, 0x1D, 0x0D },			//K
	{ 0x31, 0x21, 0x11, 0x01 },			//A
	{ 0x41 },							//小王
	{ 0X42 }							//大王
};

PokerLogic::PokerLogic()
{

}

PokerLogic::~PokerLogic()
{
	num10Arr.clear();
}

/*
	获取牌值 （这边不考虑主牌。用于记牌功能）
	id,  enum PokerNum  2-A, B, ZhuPai, XiaoGui, DaGui
*/
int PokerLogic::getPokerNum2(int id)
{
	int len = num10Arr.size();
	for (int i = 0; i < len; i++)
	{
		int l = num10Arr[i].size();
		for (int j = 0; j < l; j++)
		{
			if (num10Arr[i][j] == id)
			{
				if (i > 12)
					return i + 2;
				return i;
			}
		}
	}
	return -1;
}


/*
	获取牌值 0~14(2~A~大王)
	id,  enum PokerNum  2-A, B, ZhuPai, XiaoGui, DaGui

*/
int PokerLogic::getPokerNum(int id)
{

	int len = num10Arr.size();
	for (int i = 0; i < len; i++)
	{
		int ls = num10Arr[i].size();
		for (int j = 0; j < ls; j++)
		{
			if (num10Arr[i][j] == id)
			{
				//先判断是否是本轮的主牌
				if (i == zhuPaiNum)
					return ZhuPai;
				if (i > 12)
					return i + 2;
				return i;
			}
		}
	}
	return -1;
}

//获取牌的花色(0~4)
int PokerLogic::getPokerHuaSe(int id)
{
	int len = num10Arr.size();
	for (int i = 0; i < len; i++)
	{
		int ls = num10Arr[i].size();
		for (int j = 0; j < ls; j++)
		{
			if (num10Arr[i][j] == id)
			{
				if (i > 12)
					return Gui;
				return j;
			}
		}
	}
	return -1;
}

//自己手牌中的癞子
vector<PokerVO*> PokerLogic::getMyLaiZiArr(vector<PokerVO*> myPokerArr)
{
	vector<PokerVO*> LaiZiArr = {};
	for (int i = 0; i < myPokerArr.size(); i++)
	{
		if (myPokerArr.at(i)->pokerNum == ZhuPai && myPokerArr.at(i)->pokerHuaSe == HongXing)
			LaiZiArr.push_back(myPokerArr.at(i));
	}
	return LaiZiArr;
}

//将牌的ID进行排序（牌值从大到小，花色从黑桃到方块）
vector<int> PokerLogic::sortPokerIDArr(vector<int> pokerIDArr)
{
	int len = pokerIDArr.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			int pkNum1 = PokerLogic::getPokerNum(pokerIDArr.at(j));
			int pkNum2 = PokerLogic::getPokerNum(pokerIDArr.at(j - 1));
			if (pkNum1 > pkNum2)
			{
				int pkID = pokerIDArr.at(j);
				pokerIDArr.at(j) = pokerIDArr.at(j - 1);
				pokerIDArr.at(j - 1) = pkID;
			}
			//牌值相同的情况下比较花色
			else if (pkNum1 == pkNum2)
			{
				int huaSe1 = PokerLogic::getPokerHuaSe(pokerIDArr.at(j));
				int huaSe2 = PokerLogic::getPokerHuaSe(pokerIDArr.at(j - 1));
				if (huaSe1 > huaSe2)
				{
					int pkID = pokerIDArr.at(j);
					pokerIDArr.at(j) = pokerIDArr.at(j - 1);
					pokerIDArr.at(j - 1) = pkID;
				}
			}
		}
	}
	return pokerIDArr;
}

//将牌的ID根据牌值进行分堆（把相同牌值的放到一堆中）
vector<vector<int>> PokerLogic::fenPokerIDArr(vector<int> pokerIDArr)
{
	//先将牌的ID进行排序（牌值从大到小，花色从黑桃到方块）
	pokerIDArr = sortPokerIDArr(pokerIDArr);

	//开始分堆
	vector<vector<int>> IDArr = {};
	vector<int> pokerArr1 = {};
	pokerArr1.push_back(pokerIDArr.at(0));
	for (int i = 1; i < pokerIDArr.size(); i++)
	{
		int len = pokerArr1.size();
		if (getPokerNum(pokerIDArr.at(i)) == getPokerNum(pokerArr1.at(len-1)))
		{
			pokerArr1.push_back(pokerIDArr.at(i));
		}
		else
		{
			IDArr.push_back(pokerArr1);
			pokerArr1.clear();
			pokerArr1.push_back(pokerIDArr.at(i));
		}
		if (i == pokerIDArr.size() - 1)
		{
			IDArr.push_back(pokerArr1);
		}
	}

	return IDArr;
}

//将牌根据牌值重新进行分堆（把相同牌值的放到一堆中）
vector<vector<PokerVO*>> PokerLogic::reFenPokerArr(vector<PokerVO*> pokerArr)
{
	//先将牌的ID进行排序（牌值从大到小，花色从黑桃到方块）
	//先剔除用户自定义排成一列的牌
	vector<vector<PokerVO*>> changePosPokerArr = {};
	changePosPokerArr.resize(100);	//注意：这边分配大小为100，点击理成一排超过100次会出错 ~`（让你丫的乱点，=。=）
	vector<PokerVO*>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it)->isChangePosition > 0)
		{
			changePosPokerArr.at((*it)->isChangePosition).push_back(*it);
			it = pokerArr.erase(it);
		}
		else
			it++;
	}

	int len = pokerArr.size();
	vector<vector<PokerVO*>> Arr = {};

	if (len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = len - 1; j > i; j--)
			{
				if (pokerArr.at(j)->pokerNum > pokerArr.at(j - 1)->pokerNum)
				{
					PokerVO* pk = pokerArr.at(j);
					pokerArr.at(j) = pokerArr.at(j - 1);
					pokerArr.at(j - 1) = pk;
				}
				//牌值相同的情况下比较花色
				else if (pokerArr.at(j)->pokerNum == pokerArr.at(j - 1)->pokerNum)
				{
					if (pokerArr.at(j)->pokerHuaSe > pokerArr.at(j - 1)->pokerHuaSe)
					{
						PokerVO* pk = pokerArr.at(j);
						pokerArr.at(j) = pokerArr.at(j - 1);
						pokerArr.at(j - 1) = pk;
					}
				}
			}
		}

		//开始分堆
		vector<PokerVO*> pokerArr1 = {};
		pokerArr1.push_back(pokerArr.at(0));
		if (pokerArr.size() > 1)
		{
			for (int i = 1; i < pokerArr.size(); i++)
			{
				int len = pokerArr1.size();
				if (pokerArr.at(i)->pokerNum == pokerArr1.at(len - 1)->pokerNum)
				{
					pokerArr1.push_back(pokerArr.at(i));
				}
				else
				{
					Arr.push_back(pokerArr1);
					pokerArr1.clear();
					pokerArr1.push_back(pokerArr.at(i));
				}
				if (i == pokerArr.size() - 1)
				{
					Arr.push_back(pokerArr1);
				}
			}
		}
		else
		{
			Arr.push_back(pokerArr1);
		}

	}

	//把用户自定义排序的牌放到最后
	for (int i = 0; i < changePosPokerArr.size(); i++)
	{
		if (changePosPokerArr.at(i).size() > 0)
		{
			Arr.push_back(changePosPokerArr.at(i));
		}

	}

	return Arr;
}

//将牌根据牌值重新进行分堆（把相同牌值的放到一堆中）
vector<vector<PokerVO>> PokerLogic::reFenPokerArr1(vector<PokerVO> pokerArr)
{
	if (pokerArr.size() == 0)
		return {};
	//先将牌的ID进行排序（牌值从大到小，花色从黑桃到方块）
	//先剔除用户自定义排成一列的牌
	vector<vector<PokerVO>> changePosPokerArr = {};
	changePosPokerArr.resize(100);	//注意：这边分配大小为100，点击理成一排超过100次会出错 ~`（让你丫的乱点，=。=）
	vector<PokerVO>::iterator it;
	for (it = pokerArr.begin(); it != pokerArr.end();)
	{
		if ((*it).isChangePosition > 0)
		{
			changePosPokerArr.at((*it).isChangePosition).push_back(*it);
			it = pokerArr.erase(it);
		}
		else
			it++;
	}
	int len = pokerArr.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (pokerArr.at(j).pokerNum > pokerArr.at(j - 1).pokerNum)
			{
				PokerVO pk = pokerArr.at(j);
				pokerArr.at(j) = pokerArr.at(j - 1);
				pokerArr.at(j - 1) = pk;
			}
			//牌值相同的情况下比较花色
			else if (pokerArr.at(j).pokerNum == pokerArr.at(j - 1).pokerNum)
			{
				if (pokerArr.at(j).pokerHuaSe > pokerArr.at(j - 1).pokerHuaSe)
				{
					PokerVO pk = pokerArr.at(j);
					pokerArr.at(j) = pokerArr.at(j - 1);
					pokerArr.at(j - 1) = pk;
				}
			}
		}
	}

	//开始分堆
	vector<vector<PokerVO>> Arr = {};
	vector<PokerVO> pokerArr1 = {};
	if (pokerArr.size() != 0)
	{
		pokerArr1.push_back(pokerArr.at(0));
		if (pokerArr.size() == 1)
		{
			Arr.push_back(pokerArr1);
		}
		for (int i = 1; i < pokerArr.size(); i++)
		{
			int len = pokerArr1.size();
			if (pokerArr.at(i).pokerNum == pokerArr1.at(len - 1).pokerNum)
			{
				pokerArr1.push_back(pokerArr.at(i));
			}
			else
			{
				Arr.push_back(pokerArr1);
				pokerArr1.clear();
				pokerArr1.push_back(pokerArr.at(i));
			}
			if (i == pokerArr.size() - 1)
			{
				Arr.push_back(pokerArr1);
			}
		}
	}

	//把用户自定义排序的牌放到最后
	for (int i = 0; i < changePosPokerArr.size(); i++)
	{
		if (changePosPokerArr.at(i).size() > 0)
		{
			Arr.push_back(changePosPokerArr.at(i));
		}

	}
	return Arr;
}