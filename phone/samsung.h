#ifndef SAMSUNG_H
#define SAMSUNG_H
#include "phone.h"

class Samsung : public Phone
{
public:
    Samsung() = delete;
    Samsung(string model, string color, OS * os) : Phone("Samsung", model, color, os) {}

    void call() override
    {
        cout << "Call on Samsung" << endl;
    }

    void sendSMS() override
    {
        cout << "Send SMS on Samsung" << endl;
    }

    void browseInternet() override
    {
        cout << "Browse Internet on Samsung" << endl;
    }

    ~Samsung() override
    {
        this->_name.clear();
        this->_model.clear();
        this->_color.clear();
        if (_os != nullptr)
        {
            delete _os;
        }
    }
};
#endif // SAMSUNG_H
