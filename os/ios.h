#ifndef IOS_H
#define IOS_H

#include <iostream>

#include "os.h"

class IOS : public OS
{
public:
    IOS() = delete;
    IOS(string version, Store * appStore) : OS("iOS", version, appStore) {}
    
    ~IOS() override
    {
        this->_name.clear();
        this->_version.clear();
    }
};
#endif // IOS_H
