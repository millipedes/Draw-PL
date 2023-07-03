# :no_entry_sign: :mouse2: No Click Programming Language
No Click is a modeling programming language which is designed to remove the
annoying gui model building tools. I don't know if I can mention any here but if
you have ever been tired of click-resizing and moving sqaures etc. then no click
might be the model building language for you.

# :factory: Inputs and Outputs
A text file (which I have deemed `.nc` files) which is consistent with the
grammar below.

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
