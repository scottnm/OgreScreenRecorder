#include "OgreScreenRecorder.h"
#include <cstring>

std::ios_base::fmtflags mFF = std::ios_base::dec | std::ios_base::right;

OgreScreenRecorder::OgreScreenRecorder(Ogre::Root& r, Ogre::RenderWindow& w)
    : mRoot(r), mWindow(w), cnt(0)
{
    const char* fname = "screenshots/f_------.jpg";
    for(size_t i = 0; i < strlen(fname); ++i)
    {
        filename_buf[i] = fname[i];
    }
    filename_buf[24] = '\0';
    mRoot.addFrameListener(this);
}

OgreScreenRecorder::~OgreScreenRecorder()
{
    mRoot.removeFrameListener(this);
}

bool OgreScreenRecorder::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    (void)evt; // UNUSED param

    ++cnt;
    assert(cnt < 999999);
    char* picIdOfs = filename_buf + 14;
    Ogre::String s = Ogre::StringConverter::toString(cnt, 6, '0', mFF); 
    std::copy(s.cbegin(), s.cend(), picIdOfs);
    mWindow.writeContentsToFile(Ogre::String(filename_buf));
    return true;
}
