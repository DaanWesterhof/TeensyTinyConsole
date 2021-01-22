# TeensyTinyConsole
This is a library that can be used for basic graphical interactions on a teensy. 
It allows the drawing of shapes and sprites and has many classes to inherit from to create your own objects. 
<br><br>
**NOTE**: This is currently a work in progress and is nowhere near usable, keep an eye out on the releases for when a first version is available.
In the meanwhile take a look at my fork of [VGA_T4 library](https://github.com/DaanWesterhof/VGA_t4) wich is basicly a redesign of the 
[VGA_T4 library by Jean-MarcHarvengt](https://github.com/Jean-MarcHarvengt/VGA_t4) wich has progressed way more.

<br>
### Future plans for functionalities:
There are a few things i could come up with wich i think would be very nice additons in the future
- pass lambdas or callbacks to objects to execute when a certain condition is met (activated in .update()) (very usefull for game dev)
- supporting difrent screen types (currently only VGA output) like oleds (probably not that hard to implement for now)
- Add support for difrent types of input (is that the responsibility of this library)
- default menu option
