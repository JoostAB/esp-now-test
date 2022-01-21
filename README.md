# esp-now-test

## Overview

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

---  
  
<br>

## Topology

A network consists of several nodes, from which one has the role of [controller](#controller). 

The non-controller nodes (aka [slaves](#slave)) communicate with the controller using the esp-now protocol. They report their status and listen for commands. They can also report events.

The controller is responsible for communication to the outside world over standard WiFi. Therefore the controller must be connected to an accesspoint or router connected to the home network and maybe the internet. The controller normally is also playing a slave role.

Which device is the controller doesn't matter, since there is no hardware difference. All nodes are ESP32/ESP8266 based, and therefore they are all capable of communicating with a wireless network. The controller role is dynamically assigned (see [Controller selection](#controller-selection)) among the available nodes, and as soon the node player the controller role is offline, a new controller is chosen.

## Slave

When a slave is turned on, it will send an [introduction message](#introduction-message) to the broadcast (MAC)address `FF:FF:FF:FF:FF:FF`. The introduction message contains the MAC address of the slave and name for easy recognition. The running controller will respond with a [welcome message](#welcome-message) containing its mac address and register the slave as new node. The slave now knows who the controller is and will from now on address all communication to the controller directly using its MAC address.  
If there is no response from a running controller node, the new node will take on the role of controller (see [Controller initialization](#controller-initialization)) by connecting to the wifi network and wait for other nodes to come online as slaves.

The slave can be anything from a simple lightbulb switch, a complete weatherstation, smart plug or anything else you have in your smart-home. 

## Controller

The controller is the central accesspoint to the whole esp-now network. It acts as a gateway between the esp-now network and the home wifi, so that you can access these nodes with normal wifi enabled devices like a smartphone, computer or smart-home central like Domotica or HomeAssistant.

Using this WiFi connection the controller will also connect if available to an [MQTT broker](#mqtt) for mqtt communication. 

### Dedicated controller

## Protocol

The protocol used for communication between the nodes is based on [esp-now](https://www.espressif.com/en/products/software/esp-now/overview). A low-power communication protocol using the same 2.4 Ghz radio that is used for wifi, but without the need for a central router. The nodes can communicate with eachother peer-to-peer.  
Since the nodes are not connected to the home network, there is no way to access them directly. Therefore the controller connects to the esp-now network, as well as to the home WiFi network and acts as a gateway.  
This way, only one IP address on the home network is needed for the whole esp=now network. For the outside world (everything not in the esp-now network) the network is available as one device.

### Controller selection

When a node is turned on, and there is no controller present (eg, there is no [welcome message](#welcome-message) as a response to the [introduction message](#introduction-message)), this node shall become the controller. This is the most simple and mmost common scenario.

### Controller initialization

### Introduction message

### Welcome message

### Data message

### MQTT


