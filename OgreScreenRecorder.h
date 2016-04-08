#ifndef __OGRE_SCREEN_RECORDER__
#define __OGRE_SCREEN_RECORDER__

#include <OgreFrameListener.h>
#include <OgreRoot.h>
#include <OgreRenderWindow.h>

#include <iostream>

class OgreScreenRecorder : public Ogre::FrameListener
{
public:
    OgreScreenRecorder(Ogre::Root& r, Ogre::RenderWindow& w);
    ~OgreScreenRecorder();

private:
    bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    Ogre::Root& mRoot;
    Ogre::RenderWindow& mWindow;
    int cnt;
    char filename_buf[25];
};

#endif // __OGRE_SCREEN_RECORDER__