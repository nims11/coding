mapp = {
'a': r'@',
'b': r'8',
'c': r'(',
'd': r'|)',
'e': r'3',
'f': r'#',
'g': r'6',
'h': r'[-]',
'i': r'|',
'j': r'_|',
'k': r'|<',
'l': r'1',
'm': r'[]\/[]',
'n': r'[]\[]',
'o': r'0',
'p': r'|D',
'q': r'(,)',
'r': r'|Z',
's': r'$',
't': r"']['",
'u': r'|_|',
'v': r'\/',
'w': r'\/\/',
'x': r'}{',
'y': r'`/',
'z': r'2',
    }

def main():
    s = raw_input()
    final = ''
    for c in s:
        final += mapp.get(c.lower(), c)
    print final
if __name__ == '__main__':
    main()
