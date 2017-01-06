#include "CreateRoleView.h"
#include "SGTools.h"
CreateRoleView::CreateRoleView()
{
	rootNode = CSLoader::createNode("createRole.csb");
	addChild(rootNode);

	Node  *node1, *node2, *node3, *node4;
	UIGet_Node("character1", rootNode, node1)
	UIGet_Node("character2", rootNode, node2)
	UIGet_Node("character3", rootNode, node3)
	UIGet_Node("character4", rootNode, node4)
	UIGet_Button("clickBtn", node1, character1Btn)
	UIGet_Button("clickBtn", node2, character2Btn)
	UIGet_Button("clickBtn", node3, character3Btn)
	UIGet_Button("clickBtn", node4, character4Btn)
	UIGet_Button("autoBtn", rootNode, autoBtn)
	UIGet_Button("createBtn", rootNode, createBtn)

	BTN_EVENT(character1Btn, 10022)
	BTN_EVENT(character2Btn, 10023)
	BTN_EVENT(character3Btn, 10024)
	BTN_EVENT(character4Btn, 10025)
	BTN_EVENT(autoBtn       ,  10026)
	BTN_EVENT(createBtn    ,   10027)
}
CreateRoleView::~CreateRoleView()
{

}

void CreateRoleView::initView()
{
	setCharacterState(3);
}

void CreateRoleView::setCharacterState(int index)
{
	//
	this->stopAllActions();

	Node* character1Node = rootNode->getChildByName("character1");
	Node* character2Node = rootNode->getChildByName("character2");
	Node* character3Node = rootNode->getChildByName("character3");
	Node* character4Node = rootNode->getChildByName("character4");

	switch (index)
	{
	case 1:
		showCharacterFace(character1Node, true, 1);
		showCharacterFace(character2Node, false, 2);
		showCharacterFace(character3Node, false, 3);
		showCharacterFace(character4Node, false, 4);
		break;
	case 2:
		showCharacterFace(character1Node, false, 1);
		showCharacterFace(character2Node, true, 2);
		showCharacterFace(character3Node, false, 3);
		showCharacterFace(character4Node, false, 4);
		break;
	case 3:
		showCharacterFace(character1Node, false, 1);
		showCharacterFace(character2Node, false, 2);
		showCharacterFace(character3Node, true, 3);
		showCharacterFace(character4Node, false, 4);
		break;
	case 4:
		showCharacterFace(character1Node, false, 1);
		showCharacterFace(character2Node, false, 2);
		showCharacterFace(character3Node, false, 3);
		showCharacterFace(character4Node, true, 4);
		break;
	}
}

void CreateRoleView::showCharacterFace(Node* node, bool isSelected,int index)
{
	if (isSelected)
		node->setColor(ccc3(255, 255, 255));
	else
		node->setColor(ccc3(128, 128, 128));

	Action1 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_1"));
	Action2 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_2"));
	Action3 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_3"));
	Action4 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_4"));
	switch (index)
	{
	case 1:
		if (isSelected)
			Action1->getAnimation()->play("mother_1_zhaoshou", -1, 0);
		else
		{
			Action1->getAnimation()->play("mother_1_daiji", -1, 0);
			Action1->getAnimation()->stop();
		}
		Action1->setVisible(true);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 2:
		if (isSelected)
			Action2->getAnimation()->play("father_1_zhaoshou", -1, 0);
		else
		{
			Action2->getAnimation()->play("father_1_daiji", -1, 0);
			Action2->getAnimation()->stop();
		}
		Action1->setVisible(false);
		Action2->setVisible(true);
		Action3->setVisible(false);
		Action4->setVisible(false);
		break;
	case 3:
		if (isSelected)
			Action3->getAnimation()->play("mei_1_zhaoshou", -1, 0);
		else
		{
			Action3->getAnimation()->play("mei_1_daiji", -1, 0);
			Action3->getAnimation()->stop();
		}
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(true);
		Action4->setVisible(false);
		break;
	case 4:
		if (isSelected)
			Action4->getAnimation()->play("ling_1_zhaoshou", -1, 0);
		else
		{
			Action4->getAnimation()->play("ling_1_daiji", -1, 0);
			Action4->getAnimation()->stop();
		}
		Action1->setVisible(false);
		Action2->setVisible(false);
		Action3->setVisible(false);
		Action4->setVisible(true);
		break;
	}

	if (isSelected)
	{
		//
		auto call1 = CallFunc::create(
			bind(&CreateRoleView::showDaiJiFace, this, node, index)
			);
		this->runAction(Sequence::create(DelayTime::create(1.5f), call1, nullptr));
	}

}

void CreateRoleView::showDaiJiFace(Node* node, int index)
{
	Action1 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_1"));
	Action2 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_2"));
	Action3 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_3"));
	Action4 = dynamic_cast<cocostudio::Armature*>(node->getChildByName("character_4"));

	switch (index)
	{
		case 1:
			Action1->getAnimation()->play("mother_1_daiji", -1, 1);
			break;
		case 2:
			Action2->getAnimation()->play("father_1_daiji", -1, 1);
			break;
		case 3:
			Action3->getAnimation()->play("mei_1_daiji", -1, 1);
			break;
		case 4:
			Action4->getAnimation()->play("ling_1_daiji", -1, 1);
			break;
	}
}