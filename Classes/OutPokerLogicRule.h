#pragma once
#include "cocos2d.h"
#include "GameDataModel.h"
#include "PokerLogic.h"

USING_NS_CC;
using namespace std;
/*
	出牌逻辑类
*/
class OutPokerLogicRule
{
	public :
		OutPokerLogicRule();
		~OutPokerLogicRule();

		//判断出牌的牌型（错误牌型返回nullptr）
		static PokerTypeVO outPokerType(vector<PokerVO*> outPokerArr);

		//判断是否能跟上牌
		static bool canFollowPoker(vector<PokerVO*> otherPokerArr, vector<PokerVO*> myPokerArray);

		//冒泡排序
		static vector<PokerVO*> BubbleSort(vector<PokerVO*> outpokerArr);

		//冒泡排序
		static vector<PokerVO*> BubbleSort2(vector<PokerVO*> outpokerArr);

		//
		static vector<PokerTypeVO> fenXiShouPai(vector<PokerVO*> pokerArr);

		//将提取到的某种牌型的所有可能的组合按照权值从小到大排序
		static vector<vector<PokerVO*>> SortGroupArr(vector<vector<PokerVO*>> groupArr);

		//
		static vector<vector<PokerVO*>> FollowPoker(vector<PokerVO*> otherPokerIDArr, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取同花顺
		static vector<vector<PokerVO*>> TiQuTongHuaShun(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取炸弹
		static vector<vector<PokerVO*>> TiQuBoom(int value, int len, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		/************************************************************************/
		/* 牌型的判断															    */
		/************************************************************************/
		//1.单张 2.对子 3.3张  4.3带2 5.顺子 6.连队 7.飞机  8.炸弹 9.同花顺 10.火箭
		/////6张牌//////////////////
		//是否是连队（不是返回nullptr）
		static PokerTypeVO isLianDui(vector<PokerVO*> pokerArr);

		//是否是飞机
		static PokerTypeVO isFeiJi(vector<PokerVO*> pokerArr);

		/////5张牌/////////////////
		//是否是顺子(顺子只能5张)
		static PokerTypeVO isShunZi(vector<PokerVO*> pokerArr);

		//是否是三带二
		static PokerTypeVO isSanDaiEr(vector<PokerVO*> pokerArr);

		//是否是同花顺
		static PokerTypeVO isTongHuaShun(vector<PokerVO*> pokerArr);

		////4张牌/////////////////
		//火箭
		static PokerTypeVO isHuoJian(vector<PokerVO*> pokerArr);

		////3张牌/////////////////
		//3张
		static PokerTypeVO isSanZhang(vector<PokerVO*> pokerArr);

		////2张牌////////////////
		//对子
		static PokerTypeVO isDuiZi(vector<PokerVO*> pokerArr);

		////1张牌///////////////
		static PokerTypeVO isDanZhang(vector<PokerVO*> pokerArr);

		//是否是炸弹（4张以上）
		static PokerTypeVO isBoom(vector<PokerVO*> pokerArr);

		/************************************************************************/
		/* 提取牌型				                                                */
		/************************************************************************/
		//1.单张 2.对子 3.3张  4.3带2 5.顺子 6.连队 7.飞机  8.炸弹 9.同花顺 10.火箭
		//提取单张
		static vector<vector<PokerVO*>> TiQuDanPai(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取对子
		static vector<vector<PokerVO*>> TiQuDuiZi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取3张
		static vector<vector<PokerVO*>> TiQuSanZhang(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取3带2
		static vector<vector<PokerVO*>> TiQuSanDaiEr(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取顺子
		static vector<vector<PokerVO*>> TiQuShunZi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取连对
		static vector<vector<PokerVO*>> TiQuLianDui(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//提取飞机
		static vector<vector<PokerVO*>> TiQuFeiJi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);
};