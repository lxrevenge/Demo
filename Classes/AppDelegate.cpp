/*

Li Xiang  52mxj
1.0
Demo

*/
#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "WelcomeScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void AppDelegate::initGLContextAttrs()
{

    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("52mxj", Rect(0, 0, 480, 640));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(480, 640, ResolutionPolicy::SHOW_ALL);

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

	auto scene = WelcomeScene::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
