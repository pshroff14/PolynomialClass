class Polynomial():

    def __init__(self, sequence=0):
        self.sequence = sequence
        print(sequence)

    # implement a constructor....
    def __con__(self, poly=[0]):
        self.poly = poly
        print(poly)

        # print(self.sequence)
        a = self.sequence
        x = 0

        # just for show
        # for i in range(a):
        #     print(array[i], 'x^', a - i, "  ", sep='', end='')

    # implement multiplication of polynomials using *
    def __mul__(self, a=[], b=[]):
        c = [0]
        if len(a) > len(b):
            for i in range(len(a) + 1):
                c.append(0)

        elif len(a) < len(b):
            for i in range(len(b) + 1):
                c.append(0)

        else:
            for i in range(len(a) + 1):
                c.append(0)

        for i in range(len(a)):
            for j in range(len(b)):
                c[i + j] = c[i + j] + a[i] * b[j]
        return c

    def __equl__(self, a=[], b=[]):

        if len(a) > len(b):
            return False

        elif len(a) < len(b):
            return False

        else:
            #Stuck Here
            for i in range(len(a)):
                if a[i] == b[i]:
                    continue
                else:
                    return False


    def __eval__(self, x=0):
        poly = self.poly
        # print(x)
        # print(self.poly)
        y = len(self.poly)
        evalpoly = []

        for i in range(len(poly)):
            rise = y - i
            alpha = poly[i] * pow(x, rise)
            evalpoly.append(alpha)

        return evalpoly


print(__name__)


def main():
    "write your test code here"
    print('hi')
    pass


if __name__ == "__main__":
    main()
    p = Polynomial([5, 4])
