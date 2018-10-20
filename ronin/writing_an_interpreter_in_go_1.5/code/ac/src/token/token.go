package token

import (
  "strings"
)

type TokenType string

type Token struct {
  Type TokenType
  Literal string
}

const (
  ILLEGAL = "ILLEGAL"
  EOF = "EOF"

  IDENT = "IDENT"

  AS = "AS"
  OR = "OR"
  STAR = "*"

  // Delimiters
  COMMA = ","
  SEMICOLON = ";"

  LPAREN = "("
  RPAREN = ")"

  // Query keywords
  SELECT = "SELECT"
  FROM = "FROM"

  // Join keywords
  JOIN = "JOIN"

  INNER = "INNER"

  LEFT = "LEFT"
  RIGHT = "RIGHT"
  OUTER = "OUTER"

  FULL = "FULL"

  ON = "ON"

  // Table creation keywords
  CREATE = "CREATE"
  REPLACE = "REPLACE"
  TABLE = "TABLE"

  MATERIALIZE = "MATERIALIZE"

  DEFINE = "DEFINE"
  PERMANENT = "PERMANENT"

  // #TODO Future keywords
  GRANT = "GRANT"

  IF = "IF"
  CASE = "CASE"
  WHEN = "WHEN"
  THEN = "THEN"
)

var keywords = map[string]TokenType {
  "select": SELECT,
  "from": FROM,

  "as": AS,
  "or": OR,
  "*": STAR,

  "create": CREATE,
  "replace": REPLACE,
  "table": TABLE,

  "join": JOIN,
  "left": LEFT,
  "right": RIGHT,
  "inner": INNER,
  "full": FULL,
  "outer": OUTER,
  "on": ON,

  "materialize": MATERIALIZE,
  "define": DEFINE,
  "permanent": PERMANENT,
}

// Check identifier to see if it's a pre-defined token
func LookupIdent(ident string) TokenType {
  ident_lower := strings.ToLower(ident)
  if tok, ok := keywords[ident_lower]; ok {
    return tok
  }
  return IDENT
}
