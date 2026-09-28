## Window

## What is a window?
* In simple words window is just a output screen.
* Through a `Window` we can see rendered world.

## How it works?
* It uses a 2D array to store the current frame.
```cpp
std::array<std::array<char, width>, height> m_frame;
```
* A draw function will draw or insert the entities based on their coordinates.
* The frame or 2d grid is then printed, and cleared also the frame itself is also cleared using std::fill().

## Architecture
* **Template class:** 
* `Window` is a template class, which can accept `std::size_t` only.
* The template is used to pass arguments for the size of the 2d array while declaration.
* As we know, for std::array the memory is allocated during compilation hence using templates we make
a kind of a constructor like work to pass the width and the height of the `Window`.

* **Why std::array over std::vector?**
* As we are aware that for `std::vector` the memory is allocated on heap.
* But in the case of `std::array` the memory is allocated on stack which is ultra fast.
* So as the game grid is big, and constantly needs to be printed hence we use super speed of `std::array` and it being light weight.

* **Problem and fix of using a std::array over a std::vector:**

* **Problem:**
* One of the biggest hurdle is that because `std::array` allocates memory on stack and ie., before runtime we cannot pass the arguments into it during the runtime, neither we get a way to give the `Window` class's `m_frame` size using a constructor of Window class since there must be a placeholder which we cannot keep while declaration of `std::array` inside a class(although we can use some hacks).

* **Solution:**
* To overcome this we used templates.
* We made `Window` a template class in which the template takes two arguments height and width in which both are std::size_t's.

* Implementation:
```cpp
template<std::size_t height, std::size_t width>
class Window {
    //class body
};
```

* In this way when created an object of `Window` we can pass the height and width of our window.

* Object creation:
```cpp
Window<100, 200> win();
```