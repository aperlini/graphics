# C Graphics API

Based on [GFX](http://www.nd.edu/~dthain/courses/cse20211/fall2013/gfx) libs to draw basic elements (points, lines, and misc shapes)

By default all elements are drawn relative to the origin, which is positioned in the *top left* corner at coordinate (0,0).  

<img src="img/coordinate_space.svg" alt="coordinate_space" style="zoom:75%;" /> 

The api offers abstractions to translate and position shapes into the euclydian space.

![default](img/default.png) 

## Requirements

GFX depends upon the X11 dev library ([Windowing System](https://en.wikipedia.org/wiki/X_Window_System) used on Unix based machines)

```bash
sudo apt install libx11-dev
```

## todo list

- [x] thickness of a line
- [x] fill shapes
- [ ] add assertion (to stay consistent)
- [ ] error handling
- [ ] foreground and background color abstractions
- [ ] on resize







