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

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
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
    
    Scene *s = Director::getInstance()->getRunningScene();
    for (int i = 0; i < (int)s->getChildren().size(); i++)
    {
        if(dynamic_cast<eatfish::scene::GameLayer*>(s->getChildren().at(i)) != NULL)
        {
            eatfish::scene::GameLayer *layer = (eatfish::scene::GameLayer*)s->getChildren().at(i);
            layer->scenePause();
            break;
        }
    }
    
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
