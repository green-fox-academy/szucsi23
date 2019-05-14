//
// Created by hun46 on 2019. 04. 24..
//

#ifndef WIRELESSDEVICES_NETWORKDEVICE_H
#define WIRELESSDEVICES_NETWORKDEVICE_H

#include "Device.h"

class NetworkDevice : virtual public Device{
public:
    NetworkDevice(std::string id, int bandwidth);

protected:
    int _bandwidth;
};



#endif //WIRELESSDEVICES_NETWORKDEVICE_H
