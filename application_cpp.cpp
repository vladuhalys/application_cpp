#include "os/android.h"
#include "os/ios.h"
#include "phone/iphone.h"
#include "phone/phone.h"
#include "phone/samsung.h"

enum StoreIndex
{
    GooglePlayIndex = 0,
    AppStoreIndex = 1
};

enum OSIndex
{
    AndroidIndex = 0,
    IOSIndex = 1
};

enum PhoneIndex
{
    SamsungIndex = 0,
    IPhoneIndex = 1
};

int main()
{
    Store ** store = new Store*[2];
    store[GooglePlayIndex] = new GooglePlay();
    store[AppStoreIndex] = new AppStore();

    Application ** app = new Application*[5];
    app[0] = new Application("Facebook", "300.0");
    app[1] = new Application("Instagram", "200.0");
    app[2] = new Application("WhatsApp", "400.0");
    app[3] = new Application("Telegram", "500.0");
    app[4] = new Application("TikTok", "100.0");

    for (int i = 0; i < 5; i++)
    {
        store[GooglePlayIndex]->installApp(*app[i]);
        store[AppStoreIndex]->installApp(*app[i]);
    }

    OS ** os = new OS*[2];
    os[AndroidIndex] = new Android("10.0", store[GooglePlayIndex]);
    os[IOSIndex] = new IOS("14.0", store[AppStoreIndex]);

    Phone ** phone = new Phone*[2];
    phone[SamsungIndex] = new Samsung("Galaxy S20", "Black", os[AndroidIndex]);
    phone[IPhoneIndex] = new IPhone("12 Pro Max", "White", os[IOSIndex]);
    cout << endl<<endl;
    for (int i = 0; i<2; i++)
    {
        phone[i]->getOS()->showAllApps();
    }
    cout << endl<<endl;
    phone[SamsungIndex]->getOS()->uninstallApp(*app[0]);
    phone[IPhoneIndex]->getOS()->uninstallApp(*app[4]);

    for (int i = 0; i<2; i++)
    {
        phone[i]->getOS()->showAllApps();
    }
    
    

    
    return 0;
}
