# esp-now-test
A simple test implementation of the ESP-Now protocol.

The idea is to use this protocol for several IOT devices in my smart home setup. 
One node will be the bridge to my Home Assistant using MQTT. All others communicate to thi sbridge using ESP-Now.
The advantage is that there is only one node connected to my WiFi network, reducing used IP addresses and workload for router and Access points.

Since I use all different kinds of hardware for my devices (different kinds of ESP32/ESP8266 boards), the code has to be so portable as possible.
Different build definitions are included in the platformio*.ini files.
