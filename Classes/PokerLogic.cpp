#include "PokerLogic.h"
#include "SGTools.h"

int PokerLogic::zhuPaiNum = -1;
vector<vector<int>> PokerLogic::num10Arr = 
{
	/*��Ӧ��ʮ����  2~A С��  ����   ����÷���졢��
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
	{ 0x41 },							//С��
	{ 0X42 }							//����
};

PokerLogic::PokerLogic()
{

}

PokerLogic::~PokerLogic()
{
	num10Arr.clear();
}

/*
	��ȡ��ֵ ����߲��������ơ����ڼ��ƹ��ܣ�
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
	��ȡ��ֵ 0~14(2~A~����)
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
				//���ж��Ƿ��Ǳ��ֵ�����
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

//��ȡ�ƵĻ�ɫ(0~4)
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

//�Լ������е����
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

//���Ƶ�ID����������ֵ�Ӵ�С����ɫ�Ӻ��ҵ����飩
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
			//��ֵ��ͬ������±Ƚϻ�ɫ
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

//���Ƶ�ID������ֵ���зֶѣ�����ͬ��ֵ�ķŵ�һ���У�
vector<vector<int>> PokerLogic::fenPokerIDArr(vector<int> pokerIDArr)
{
	//�Ƚ��Ƶ�ID����������ֵ�Ӵ�С����ɫ�Ӻ��ҵ����飩
	pokerIDArr = sortPokerIDArr(pokerIDArr);

	//��ʼ�ֶ�
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

//���Ƹ�����ֵ���½��зֶѣ�����ͬ��ֵ�ķŵ�һ���У�
vector<vector<PokerVO*>> PokerLogic::reFenPokerArr(vector<PokerVO*> pokerArr)
{
	//�Ƚ��Ƶ�ID����������ֵ�Ӵ�С����ɫ�Ӻ��ҵ����飩
	//���޳��û��Զ����ų�һ�е���
	vector<vector<PokerVO*>> changePosPokerArr = {};
	changePosPokerArr.resize(100);	//ע�⣺��߷����СΪ100��������һ�ų���100�λ���� ~`������Ѿ���ҵ㣬=��=��
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
				//��ֵ��ͬ������±Ƚϻ�ɫ
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

		//��ʼ�ֶ�
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

	//���û��Զ���������Ʒŵ����
	for (int i = 0; i < changePosPokerArr.size(); i++)
	{
		if (changePosPokerArr.at(i).size() > 0)
		{
			Arr.push_back(changePosPokerArr.at(i));
		}

	}

	return Arr;
}

//���Ƹ�����ֵ���½��зֶѣ�����ͬ��ֵ�ķŵ�һ���У�
vector<vector<PokerVO>> PokerLogic::reFenPokerArr1(vector<PokerVO> pokerArr)
{
	if (pokerArr.size() == 0)
		return {};
	//�Ƚ��Ƶ�ID����������ֵ�Ӵ�С����ɫ�Ӻ��ҵ����飩
	//���޳��û��Զ����ų�һ�е���
	vector<vector<PokerVO>> changePosPokerArr = {};
	changePosPokerArr.resize(100);	//ע�⣺��߷����СΪ100��������һ�ų���100�λ���� ~`������Ѿ���ҵ㣬=��=��
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
			//��ֵ��ͬ������±Ƚϻ�ɫ
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

	//��ʼ�ֶ�
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

	//���û��Զ���������Ʒŵ����
	for (int i = 0; i < changePosPokerArr.size(); i++)
	{
		if (changePosPokerArr.at(i).size() > 0)
		{
			Arr.push_back(changePosPokerArr.at(i));
		}

	}
	return Arr;
}