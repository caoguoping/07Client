#pragma once
#include "cocos2d.h"
#include "GameDataModel.h"
#include "PokerLogic.h"

USING_NS_CC;
using namespace std;
/*
	�����߼���
*/
class OutPokerLogicRule
{
	public :
		OutPokerLogicRule();
		~OutPokerLogicRule();

		//�жϳ��Ƶ����ͣ��������ͷ���nullptr��
		static PokerTypeVO outPokerType(vector<PokerVO*> outPokerArr);

		//�ж��Ƿ��ܸ�����
		static bool canFollowPoker(vector<PokerVO*> otherPokerArr, vector<PokerVO*> myPokerArray);

		//ð������
		static vector<PokerVO*> BubbleSort(vector<PokerVO*> outpokerArr);

		//ð������
		static vector<PokerVO*> BubbleSort2(vector<PokerVO*> outpokerArr);

		//
		static vector<PokerTypeVO> fenXiShouPai(vector<PokerVO*> pokerArr);

		//����ȡ����ĳ�����͵����п��ܵ���ϰ���Ȩֵ��С��������
		static vector<vector<PokerVO*>> SortGroupArr(vector<vector<PokerVO*>> groupArr);

		//
		static vector<vector<PokerVO*>> FollowPoker(vector<PokerVO*> otherPokerIDArr, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡͬ��˳
		static vector<vector<PokerVO*>> TiQuTongHuaShun(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡը��
		static vector<vector<PokerVO*>> TiQuBoom(int value, int len, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		/************************************************************************/
		/* ���͵��ж�															    */
		/************************************************************************/
		//1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
		/////6����//////////////////
		//�Ƿ������ӣ����Ƿ���nullptr��
		static PokerTypeVO isLianDui(vector<PokerVO*> pokerArr);

		//�Ƿ��Ƿɻ�
		static PokerTypeVO isFeiJi(vector<PokerVO*> pokerArr);

		/////5����/////////////////
		//�Ƿ���˳��(˳��ֻ��5��)
		static PokerTypeVO isShunZi(vector<PokerVO*> pokerArr);

		//�Ƿ���������
		static PokerTypeVO isSanDaiEr(vector<PokerVO*> pokerArr);

		//�Ƿ���ͬ��˳
		static PokerTypeVO isTongHuaShun(vector<PokerVO*> pokerArr);

		////4����/////////////////
		//���
		static PokerTypeVO isHuoJian(vector<PokerVO*> pokerArr);

		////3����/////////////////
		//3��
		static PokerTypeVO isSanZhang(vector<PokerVO*> pokerArr);

		////2����////////////////
		//����
		static PokerTypeVO isDuiZi(vector<PokerVO*> pokerArr);

		////1����///////////////
		static PokerTypeVO isDanZhang(vector<PokerVO*> pokerArr);

		//�Ƿ���ը����4�����ϣ�
		static PokerTypeVO isBoom(vector<PokerVO*> pokerArr);

		/************************************************************************/
		/* ��ȡ����				                                                */
		/************************************************************************/
		//1.���� 2.���� 3.3��  4.3��2 5.˳�� 6.���� 7.�ɻ�  8.ը�� 9.ͬ��˳ 10.���
		//��ȡ����
		static vector<vector<PokerVO*>> TiQuDanPai(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡ����
		static vector<vector<PokerVO*>> TiQuDuiZi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡ3��
		static vector<vector<PokerVO*>> TiQuSanZhang(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡ3��2
		static vector<vector<PokerVO*>> TiQuSanDaiEr(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡ˳��
		static vector<vector<PokerVO*>> TiQuShunZi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡ����
		static vector<vector<PokerVO*>> TiQuLianDui(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);

		//��ȡ�ɻ�
		static vector<vector<PokerVO*>> TiQuFeiJi(int value, vector<PokerTypeVO> myPokerTypeArr, vector<PokerVO*> LaiZiArr);
};