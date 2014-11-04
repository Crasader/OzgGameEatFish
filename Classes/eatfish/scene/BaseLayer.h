#ifndef __OzgGameEatFish__BaseLayer__
#define __OzgGameEatFish__BaseLayer__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

namespace eatfish
{
	namespace scene
	{
		class BaseLayer;
	}
}

class eatfish::scene::BaseLayer : public cocos2d::Layer
{
public:

	virtual ~BaseLayer();
	virtual bool init();

};

#endif
