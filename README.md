# esp-now-test

A simple test implementation of the ESP-Now protocol.

The idea is to use this protocol for several IOT devices in my smart home setup.
One node will be the bridge to my Home Assistant using MQTT. All others communicate to thi sbridge using ESP-Now.
The advantage is that there is only one node connected to my WiFi network, reducing used IP addresses and workload for router and Access points.

Since I use all different kinds of hardware for my devices (different kinds of ESP32/ESP8266 boards), the code has to be so portable as possible.
Different build definitions are included in the platformio*.ini files.

The following borads have been defined:

| Board            | Environment         | Chip     | Display            | Controller         |
|------------------|---------------------|----------|--------------------|--------------------|
| ESP-01 512K      | esp01_512k          | ESP 8266 |                    |                    |
| ESP-01 1MB       | esp01_1m            | ESP 8266 |                    |                    |
| Wemos D1 mini    | d1_mini_lite        | ESP 8266 |                    | :heavy_check_mark: |
| Heltec WifiKit 8 | heltec_wifi_kit_8   | ESP 8266 | :heavy_check_mark: |                    |
| Wemos D1 mini32  | wemos_d1_mini32     | ESP 32   |                    |                    |
| Do-It Devkit 32  | esp32doit-devkit-v1 | ESP 32   |                    | :heavy_check_mark: |
| M5Stack Fire     | m5stack-fire        | ESP 32   | :heavy_check_mark: | :heavy_check_mark: |
