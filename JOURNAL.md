## 2nd July 2026: Wiring and schematics
I began the project by creating a schematic for all the wiring of the components. I decided to use an arduino uno (I know it's outdated and there are better microcontroller boards) as the circuit components are very simple and I already had two availale. I first decided to do this in KiCad however the pin numbering and labelling was confusing me so I switched over to tinker cad as I was using an arduino uno. This made it much easier to create a full schematic. Then I used really basic code to just simply test each component by produing a basic output on the simulation and confirmed the wiring was correct. 

Schematic:

<img width="1588" height="823" alt="image" src="https://github.com/user-attachments/assets/d86090e3-5ab4-4e64-9be5-1a9284c365a5" />

Lapse: https://lapse.hackclub.com/timelapse/tBaE92BHizNh

Time Spent: 00:41

## 2nd July 2026: Building the circuit 
I asssembled the circuit using the arduino uno kit I already had and following my functioning schematic. However after uploading the code to test it, the components did not seem to be working. I could hear  slight clicking sound from the servo but no movement, the motor did not seem to do anything and the LCD was not even turning on so I had no idea whether the LDR was functioning. I double checked the wiring agianst the schematic and couldn't find an issue. I will troubleshoot each component individually later. 

Circuit:

<img width="4032" height="3024" alt="1000019017" src="https://github.com/user-attachments/assets/3d7f4342-e722-4e68-a390-23465f8f1871" />

Lapse: https://lapse.hackclub.com/timelapse/c16ZF1C1VSLh

NOTE: For some reason after 0:06, it stopped taking pictures and is stuck on the same picture, I didn't realise until I finished the circuit. I have a picture of the finished circuit timestamped if that helps

Timestamped photo:

<img width="1883" height="994" alt="image" src="https://github.com/user-attachments/assets/bc760dae-11da-44fe-aeec-33f906c303df" />

Time Spent: 00:36

## 2nd and 3rd July 2026: Designing the model in CAD (Solidworks)
I then moved on to creating the design of the product in Solidworks. I based my design of components I already had for a previous project such as 600mm 2020 aluminium extrusion and 6mm pulley belt and pulleys. 

<img width="967" height="946" alt="image" src="https://github.com/user-attachments/assets/7988cf6c-5bde-45df-8ad2-1b8391de552a" />

2nd July Lapse: https://lapse.hackclub.com/timelapse/DHAjXOzbIMxc     01:42:23

3rd July Lapse: https://lapse.hackclub.com/timelapse/Rks5L6Anx1pu     01:06:49

Time Spent: 02:49


## 4th July 2026: Fixing the circuit
I had a look at the circuit again today and first checked everything against the shcematic. As far as I could tell, everything was wired correctly so I tested it again but no change. I then used my other arduino uno to see if I was usign a faulty uno but neither of them worked. So I decided to rewire everything but test it in little bits instead. I began with the LCD and this time I got it to turn on but it didn't diaply anything. After further inspection, it turned out I forgot to wire RW to gnd. Once I did this it functioned perfectly. Then I moved onto the LDR which worked perfectly as expected. Then I moved onto the servo which worked after a little bit of thinking as it turned out the code had the wrong pin for the servo. Then I tried the motor but I couldn't get it to work. I tried to power it all through 12v but that failed to work too. After a lot of testing it turned out there was some conflict between the servo and the motor due to pin 9 so I changed the motor to connect to pin 6 for pwm and then rewired the l293d to the arduino and this time it worked. 

Lapse: https://lapse.hackclub.com/timelapse/w8Zyqny9Opo1     00:05:00

Lapse: https://lapse.hackclub.com/timelapse/GnqO4-OK7IQY     01:17:00

NOTE: It happened again :( after 8 minutes it stopped taking pictures. I have timestamped videos and pictures throughout the time (attached below) but no continuous video.

<img width="1887" height="1000" alt="image" src="https://github.com/user-attachments/assets/24683faf-1409-4955-8603-46c2b4e3988f" />

<img width="857" height="1174" alt="markup_1000019334" src="https://github.com/user-attachments/assets/3134ea07-4f70-429f-8cd8-f9de4b438944" />

<img width="852" height="970" alt="markup_1000019333" src="https://github.com/user-attachments/assets/8f04e9d0-c597-4716-8446-0e981c7e5b89" />

<img width="869" height="972" alt="markup_1000019332" src="https://github.com/user-attachments/assets/0d07799f-a1a0-4c53-bee5-5836965f8875" />

<img width="1897" height="998" alt="image" src="https://github.com/user-attachments/assets/1bab59d5-9dcc-4b8c-b715-1a51ba20feba" />

<img width="1891" height="997" alt="image" src="https://github.com/user-attachments/assets/1c665162-1e5b-4e1a-8165-100169b87412" />

I spent another half an hour at night that I didn't bother to use lapse for becuase it wasn't working so I have included a timestamped photo below.

<img width="854" height="1188" alt="markup_1000019342" src="https://github.com/user-attachments/assets/8e091b8f-6fe6-4b1b-9160-dc2e8b8444ac" />

Video of working circuit:

https://youtu.be/JYhf91gpHcE

Time Spent: 01:52

## 5th July 2026: Designing the PCB
I designed my PCB so that it could be like a shield and stack on top of the arduino uno. 

<img width="952" height="881" alt="image" src="https://github.com/user-attachments/assets/44ac10e6-feb0-43fe-8fe8-32a3cd7c8000" />

<img width="1100" height="875" alt="image" src="https://github.com/user-attachments/assets/7e98ee64-f4ba-4d33-8afe-41abc57138ef" />

Lapse: https://lapse.hackclub.com/timelapse/jVmM2SpNe8C-

Time Spent: 2:00

## 5th July 2026: Fixing the CAD model
I changed the stand on the right to accomodate the motor and also a PCB and realised that the square hole for the extrusion was too small so resized that. As I was fixing the model, I realised I forgot the V-wheels for the plant pot carriage so will have to redesign that tomorrow :(

<img width="437" height="265" alt="image" src="https://github.com/user-attachments/assets/5861dd04-8386-4b2d-bac4-87881880d554" />

Lapse: https://lapse.hackclub.com/timelapse/tX8e8igjWN-x 

Time Spent: 00:29

## 7th July 2026: Fixing the CAD model
I first added a moisture sensor into the circuit. Then, I had to redesign the entire plant carriage assembly. This means I will have to reassemble the main assembly all over again tomorrow. 

<img width="820" height="499" alt="image" src="https://github.com/user-attachments/assets/7a0281d3-791b-411b-bd1c-f5735f899892" />

<img width="477" height="297" alt="image" src="https://github.com/user-attachments/assets/c27099ea-3b83-48de-9b2c-e8e0b96491d9" />

Lapse: https://lapse.hackclub.com/timelapse/ZRIUK9M7NHi8

Time Spent: 02:06

## 8th July 2026: Adding to circuit and fixing the CAD model
I added another motor to the breadbaord schematic on tinkercad as a placeholder for a DC water pump. I will attempt to avoid buying and having to use the water pump and will attempt my servo method first but I'm keeping the option open. I then increased the height of the stands and fixed the final assembly. 

<img width="1669" height="980" alt="image" src="https://github.com/user-attachments/assets/878217bd-4abd-4a0a-9fa6-7d46a7048a70" />

<img width="1380" height="829" alt="image" src="https://github.com/user-attachments/assets/9b5cb281-7713-4887-9e69-f4c9588de92e" />

Lapse: https://lapse.hackclub.com/timelapse/WA_zX9wjQfdF 

(I added an extra 20mins to the final time becuase I spent some time adding spaces for the nuts for fixing the two halves of the carriage but forgot to record it with Lapse.)

Time Spent: 01:07 

## 9th July 2026: Fixing Kicad Schematic and PCB
I added in the final components to the schematic and realised that the PCB footrpint for the uno was reversed. This meant I had to remake the entire PCB and shematic using a template instead of a footprint. 


Lapse: https://lapse.hackclub.com/timelapse/YqrEKAufjbH9

(Lapse or google or smth crashed halfway through and I didn't realise so I have added 30mins on to final time for the work that was not recorded.)

Time Spent: 01:07 
