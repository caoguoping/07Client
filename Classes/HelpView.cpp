#include "HelpView.h"
#include "SGTools.h"

HelpView::HelpView()
{
	rootNode = CSLoader::createNode("help.csb");
	addChild(rootNode);

		UIGet_Button("closeBtn", rootNode, closeBtn)
		UIGet_ImageView("Image_38", rootNode, Image_38)
		BTN_EVENT(closeBtn, 13001)
		BTN_EVENT(Image_38, 13001)
}

HelpView::~HelpView()
{

}

void HelpView::initView()
{
		UIGet_ScrollView("ScrollView_0", rootNode, mScrollView[0])
		UIGet_ScrollView("ScrollView_1", rootNode, mScrollView[1])
		UIGet_ScrollView("ScrollView_2", rootNode, mScrollView[2])
		UIGet_ScrollView("ScrollView_3", rootNode, mScrollView[3])
		UIGet_ScrollView("ScrollView_4", rootNode, mScrollView[4])

		UIGet_CheckBox("CheckBox_0", rootNode, mCheckBox[0])
		UIGet_CheckBox("CheckBox_1", rootNode, mCheckBox[1])
		UIGet_CheckBox("CheckBox_2", rootNode, mCheckBox[2])
		UIGet_CheckBox("CheckBox_3", rootNode, mCheckBox[3])
		UIGet_CheckBox("CheckBox_4", rootNode, mCheckBox[4])

		for (int i = 0; i < 5; i++)
		{
			mCheckBox[i]->setTag(i);
			UIClick(mCheckBox[i], HelpView::clickCheckBox)
		}
		handleWhich(0);
}

void HelpView::handleWhich(int iWhich)
{
	for (int i = 0; i < 5; i++)
	{
		mCheckBox[i]->setSelected(false);
		mCheckBox[i]->setTouchEnabled(true);
		mScrollView[i]->setVisible(false);
	}
	mCheckBox[iWhich]->setSelected(true);
	mCheckBox[iWhich]->setTouchEnabled(false);
	mScrollView[iWhich]->setVisible(true);
}

void HelpView::clickCheckBox(Ref* pSender)
{
	PLayEffect(EFFECT_BTN);
	CheckBox*  checkBox = static_cast<CheckBox*>(pSender);
	int iwhich = checkBox->getTag();
	if (iwhich < 0 || iwhich >= 5)
	{
		return;
	}
	handleWhich(iwhich);

}
