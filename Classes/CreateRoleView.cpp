#include "CreateRoleView.h"
CreateRoleView::CreateRoleView()
{
	rootNode = CSLoader::createNode("createRole.csb");
	addChild(rootNode);
//	rootNode->setScale(0.8f, 0.8f);
// 	rootNode->runAction(Sequence::create(
// 		ScaleTo::create(0.2f, 1.03f),
// 		ScaleTo::create(0.15f, 1.0f),
// 		nullptr));

	BTN_ADD_TOUCH_EVENTLISTENER(Button, CreateRoleView, character1Btn, 10022, "clickBtn", "character1");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, CreateRoleView, character2Btn, 10023, "clickBtn", "character2");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, CreateRoleView, character3Btn, 10024, "clickBtn", "character3");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, CreateRoleView, character4Btn, 10025, "clickBtn", "character4");
	BTN_ADD_TOUCH_EVENTLISTENER(Button, CreateRoleView, autoBtn, 10026, "autoBtn", NULL)
	BTN_ADD_TOUCH_EVENTLISTENER(Button, CreateRoleView, createBtn, 10027, "createBtn", NULL)
}
CreateRoleView::~CreateRoleView()
{
	BTN_REMOVE_TOUCH_EVENTLISTENER(CreateRoleView, character1Btn, 10022);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CreateRoleView, character2Btn, 10023);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CreateRoleView, character3Btn, 10024);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CreateRoleView, character4Btn, 10025);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CreateRoleView, autoBtn, 10026);
	BTN_REMOVE_TOUCH_EVENTLISTENER(CreateRoleView, createBtn, 10027);
	delete rootNode;
	rootNode = NULL;
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