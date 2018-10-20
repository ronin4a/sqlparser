# Description

SQL parser, based on 'Writing A Interpreter in Go'.

This is intended to take a .sql ETL (using GoogleSQL syntax) and parse text into
logic tree. A graph is built, with traversal options, and checks against
breakages in an ETL pipeline.

# Status

go test lexer

Test: pg17


# TODO

Generally - will need to parse all terms; currently just hitting keywords that
will feed into data lineage.

Also need to put together LEFT JOIN, LEFT OUTER JOIN, etc. into one token,
rather than separate tokens.

## Lexer
- process numeric characters are part of an IDENT
- process MATERIALIZE with filename paths; i.e. '...' should convert to a
  filename; capacitor/columnio should be stored separately

## Logic processing
Design objects for logical processing and relationships retrieval.

E.g.
CREATE OR REPLACE table1 AS

SELECT * FROM table2;

In this case, table1 and table2 should be connected somehow. table1 is created
off table2.

## Geneneral test cases

(1) Fields:

SELECT a.\*
FROM table1 a
INNER JOIN table2 AS b

(2) MATERIALIZE and storing filepaths as its own token:

MATERIALIZE '/filepath/' AS

(3) DEFINE PERMANENT and storing filepaths:

DEFINE PERMANENT TABLE myTable '/filepath/';
