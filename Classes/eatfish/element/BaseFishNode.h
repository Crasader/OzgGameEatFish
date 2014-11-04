#ifndef __OzgGameEatFish__BaseFishNode__
#define __OzgGameEatFish__BaseFishNode__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

namespace eatfish
{
	namespace element
	{
		class BaseFishNode;
	}
}

class eatfish::element::BaseFishNode : public cocos2d::Node
{

protected:

	std::vector<std::string> m_animSpriteList;
	std::string m_animKey;

	void playAnim();

	void cumpAutoHide(cocos2d::Node* sender);
	virtual void paralysisEnd(cocos2d::Node* sender);
	
public:

	enum class ChildTag
	{
		FISH = 1,
		CENTER_POINT = 2,
		CUMP = 3
	};

	enum class Orientation
	{
		LEFT = 1,
		RIGHT = 2
	};

	Orientation m_orientation; //朝向
	bool m_isMoving;

	virtual ~BaseFishNode();
	virtual bool init();

	cocos2d::Rect centerRect();

	void orientationRight();
	void orientationLeft();

	virtual void cump();
	virtual void paralysis();

	virtual void pause();
	virtual void resume();

};

#endif
