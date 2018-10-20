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
  input := `SELECT id FROM ronin.table_name;`

  tests := []struct {
    expectedType token.TokenType
    expectedLiteral string
  }{
    {token.SELECT, "SELECT"},
    {token.IDENT, "id"},
    {token.FROM, "FROM"},
    {token.IDENT, "ronin.table_name"},
    {token.SEMICOLON, ";"},
  }

  l := New(input)

  for i, tt := range tests {
    tok := l.NextToken()

    if tok.Type != tt.expectedType {
      t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
        i, tt.expectedType, tok.Type)
    }

    if tok.Literal != tt.expectedLiteral {
      t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
        i, tt.expectedLiteral, tok.Literal)
    }
  }
}

//  Test create/replace table creation
func TestCreateOrReplaceTable(t *testing.T) {
  input := `
  CREATE OR REPLACE TABLE ronin.new_table AS
  (
    SELECT
      *
    FROM 
      ronin.sample_table
  );
  `

  tests := []struct {
    expectedType token.TokenType
    expectedLiteral string
  }{
    {token.CREATE, "CREATE"},
    {token.OR, "OR"},
    {token.REPLACE, "REPLACE"},
    {token.TABLE, "TABLE"},
    {token.IDENT, "ronin.new_table"},
    {token.AS, "AS"},
    {token.LPAREN, "("},
    {token.SELECT, "SELECT"},
    {token.STAR, "*"},
    {token.FROM, "FROM"},
    {token.IDENT, "ronin.sample_table"},
    {token.RPAREN, ")"},
    {token.SEMICOLON, ";"},
  }

  l := New(input)

  for i, tt := range tests {
    tok := l.NextToken()

    if tok.Type != tt.expectedType {
      t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
        i, tt.expectedType, tok.Type)
    }

    if tok.Literal != tt.expectedLiteral {
      t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
        i, tt.expectedLiteral, tok.Literal)
    }
  }
}

//  Test joins
//  Note: this is not correct SQL syntax; however, for the purpose of initial
//  prototype, we're mainly interested in identifying the table IDENTs and the
//  CREATE/REPLACE table IDENT; testing ON and correct SQL syntax will occur
//  later
func TestJoins(t *testing.T) {
  input := `
  CREATE OR REPLACE TABLE ronin.joined_tables AS
  (
    SELECT
      *
    FROM 
      ronin.original_table AS a
    LEFT JOIN
      ronin.left_join_this b
    RIGHT JOIN
      ronin.right_join_this c
    FULL OUTER JOIN
      ronin.outer_join_this AS d
    INNER JOIN
      ronin.inner_join_this e
  );
  `

  tests := []struct {
    expectedType token.TokenType
    expectedLiteral string
  }{
    {token.CREATE, "CREATE"},
    {token.OR, "OR"},
    {token.REPLACE, "REPLACE"},
    {token.TABLE, "TABLE"},
    {token.IDENT, "ronin.joined_tables"},
    {token.AS, "AS"},
    {token.LPAREN, "("},
    {token.SELECT, "SELECT"},
    {token.STAR, "*"},
    {token.FROM, "FROM"},
    {token.IDENT, "ronin.original_table"},
    {token.AS, "AS"},
    {token.IDENT, "a"},
    {token.LEFT, "LEFT"},
    {token.JOIN, "JOIN"},
    {token.IDENT, "ronin.left_join_this"},
    {token.IDENT, "b"},
    {token.RIGHT, "RIGHT"},
    {token.JOIN, "JOIN"},
    {token.IDENT, "ronin.right_join_this"},
    {token.IDENT, "c"},
    {token.FULL, "FULL"},
    {token.OUTER, "OUTER"},
    {token.JOIN, "JOIN"},
    {token.IDENT, "ronin.outer_join_this"},
    {token.AS, "AS"},
    {token.IDENT, "d"},
    {token.INNER, "INNER"},
    {token.JOIN, "JOIN"},
    {token.IDENT, "ronin.inner_join_this"},
    {token.IDENT, "e"},
    {token.RPAREN, ")"},
    {token.SEMICOLON, ";"},
  }

  l := New(input)

  for i, tt := range tests {
    tok := l.NextToken()

    if tok.Type != tt.expectedType {
      t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
        i, tt.expectedType, tok.Type)
    }

    if tok.Literal != tt.expectedLiteral {
      t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
        i, tt.expectedLiteral, tok.Literal)
    }
  }
}
