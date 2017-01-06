#ifndef  _SevenDayGiftView_
#define  _SevenDayGiftView_

#include "cocos2d.h"
#include "BlueSky.h"
#include "cocostudio/CocoStudio.h"

class  SevenDayGiftView : public BlueSkyView
{
public:
	SevenDayGiftView();
	~SevenDayGiftView();

	void initView(bool isShowCloseBtn);
	void showGift();

private:
	Button   * getGiftBtn;
	Button   * closeBtn  ;
	ImageView* Image_38  ;

	ImageView*  imgFrame;
	ImageView*  imgGift[7];
	ImageView*  imgMask[7];

	//第一天
	ImageView* day1_1;
	ImageView* day1_2;
	ImageView* day1_3;

	//第2天
	ImageView* day2_1;
	ImageView* day2_2;
	ImageView* day2_3;

	//第3天
	ImageView* day3_1;
	ImageView* day3_2;
	ImageView* day3_3;

	//第4天
	ImageView* day4_1;
	ImageView* day4_2;
	ImageView* day4_3;

	//第5天
	ImageView* day5_1;
	ImageView* day5_2;
	ImageView* day5_3;

	//第6天
	ImageView* day6_1;
	ImageView* day6_2;
	ImageView* day6_3;

	//第7天
	ImageView* day7_1;
	ImageView* day7_2;
	ImageView* day7_3;

	//明日再来领取
	ImageView* noGiftImage1;
	ImageView* noGiftImage2;

	//
	void showDay1Gift(bool isGet);
	void showDay2Gift(bool isGet);
	void showDay3Gift(bool isGet);
	void showDay4Gift(bool isGet);
	void showDay5Gift(bool isGet);
	void showDay6Gift(bool isGet);
	void showDay7Gift(bool isGet);
};

#endif