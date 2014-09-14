#ifndef __OzgGameEatFish__PlayerFishNode__
#define __OzgGameEatFish__PlayerFishNode__

#include "BaseFishNode.h"
#include "EnemyFishNode.h"

namespace eatfish
{
	namespace element
	{
		class PlayerFishNode;
	}
}

class eatfish::element::PlayerFishNode : public eatfish::element::BaseFishNode
{

private:
	void scoreEffectMoveEnd(cocos2d::Node* sender);

public:

	enum class Status
	{
		SMALL = 1,
		NORMAL = 2,
		BIG = 3
	};

	enum class ChildTag
	{
		WATER = 10,
		FLOWER = 11
	};

	Status m_status;
	bool m_isInvincible; //是否正在无敌状态

	virtual ~PlayerFishNode();
	virtual bool init();

	CREATE_FUNC(PlayerFishNode);

	void changeStatus(Status status);

	void invincible();
	void invincibleCallback(float delay);

	void invincible2();
	void invincible2Callback1(float delay);
	void invincible2Callback2(float delay);

	virtual void pause();
	virtual void resume();
	
	virtual void cump(eatfish::element::EnemyFishNode::EnemyFishType type);

};

#endif
