package lexer

import (
  "testing"
  "token"
)

//  Test token and lexer; more importantly, test NextToken
func TestDelimiters(t *testing.T) {
  input := `;,()`

  tests := []struct {
    expectedType token.TokenType
    expectedLiteral string
  }{
    {token.SEMICOLON, ";"},
    {token.COMMA, ","},
    {token.LPAREN, "("},
    {token.RPAREN, ")"},
  }

  l := New(input)

  for i, tt := range tests {
    tok := l.NextToken()

    if tok.Type != tt.expectedType {
      t.Fatalf("tests[%d] - tokentpye wrong. expected=%q, got=%q",
        i, tt.expectedType, tok.Type)
    }

    if tok.Literal != tt.expectedLiteral {
      t.Fatalf("tests[%d] - tokentpye wrong. expected=%q, got=%q",
        i, tt.expectedLiteral, tok.Literal)
    }
  }
}

//  Test a basic query
//  Note: In this example, table_name should actually be its own special
//  identifier. This has not been defined as of this point in dev.
func TestBasicQuery(t *testing.T) {
  input := `SELECT id FROM table_name`

  tests := []struct {
    expectedType token.TokenType
    expectedLiteral string
  }{
    {token.SELECT, "SELECT"},
    {token.IDENT, "id"},
    {token.FROM, "FROM"},
    {token.IDENT, "table_name"},
  }

  l := New(input)

  for i, tt := range tests {
    tok := l.NextToken()

    if tok.Type != tt.expectedType {
      t.Fatalf("tests[%d] - tokentpye wrong. expected=%q, got=%q",
        i, tt.expectedType, tok.Type)
    }

    if tok.Literal != tt.expectedLiteral {
      t.Fatalf("tests[%d] - tokentpye wrong. expected=%q, got=%q",
        i, tt.expectedLiteral, tok.Literal)
    }
  }
}
