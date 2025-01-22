#ifndef ANDROID_H
#define ANDROID_H

#include <iostream>

#include "os.h"

class Android : public OS
{
public:
    Android() = delete;
    Android(string version, Store * googlePlay) : OS("Android", version, googlePlay) {}
    
    ~Android() override
    {
        this->_name.clear();
        this->_version.clear();
    }
};
#endif // ANDROID_H
