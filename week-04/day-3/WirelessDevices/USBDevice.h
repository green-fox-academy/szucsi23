//
// Created by hun46 on 2019. 04. 24..
//

#ifndef WIRELESSDEVICES_USBDEVICE_H
#define WIRELESSDEVICES_USBDEVICE_H

#include "Device.h"

class USBDevice : virtual public Device{
public:
    USBDevice(std::string id, int usbType);

private:
    int _usbType;
};


#endif //WIRELESSDEVICES_USBDEVICE_H
