# Ray Trace Engine

Ray tracihng is a fun way to learn a little more about math and how it interacts with our world.  This version of the ray trace engine is based on a book I'm reading but will a few simple modifications from my game engine designs.

This version of the code is multithreaded because I'm impatient and can't wait five minutes or longer for a render.

![alt_text](https://github.com/lede701/raytrace/blob/master/raytraced.png?raw=true)

##Why?

I like learning different things about programming and 3D which for years, and I mean 20 years or more, I've been facinated by the images that get produced by a good ray trace engine!  Just look at what Pixar does with RenderMan.  I've also been a hobbiest 3D modeler and thought what fun writing a ray tracer could be.

## Fun Stuff

Currently the engine will randomly create a scene with 34 defined balls.  There is one really large one that acts as the ground / floor / horizon.  Surface materials currently consist of the following:

1. Lambertian - A solid color.
2. Metal - A very reflective surface which also has a fuzzy value so the ray tracer will know if there needs to be some blurring on the reflection.
3. Dielectric - Very simple glass that has a random change to either refract a ray or reflect it.

As I progress more into the ray tracer book series hopefully more textures will be available.

### Multithreading

Since this is a feature of the engine I wanted to give some background to how it was attained.  Currently the only thread support is for windows based computers.  I'm using the function _beginthreadex which is in the windows.h definition file.  I do plan on migrating this to a different thread system when time permits so that it will work on Linux or Mac OSX but this isn't a priority for me at this time.

### Main.cpp

The main.cpp file contains some basic code and some settings for the image rendering process.  The settings some be self explanitory but if you need help understading something please feel free to ask.

## The World

Currently it is a mixed bag of class that make up the world.  I'm working on creating a scene object which will manage the render world and help process out rays.  The basic class for the world will be made up of Entities from the Entity class.

## Sorry

Yes the code is a mess right now but I needed a place to start orginizing it as I go through the books.  As time and my understadning of what is happening increases I will provide comments.

## Code Licesne

For now this code is freely to use in anything you want.  Just don't ask me to support your use of this code.  If you find bugs please report them here so I can address these issues.
