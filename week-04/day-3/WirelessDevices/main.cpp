#include <iostream>
#include "WirelessAdapter.h"
#include "NetworkDevice.h"
#include "USBDevice.h"
#include "Device.h"

enum USBType{
    USB_TYPE_2,
    USB_TYPE_3
};

int main( int argc, char* args[] )
{
    WirelessAdapter adapter("da4c32fb21", USB_TYPE_2, 100);
    adapter.info();
}