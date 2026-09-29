## RigidBody

## What is a RigidBody?
* A fixed body that cannot form a curve or bend, and all of it's parts move together is called a RigidBody.

## How it works in this engine?
* It uses an `std::vector` of `Engine::Core::Cell` to store every cell of the body in a contigious manner.
* It can store both 1d and 2d entities, into a 1d vector.
* The origin position of the body is set to the top left `Cell` in the `std::vector`.

## Architecture

## **Why 1d `std::vector` for even a 2d entity?**
* **Problem with 2d vectors:**
* A `std::vector` is a dynamic array that holds elements in a contigious manner.
* A 2D vector is nothing but a vector of vectors, so these rows which are the individual vectors are stored inside a vector. So all these rows or individual vectors belong to different parts of memory and hence your memory is not packed together.
* Even though each elements row there is in a contigous location but those rows are at different locations which spoils this contigous memory adavantage.

* **Solution is a 1d vector:**
* So to solve this caching issues we use a 1d vector in such a way that we can store elements in 2d.
* It is done by flattening the 2d vector.
* Example if we have a 2*2 vector it would look like `[[1, 2], [3,4]]` but after flattening it will look like `[1, 2, 3, 4]`.
* So we store rows in contigous manner, like 1st row will be written first then second row will be written after it, and by using certain formulae we can easily access them using x and y.
* Even though this approach takes more contigous space but it gives us very crucial `Cache Locality`.

* **Cache Locality:**
* It refers to how close the set of memory locations that are closer to each other.
* As we know that whenever we access a memory location the data on that location is loaded into the ultra fast cpu cache lines L1/L2/L3 cpu caches.
* Even along the accessed location it's neighbouring chunk of memory is also loaded.
* So in terms or arrays or vectors the elements are closer to each other which means if we access the 0th element even other locations of 1, 2, 3, 4.... will be inside the these CPU caches. 
* So cache lines being fast we need not to look into RAM again to and search for 3rd element coz it's already inside the CPU caches.
* So in conclusion cache locality gives very fast access with taking 20 times less CPU cycles(According to "The Cherno" as far as I remember).
* This is the reason why arrays and vectors are widely used and is considered as fast.