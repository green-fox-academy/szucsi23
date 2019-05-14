//
// Created by hun46 on 2019. 04. 24..
//

#ifndef WIRELESSDEVICES_DEVICE_H
#define WIRELESSDEVICES_DEVICE_H

#include <iostream>

class Device {
public:

    Device(std::string _id);

    std::string getId() const;

private:
    std::string _id;
};


#endif //WIRELESSDEVICES_DEVICE_H
