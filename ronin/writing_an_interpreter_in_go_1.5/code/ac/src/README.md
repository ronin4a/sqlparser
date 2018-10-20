# Description

SQL parser, based on 'Writing A Interpreter in Go'.

This is intended to take a .sql ETL (using GoogleSQL syntax) and parse text into
logic tree. A graph is built, with traversal options, and checks against
breakages in an ETL pipeline.

# Status

pg17
  Need to include support for non-delimiter tokens; need to convert bytes to
strings (e.g. for "SELECT")
