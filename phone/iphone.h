#ifndef IPHONE_H
#define IPHONE_H
#include "phone.h"

class IPhone : public Phone
{
public:
    IPhone() = delete;
    IPhone(string model, string color, OS * os) : Phone("IPhone", model, color, os) {}

    void call() override
    {
        cout << "Call on IPhone" << endl;
    }

    void sendSMS() override
    {
        cout << "Send SMS on IPhone" << endl;
    }

    void browseInternet() override
    {
        cout << "Browse Internet on IPhone" << endl;
    }
    
    ~IPhone() override
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
#endif // IPHONE_H
