#include "AppDelegate.h"
#include "StartLayer.h"
#include "GameLayer.h"
#include "GameConfig.h"
#include "Strings.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLViewImpl::create(STRINGS_TITLE);
		glview->setFrameSize(960, 640);
        director->setOpenGLView(glview);
    }

	glview->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    //声音的处理
    if(UserDefault::getInstance()->getBoolForKey(GAME_CONFIG_BGSOUND, true))
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);
    else
        SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.0);
    
    if(UserDefault::getInstance()->getBoolForKey(GAME_CONFIG_EFFECT, true))
        SimpleAudioEngine::getInstance()->setEffectsVolume(1.0);
    else
        SimpleAudioEngine::getInstance()->setEffectsVolume(0.0);
    //声音处理结束
    
    // create a scene. it's an autorelease object
	auto scene = eatfish::scene::StartLayer::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    
    Scene *s = Director::getInstance()->getRunningScene();
    
    if(dynamic_cast<eatfish::scene::GameLayer*>(s->getChildren().at(0)) != NULL)
    {
        eatfish::scene::GameLayer *layer = (eatfish::scene::GameLayer*)s->getChildren().at(0);
        layer->scenePause();
    }
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
