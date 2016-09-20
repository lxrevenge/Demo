/*

Li Xiang  52mxj
1.0
Demo

*/
#include "GameOverLayer.h"
#include "WelcomeScene.h"

bool GameOverLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size MyWinSize = Director::getInstance()->getVisibleSize();
	MenuItemSprite* ReStartBtn = MenuItemSprite::create(Sprite::create("uires_5.png"), Sprite::create("uires_5.png"), NULL, this, menu_selector(GameOverLayer::ReStart));
	ReStartBtn->setPosition(MyWinSize.width / 2, MyWinSize.height / 2 + 8);
	Menu* menu = Menu::create(ReStartBtn, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
	return true;
}

void GameOverLayer::ReStart(cocos2d::Ref * _pSender)
{
	
	WelcomeScene* scene = WelcomeScene::create();
	Director* pDirector = Director::getInstance();
	TransitionFade* jump = TransitionFade::create(0.3f, scene->createScene());
	pDirector->replaceScene(jump);

	
}