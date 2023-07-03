# :no_entry_sign: :mouse2: No Click Programming Language
No Click is a modeling programming language which is designed to remove the
annoying gui model building tools. I don't know if I can mention any here but if
you have ever been tired of click-resizing and moving sqaures etc. then no click
might be the model building language for you.

# :factory: Inputs and Outputs
The input to this program should be text files which are representative of a
some 2D model (which I have deemed `.nc` files).  This can be anything which you
can draw on a 2D surface using ellipses, rectangles, points, and lines.
Additionally there is full text support. With these two things in mind, at least
what I use it for is making graphical representations of complex data
structures, representations of subdivisions of tasks, and representations of
other state based phenomena such as DFA's.

There are example programs in the `example_progs/` directory which kind of walks
through why I made this language and its capabilities. Also the examples are all
well commented.

# :hammer: Building
Ensure that you have:
  - libpng
  - bison
  - flex
  - libfreetype

Installed on your system then:
```
mkdir build
cd build
cmake ..
make
```

# :ledger:
The grammar for No Click is as follows:
```
canvas ->
```
