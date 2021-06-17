# TeensyTinyConsole
This is a library that can be used for basic graphical interactions on a teensy. 
It allows the drawing of shapes and sprites and has many classes to inherit from to create your own objects. 
<br><br>
**NOTE**: This is currently a work in progress and still lots has to be done, but a few things are working so be sure to check it out!
<br>

### Current functionalities
- initialise game objects on the go
- Pass lambdas to a collection of objects or to an object wich will be executed in .update()
- VGA output

### Planned improvements
- Faster drawing to the canvas for display
- Image parser for easy creation of sprites. (file type to be determined)

### Future plans for functionalities:
There are a few things i could come up with which i think would be very nice additions in the future
- supporting different screen types (currently only VGA output) like oleds (probably not that hard to implement for now)
- Add support for different types of input
- default menu option
- auto scale output (set default canvas size and output on different resolutions)
- default physics?
- Some sort of game AI?
