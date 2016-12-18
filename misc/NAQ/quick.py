def main():
    t = int(raw_input())
    s = raw_input()
    final = ''
    for c in s:
        final += mapp.get(c.lower(), c)
    print final
if __name__ == '__main__':
    main()
