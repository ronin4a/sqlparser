package token

type TokenType string

type Token struct {
  Type TokenType
  Literal string
}

const (
  ILLEGAL = "ILLEGAL"
  EOF = "EOF"

  IDENT = "IDENT"

  // Delimiters
  COMMA = ","
  SEMICOLON = ";"
  
  LPAREN = "("
  RPAREN = ")"
  
  // Crtical keywords
  SELECT = "SELECT"
  FROM = "FROM"

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
  "create": CREATE,
  "replace": REPLACE,
  "table": TABLE,
  "materialize": MATERIALIZE,
  "define": DEFINE,
  "permanent": PERMANENT,
}

// Check identifier to see if it's a pre-defined token
func LookupIdent(ident string) TokenType {
  if tok, ok := keywords[ident]; ok {
    return tok
  }
  return IDENT
}
