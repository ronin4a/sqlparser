# Description

Please see java implementation for full notes (javaronin; cd atm)

# STATUS

_Currently at_
- filling in Session class; will need to create and fill in Transaction class to
  begin implementing the menu choices
- finished Transaction definition; finish implementation
- incorporate status.h into Makefile

_Notes_
Implementing Display class. For now this will just be a simple text display on
command line.

_High level to-dos_
- VERY IMPORTANT: connecting everything with new, delete, pointers... for
  example, new Session s, then s -> CallFunction() vs. just declaring and using
  s.CallFunction()
- Implement logging in etc. for operators
- Better Destructor processes; study how to free up this memory and destroy the
  instance of the object
- Refresh screen after each choice
- Catch ESC at any time

# QUESTIONS

##  iostream and std

Not sure why atm.h/atm.cc don't need #include <iostream>; possibly because it's
being called from main.cc, which has it?

All the other classes need this if I want to use the std functions.

##  static and const

Research implications.

##  virtual vs private

What does this do? See transaction.h

# FINAL NOTES

_Linking objects together via declaration and implementations_

- #include "atmparts.h" and NOT including Class Display in atm.h works
- NOT including #include "atmparts.h" and including Class Display in atm.h
  works; however, will need #include "atmparts.h" in atm.cc

Why?

atmparts.h contains implementation of Class Display (including constructors).
Declaring Class Display in atm.h means we create it; but it's constructed in the
implementation (atm.cc) when we #include "atmparts.h"

clsas ATM is able to take this and use it. Now all the accesors and mutators,
now that they're defined via #include, can be used in atm.cc. 

Note that these can't be accessed in main program - they can only be accessed in
the ATM class, privately. However, the output can be piped to main through ATM's
own accessors.

# C++ specific notes

- include Makefile
- no graphics (though solution code contains this)

# src
http://www.math-cs.gordon.edu/courses/cs320/ATM_Example/Code.html
