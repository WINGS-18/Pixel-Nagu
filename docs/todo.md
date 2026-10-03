## Collision of SoftBodies

* So my current collision check only works for RigidBody -> RigidBody or RigidBody -> SoftBody but no SoftBody -> SoftBody -> SoftBody.
* To detect collision between two softbodies we use a approach called Bend Segments Intersect(i call it that way).
* Keep trach of bend points or vertices of the soft body into a vector of bends.
* Now as it bends from there it'll be always a straight line untill we get the next bend.
* Hence that segment can be treated as a rigidbody and apply  global bounds and use intersect functions to detect the collision.