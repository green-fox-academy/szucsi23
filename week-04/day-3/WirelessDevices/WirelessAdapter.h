//
// Created by hun46 on 2019. 04. 24..
//

#ifndef WIRELESSDEVICES_WIRELESSADAPTER_H
#define WIRELESSDEVICES_WIRELESSADAPTER_H

#include "USBDevice.h"
#include "NetworkDevice.h"

class WirelessAdapter : public USBDevice, public NetworkDevice{
public:
    WirelessAdapter(std::string id, int usbType, int bandwidth);
    void info();
};


#endif //WIRELESSDEVICES_WIRELESSADAPTER_H
