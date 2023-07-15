# SuperCapacitorModule

The goal of this project:<br>
A supercapacitor can provide much-needed current to motors while allowing charge at a much higher rate, making it a *powerful* tool when used in tandem with a battery, or heck, even a secondary power source of its own!

The current implementation of this supercapacitor bank consists of buck-boost converters, which regulate voltage/current during its use. There is also the use of relays along with a teensy as a microcontroller to dynamically control charge and discharge cycles, while voltage sensors (voltage dividing resistors) help monitor any abnormalities in capacitor voltages. Full Arduino code is made available to the public.

PRODUCT FEATURE<br>
Backfeeding protection (Breaker, diodes)<br>
Overvoltage protection (Crowbar circuit)<br>
High voltage charging @~15V (Capacitor stack)<br>
Active cell balancing charging using MOSFET ICs<br>
Buck-Boost capability (DC-DC converters)<br>
Controlled charge and discharge cycles<br>
2002J of potential energy<br>

Full in-depth documentation can be found here: (Still in the works!)
https://docs.google.com/document/d/10xSz2Brdb20Teefaufs0sfIVZrpAqIFKbtMyl3yj6dg/edit?usp=sharing
----------------------------------------------------------------------------------------------------------------------------
// Finished Product:
![20230701_121806](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/fa862643-8782-47ef-bae6-c61205d48aff)
![20230701_121816](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/4fd571d0-e7e2-4d0e-8658-125104aad7ae)
![IMG_8250](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/08c42539-9d2f-4b72-a1b8-7b9c879009cd)

// Assembly Images:
PCB Bottom Layer
![image](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/b0ee9331-4d2f-4899-9f22-27eb8e8b4206)
PCB Top 3D Model
![image](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/578b8858-64b1-492e-9f33-f50864065238)
PCB Bottom 3D Model
![image](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/73bf29f8-10e2-407b-9bc0-5f6eec09f08c)
PCB Schematic
![image](https://github.com/christopherho5/SuperCapacitorModule/assets/128961461/6fcefa11-c09e-4357-ab81-0fc192823e7c)





