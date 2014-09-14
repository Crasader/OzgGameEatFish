#ifndef __OzgGameEatFish__GameLayer__
#define __OzgGameEatFish__GameLayer__

#include <iostream>
#include "BaseLayer.h"
#include "BaseFishNode.h"
#include "EnemyFishNode.h"

namespace eatfish
{
	namespace scene
	{
		class GameLayer;
	}
}

class eatfish::scene::GameLayer : public eatfish::scene::BaseLayer
{

private:

	int m_stageNum; //关卡
	int m_score; //分数

	int m_eatFish; //吃了鱼的分数，用来判断变大的，player死了会清0
	int m_eatFishTotal; //吃了鱼的总数
	int m_eatFishTotalType1And2; //吃了Type1和2的鱼的总数
	int m_eatFishTotalType3; //吃了Type3的鱼的总数
	int m_eatFishTotalType4; //吃了Type4的鱼的总数

	int m_playerLife; //

	std::string m_bg;

	void onButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType);
	
	void gameStart(float delay);
	void gameStartCallback();

	void gameRestart(float delay);
	void gameRestartCallback();

	void enabledTouchEvent(bool enabled);

	bool onLayerTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onLayerTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onLayerTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void enemyFishEmergence(eatfish::element::BaseFishNode* enemyFishNode);
	cocos2d::Vec2 enemyFishRandomLeftPoint(eatfish::element::BaseFishNode* enemyFishNode);
	cocos2d::Vec2 enemyFishRandomRightPoint(eatfish::element::BaseFishNode* enemyFishNode);
	
	void changeScore(eatfish::element::EnemyFishNode::EnemyFishType type);
	void changePlayerLife(int playerLife);
    
    void onDialogBtnNo(cocos2d::Node* sender);
    void onDialogBtnYes(cocos2d::Node* sender);
    
public:

	enum class ChildTag
	{
		BG = 1,
		BLISTER_LEFT = 2,
		BLISTER_RIGHT = 3,
		LAB_STAGE_NUM = 4,
		LAB_SCORE = 5,
		LAB_FISH_LIFE = 6,
		BTN_PAUSE = 7,
		PROGRESS_BG = 8,
		PROGRESS = 9,
		FISH_LIFE = 10,
		FISH_NODE = 11,
		FISH_PLAYER = 20,
        PAUSE_NODE = 21,
        BTN_RESUME = 22,
        BTN_SOUND = 23,
        BTN_EFFECT = 24,
        BTN_EXIT = 25,
        MASK = 26,
        CLEAR_NODE = 27,
        BTN_NEXT = 28,
        GAMEOVER_NODE = 29,
        BTN_RESTART = 30
        
	};

	virtual ~GameLayer();
	virtual bool init();

	CREATE_FUNC(GameLayer);
	static cocos2d::Scene* createScene();

	void update(float delay);

	void enemyFishMoveEnd(cocos2d::Node* sender);
};

#endif
