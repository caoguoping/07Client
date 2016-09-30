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
		获取牌值 （这边不考虑主牌。用于记牌功能）
		*/
		static int getPokerNum2(int id);

		//获取牌值
		static int getPokerNum(int id);

		//获取花色
		static int getPokerHuaSe(int id);

		//自己手牌中癞子的数量
		static vector<PokerVO*> getMyLaiZiArr(vector<PokerVO*> myPokerArr);

		//将牌的ID进行排序（牌值从大到小，花色从黑桃到方块）
		static vector<int> sortPokerIDArr(vector<int> pokerIDArr);

		//将牌的ID根据牌值进行分堆（把相同牌值的放到一堆中）
		static vector<vector<int>> fenPokerIDArr(vector<int> pokerIDArr);

		static vector<vector<PokerVO*>> reFenPokerArr(vector<PokerVO*> pokerArr);

		static vector<vector<PokerVO>> reFenPokerArr1(vector<PokerVO> pokerArr);

		public:

		//牌的id二维容器 [14][4]
		static vector<vector<int>> num10Arr;
};