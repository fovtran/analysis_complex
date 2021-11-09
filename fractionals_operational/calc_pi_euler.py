#! /usr/local/bin/python3.6
"""
Computation of Pi with Euler's formula
"""
import math
import sys
import time
import traceback

class CalcPiEuler:
    L     = 10000  # Digits of computation
    FNAME = "pi_eular.txt"

    def __init__(self):
        self.l1 = int(self.L / 8) + 1
        n = int(self.L / math.log10(7)) + 1
        self.n = int(n / 2) + 1

    def compute(self):
        """ Computation of Pi """
        try:
            t0 = time.time()
            s = [0 for _ in range(self.l1 + 2)]
            a = [0 for _ in range(self.l1 + 2)]
            b = [0 for _ in range(self.l1 + 2)]
            q = [0 for _ in range(self.l1 + 2)]
            a[0] = 20 *  7
            b[0] =  8 * 79
            b = self.__long_div(b, 3)
            for k in range(1, self.n + 1):
                a = self.__long_div(a,    7 *  7)
                b = self.__long_mul(b,    3 *  3)
                b = self.__long_div(b,   79 * 79)
                q = self.__long_add(a,         b)
                q = self.__long_div(q, 2 * k - 1)
                if k % 2 == 0:
                    s = self.__long_sub(s, q)
                else:
                    s = self.__long_add(s, q)
            t1 = time.time()
            tt = t1 - t0
            self.__display(tt, s)
        except Exception as e:
            raise

    def __long_add(self, a, b):
        """ Computation of long + long

        :param  list a
        :param  list b
        :return list z
        """
        try:
            z = [0 for _ in range(self.l1 + 2)]
            cr = 0
            for i in reversed(range(self.l1 + 2)):
                z[i] = a[i] + b[i] + cr
                if z[i] < 100000000:
                    cr = 0
                else:
                    z[i] -= 100000000
                    cr = 1
            return z
        except Exception as e:
            raise

    def __long_sub(self, a, b):
        """ Computation of long - long

        :param  list a
        :param  list b
        :return list z
        """
        try:
            z = [0 for _ in range(self.l1 + 2)]
            br = 0
            for i in reversed(range(self.l1 + 2)):
                z[i] = a[i] - b[i] - br
                if z[i] >= 0:
                    br = 0
                else:
                    z[i] += 100000000
                    br = 1
            return z
        except Exception as e:
            raise

    def __long_mul(self, a, b):
        """ Computation of long * short

        :param  list a
        :param  list b
        :return list z
        """
        try:
            z = [0 for _ in range(self.l1 + 2)]
            cr = 0
            for i in reversed(range(self.l1 + 2)):
                w = a[i]
                z[i] = (w * b + cr) % 100000000
                cr = int((w * b + cr) / 100000000)
            return z
        except Exception as e:
            raise

    def __long_div(self, a, b):
        """ Computation of long / short

        :param  list a
        :param  list b
        :return list z
        """
        try:
            z = [0 for _ in range(self.l1 + 2)]
            r = 0
            for i in range(self.l1 + 2):
                w = a[i]
                z[i] = int((w + r) / b)
                r = ((w + r) % b) * 100000000
            return z
        except Exception as e:
            raise

    def __display(self, tt, s):
        """ Display

        :param float tt
        :param list   s
        """
        try:
            print("** Pi Computation with the Eular formula method **")
            print("   Digits = {:d}.".format(self.L))
            print("   Time   = {:f} seconds".format(tt))
            out_file = open(self.FNAME, "w")
            out_file.write("** Pi Computation with the Eular formula method **\n")
            out_file.write("   Digits = {:d}.\n".format(self.L))
            out_file.write("   Time   = {:f} seconds.\n\n".format(tt))
            out_file.write("          {:d}.\n".format(s[0]))
            for i in range(1, self.l1):
                if i % 10 == 1:
                    out_file.write("{:08d}:".format((i - 1) * 8 + 1))
                out_file.write(" {:08d}".format(s[i]))
                if i % 10 == 0:
                    out_file.write("\n")
            out_file.close
        except Exception as e:
            raise


if __name__ == '__main__':
    try:
        obj = CalcPiEuler()
        obj.compute()
    except Exception as e:
        traceback.print_exc()
        sys.exit(1)
