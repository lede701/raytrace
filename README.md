# Ray Trace Engine

Ray tracing is a fun way to learn a little more about math and how it interacts with our world.  This version of the ray trace engine is based on a book I'm reading but will a few simple modifications from my game engine designs.

This version of the code is multi threaded because I'm impatient and can't wait five minutes or longer for a render.

![alt_text](https://github.com/lede701/raytrace/blob/master/raytraced.png?raw=true)

## Why?

I like learning different things about programming and 3D which for years, and I mean 20 years or more, I've been fascinated by the images that get produced by a good ray trace engine!  Just look at what Pixar does with RenderMan.  I've also been a hobbyist 3D modeler and thought what fun writing a ray tracer could be.

## Fun Stuff

Currently the engine will randomly create a scene with 34 defined balls.  There is one really large one that acts as the ground / floor / horizon.  Surface materials currently consist of the following:

1. Lambertian - A solid color.
2. Metal - A very reflective surface which also has a fuzzy value so the ray tracer will know if there needs to be some blurring on the reflection.
3. Dielectric - Very simple glass that has a random change to either refract a ray or reflect it.

As I progress more into the ray tracer book series hopefully more textures will be available.

### Multi-threading

Since this is a feature of the engine I wanted to give some background to how it was attained.  Currently the only thread support is for windows based computers.  I'm using the function _beginthreadex which is in the windows.h definition file.  I do plan on migrating this to a different thread system when time permits so that it will work on Linux or Mac OSX but this isn't a priority for me at this time.

## The World

Currently it is a mixed bag of class that make up the world.  I'm working on creating a scene object which will manage the render world and help process out rays.  The basic class for the world will be made up of Entities from the Entity class.  The original idea was to have a base class for all hitable objects.  This didn't make sense to me so I've been working slowly at replacing this code for the Entity design instead.

### Proposed world Design

1. Create a Scene class to manages all world entities.  This will replace the HitList class and will have methods for adding, removing, and animating entities.
2. Entity class.  Currently this class has replaced the Hitable class and now supports key frames.
3. EntityKey - This class manages the different transformations of the entity class that can happen over time.

# Code

Currently this code is written in Visual Studio 2017.  If you can get this code to work in other compilers I would like to hear from you and the steps you took to make it work.

### main.cpp

The main.cpp file contains some basic code and some settings for the image rendering process.  The settings some be self explanatory but if you need help understanding something please feel free to ask.

### Imager.cpp

This is the main render class.  In future versions this class will be renamed to something more fitting to what it does.  When the render process is complete it will dump all the colors to a text file using the Mac OSX PPM file format.  There are several GREAT web sites I've used to display the image for Windows computers.  In future designs this process will be abstracted and the data array will be sent to a file IO class that will handle those details.

This class is where all the multi-threading takes place.  It uses a mutex to manage locking og the vector queue so we don't trample on extracting data from the queue since it isn't multi-threaded friendly.  Next all color data is stored in an array for later rendering an image.  There are also some data members that are used for tracking how much of the rendering is complete.  These allow for the system to write out a . when a mile marker has been reached.

There is also a parameter to control the number of threads to launch.  By default I've set this to 2 since most modern computers today have at least this many processors.  You can change this value in the main.cpp file after the class has been insrtantiated.

Important rendering parameters:

1. x - The x offset to start rendering.  This can be used if you only want to render a portion of the scene / world.
2. y - The y offset to start rendering.  Same as the x offset.
3. passes - How many samples for each [x,y] pixel to process.  The render engine uses a random amoun that then averages the color for that pixel.  This is also called Anti-aliasing.
4. width - Width of the image in pixels
5. height - Height of the image in pixels

This should be enough to get the basic idea of how the render system works.  Play with the code, have fun with it and if you do something amazing please share it with me.

## Sorry

Yes the code is a mess right now but I needed a place to start organizing it as I go through the books.  As time and my understanding of what is happening increases I will provide comments.

## Code License

For now this code is freely to use in anything you want.  Just don't ask me to support your use of this code.  If you find bugs please report them here so I can address these issues.
