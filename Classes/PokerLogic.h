#pragma once
#include "cocos2d.h"
#include "GameDataModel.h"

USING_NS_CC;
using namespace std;

class PokerLogic
{
	public:
		PokerLogic();
		~PokerLogic();

		//
		static int zhuPaiNum;

		/*
		��ȡ��ֵ ����߲��������ơ����ڼ��ƹ��ܣ�
		*/
		static int getPokerNum2(int id);

		//��ȡ��ֵ
		static int getPokerNum(int id);

		//��ȡ��ɫ
		static int getPokerHuaSe(int id);

		//�Լ���������ӵ�����
		static vector<PokerVO*> getMyLaiZiArr(vector<PokerVO*> myPokerArr);

		//���Ƶ�ID����������ֵ�Ӵ�С����ɫ�Ӻ��ҵ����飩
		static vector<int> sortPokerIDArr(vector<int> pokerIDArr);

		//���Ƶ�ID������ֵ���зֶѣ�����ͬ��ֵ�ķŵ�һ���У�
		static vector<vector<int>> fenPokerIDArr(vector<int> pokerIDArr);

		static vector<vector<PokerVO*>> reFenPokerArr(vector<PokerVO*> pokerArr);

		static vector<vector<PokerVO>> reFenPokerArr1(vector<PokerVO> pokerArr);

		public:

		//�Ƶ�id��ά���� [14][4]
		static vector<vector<int>> num10Arr;
};