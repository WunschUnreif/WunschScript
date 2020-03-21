# -*- coding: utf-8 -*-
"""
    pygments.lexers.ws
    ~~~~~~~~~~~~~~~~~~

    Custom lexer for WunschScript.
"""
import re

from pygments.lexer import RegexLexer, include, bygroups, default, words, using, this
from pygments.token import Token, Text, Comment, Operator, Keyword, Name, String, \
    Number, Punctuation, Error


__all__ = ['WSLexer']

class WSLexer(RegexLexer):
    name = 'WunschScript'
    aliases = ['ws', 'wunsch']
    filenames = ['*.ws']

    IDENTIFIER = r'(\b[_a-zA-Z][_a-zA-Z0-9]*\b)'

    tokens = {
        'root': [
            (r'#.*$', Comment.Single),
            (r'[ \n\t]', Text),
            (r'\b(if|else|while|for|in|return)\b', Keyword),
            (r'\b(true|false|nil)\b', Name.Builtin),
            (r'0[oO][0-7]+', Number.Oct),
            (r'0[xX][0-9a-fA-F]+', Number.Hex),
            (r'[0-9]+', Number.Integer),
            (r'(\.\d+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)?', Number.Float),

            (r'\"([^\"\\]|(\\.))*?\"', String),

            (r'\{', Punctuation, '#push'),
            (r'\}', Punctuation, '#pop'),

            (
                r'([_a-zA-Z][_a-zA-Z0-9]*)'
                r'(\s*:)'
                r'(\s*[^;,]*)',
                bygroups(Name.Constant, Punctuation, using(this))
            ),

            (
                r'(\.\s*)'
                r'([_a-zA-Z][_a-zA-Z0-9]*)',
                bygroups(Punctuation, Name.Constant)
            ),

            (
                r'(var)'
                r'(\s*[_a-zA-Z][_a-zA-Z0-9]*)'
                r'(\s*=)',
                bygroups(Keyword.Type, Name.Variable, Punctuation)
            ),

            (
                r'([_a-zA-Z][_a-zA-Z0-9]*)'
                r'(\s*\([^;]*?\))',
                bygroups(Name.Function, using(this))
            ),

            (   #function def with body, with capture
                r'(\s*\([^;]*?\))'  #arg names
                r'(\s*\[[^;]*?\])'  #capture
                r'(\s*=>)'
                r'(\s*\{)',
                bygroups(using(this), using(this), Punctuation, Punctuation),
                'funcdef'
            ),
            (   #function def with body, no capture
                r'(\s*\([^;]*?\))'  #arg names
                r'(\s*=>)'
                r'(\s*\{)',
                bygroups(using(this), Punctuation, Punctuation),
                'funcdef'
            ),
            
            (   #function def with no body, with capture
                r'(\s*\([^;]*?\))'  #arg names
                r'(\s*\[[^;]*?\])'  #capture
                r'(\s*=>)',
                bygroups(using(this), using(this), Punctuation)
            ),
            (   #function def with no body, no capture
                r'(\s*\([^;]*?\))'  #arg names
                r'(\s*=>)',
                bygroups(using(this), Punctuation)
            ),


            (r'[~!%^&+=|<>/\*-]', Operator),
            (r'[;\(\)\[\]\},]', Punctuation),
            (IDENTIFIER, Name.Other),

            (r'.', Text)
        ],
        'funcdef' : [
            include('root'),
            (r'\{', Punctuation, '#push'),
            (r'\}', Punctuation, '#pop')
        ]
    }
