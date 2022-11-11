import unittest


class LexerTestCase(unittest.TestCase):
    def makeLexer(self, text):
        from spi import Lexer
        lexer = Lexer(text)
        return lexer

    def test_tokens(self):
        from spi import (
            INTEGER, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, ID, ASSIGN,
        SEMI, MOD, LBRACE, RBRACE,DOUBLE,STRING,BOOL,LBRACKET, RBRACKET
        )
        records = (
            ('234', INTEGER, 234),
            ('3.14', DOUBLE, 3.14),
            ('*', MUL, '*'),
            ('%', MOD, '%'),
            ('/', DIV, '/'),
            ('+', PLUS, '+'),
            ('-', MINUS, '-'),
            ('(', LPAREN, '('),
            (')', RPAREN, ')'),
            ('=', ASSIGN, '='),
            ('name', STRING, "name"),
            ('True',BOOL, True),
            ('number', ID, 'number'),
            (';', SEMI, ';'),
            ('LBRACE', LBRACE, 'LBRACE'),
            ('RBRACE', RBRACE, 'RBRACE'),
            ('LBRACKET', LBRACKET, 'LBRACKET'),
            ('RBRACKET', RBRACKET, 'RBRACKET'),
        )
        for text, tok_type, tok_val in records:
            lexer = self.makeLexer(text)
            token = lexer.get_next_token()
            self.assertEqual(token.type, tok_type)
            self.assertEqual(token.value, tok_val)


class InterpreterTestCase(unittest.TestCase):
    def makeInterpreter(self, text):
        from spi import Lexer, Parser, Interpreter
        lexer = Lexer(text)
        parser = Parser(lexer)
        interpreter = Interpreter(parser)
        return interpreter

    def test_integer_arithmetic_expressions(self):
        for expr, result in (
            ('3', 3),
            ('2 + 7 * 4', 30),
            ('7 - 8 / 4', 5),
            ('14 + 2 * 3 - 6 / 2', 17),
            ('7 + 3 * (10 / (12 / (3 + 1) - 1))', 22),
            ('7 + 3 * (10 / (12 / (3 + 1) - 1)) / (2 + 3) - 5 - 3 + (8)', 10),
            ('7 + (((3 + 2)))', 12),
            
            ('5 + 3', 8),
            ('5+(3 + 4)+2', 14),
        ):
            interpreter = self.makeInterpreter(
                """MAIN (){
                    INTEGER A = %s ;
                     } """ % expr
                
            )
            interpreter.interpret()
            globals = interpreter.GLOBAL_SCOPE
            self.assertEqual(globals['a'], result)

    def test_float_arithmetic_expressions(self):
        for expr, result in (
            ('3.14', 3.14),
        ):
            interpreter = self.makeInterpreter(
                """MAIN (){
                  
                       DOUBLE a = %s;
                   
                     }
                  
                """ % expr
            )
            interpreter.interpret()
            globals = interpreter.GLOBAL_SCOPE
            self.assertEqual(globals['a'], result)

    def test_expression_invalid_syntax_01(self):
        interpreter = self.makeInterpreter(
            """
            PROGRAM Test;
            BEGIN
               a = 10 * ;  {Invalid syntax}
            END.
            """
        )
        with self.assertRaises(Exception):
            interpreter.interpret()

    def test_expression_invalid_syntax_02(self):
        interpreter = self.makeInterpreter(
            """
            PROGRAM Test;
            BEGIN
               a = 1 (1 + 2); {Invalid syntax}
            END.
            """
        )
        with self.assertRaises(Exception):
            interpreter.interpret()

    def test_program(self):
        text = """\
MAIN (){  // part 10
   INTEGER number;
   INTEGER a, b, c, x;
   DOUBLE y;


      number = 2;
      a = number;
      b = 10 * a + 10 * number / 4;
      c = a - b;
  
   x = 11;
   y = 20 / 7 + 3.14;

 }
 // part 10
"""
        interpreter = self.makeInterpreter(text)
        interpreter.interpret()

        globals = interpreter.GLOBAL_SCOPE
        self.assertEqual(len(globals.keys()), 6)
        self.assertEqual(globals['number'], 2)
        self.assertEqual(globals['a'], 2)
        self.assertEqual(globals['b'], 25)
        self.assertEqual(globals['c'], -23)
        self.assertEqual(globals['x'], 11)
        self.assertAlmostEqual(globals['y'], float(20) / 7 + 3.14)  # 5.9971...


if __name__ == '__main__':
    unittest.main()