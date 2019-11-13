# PID Box Process
## Our Design 
In order to complete our PID box, we wanted to utilize cardboard in order to make a smooth, friction fit device that we could minimize the size of and make into a slim as possible device. 

## Important Information on Design 
In order to make our box out of cardboard, some adjustments were necessary in the design process. 

We chose to use single thickness rather than double corregated cardboard. When cutting with cardboard, it is important to remember that the laser cutter will burn off some of the material so the CAD files must be adjusted for this by measuring curve (or how much the laser cutter takes off) and adding this value to all of the sides to ensure a tight fit on the final box. We had to keep in mind that the CAD files adjusted with curve will not mate together in a Solidworks assembly very smoothly so extra precautions had to be made so that the lack of an accurate assembly didn't result in mis-measured or mis-fit parts. 

The laser cutter has no "cardboard" setting so after some trial and error we determined that the best stand in setting was to utilize the Natural -> Wood -> Soft Wood -> Balsa setting and measure the thickness of the cardboard to determine the setting. 

To measure curve, a small rectange was laser cut out of our desired cardboard and the length measured (l), next we made another cut down the middle of that rectangle, placed the pieces together and measured the new length(l'). Curve could then be calculated as (l-l'). 

The friction fit design of the box was made using a puzzle-piece esq side and then utilizing the configurations tool to make the other sides.  

# PID Box Planning

We will create a box with a spinning wheel powered by a DC motor, an arduino and potentiometer, monitored with a photointerrupter that will display rotations per minute and correct for error using a proportional-integral-derivative controller. Additionally, we would like to minimize wasted materials and use cardboard rather than acrylic as well as a friction fit design. 

## Schedule
We hope to finish this project by November 15th, our weekly milestones and deadlines may be found on our Google Calendar

__Coding and Wiring Process:__ Spin a wheel >> read a wheel speed >> control wheel speed >> implement PID control of wheel speed >> add LEDs, indicators etc. >> Streamline code and wiring

__Solidworks/CAD:__ Determine curve of cardboard material >> Design box skeleton >> Fricton fit w/ cardboard >> Integrating specific parts/devices >> assemble w/ parts in CAD >> work on actual cardboard etching etc. in order to not look like trash. 

Additionally, we will design/cut a wheel out of acrylic early on in the project so that the code may be fine tuned to the actual goal.

In general, CAD will be up to Frank while coding, wiring and git will be handled by Kit.

## Criteria and Constraints 
We would like to minimize the total size of our box in order to make it more handheld rather than large and bulky. Additonally, we are attempting a box made of cardboard which complicates the design process somewhat as making cardboard not look unattractive will be an obstacle. Cable/wire placement will likewise need to be managed as minimizing total volume of the box will necessitate more organized wires for functionality.

![Design Sketch](https://github.com/ktremag/PID-Box/blob/master/Media/PID_Box.PNG)

## Materials
We expect the necessary materials to be: 
- cardboard for box structure 
- acyrilic wheel
- 3D printed or acrylic breadboard/arduino mount
- battery pack
- arduino uno
- breadboard
- DC motor
- on/off switch
- panel-mounted potentiometer
- LEDs
- LCD screen
- photointerrupter
