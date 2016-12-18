import math
def main():
    x = int(input())
    y = int(input())
    va = int(input())
    vb = int(input())

    if x * vb == y * va:
        print('0.0')
    else:
        t = (x*va + y*vb) / (va*va+vb*vb)
        xx = x - t*va
        yy = y - t*vb
        print(t,xx,yy)
        print((xx*xx+yy*yy)**0.5)

if __name__ == '__main__':
    main()
