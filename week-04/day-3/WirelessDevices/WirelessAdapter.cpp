//
// Created by hun46 on 2019. 04. 24..
//

#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(std::string id, int usbType, int bandwidth) : USBDevice(id, usbType), NetworkDevice(id, bandwidth), Device(id)
{}

void WirelessAdapter::info()
{
    std::cout << std::endl;
}
