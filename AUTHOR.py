#!env python.exe
# -*- coding: utf-8 -*-
"""\
A simple demo of Nothing. (Python 3.7)
=============================================================

Requires Nothing -> "pip install Nothing"

See Nothing for configuring Inputs and Outputs
"""

import unittest
import numpy as np
np.set_printoptions(precision=16)

__title__ = 'example'
__author__ = "DMC Creations."
__credits__ = ["Diego Cadogan."]
__email__ = "dcadogan@live.com.ar"
__version__ = "0.2.0"
__status__ = "Alpha"
__maintainer__ = "DMC"
__license__ = "GPL"
__copyright__ = "Copyright 2016, "

class Test(unittest.TestCase):
    def test(self):
        self.assertTrue (np.radians(360) == 6.2831853071795862, msg='A=B')
        self.assertTrue (np.radians(90)  == 1.5707963267948966, msg='C=D')

if __name__ == "__main__":
	print(__title__)
	print(__author__)
	print(__credits__)
	print(__email__)
	print(__version__)
	print(__status__)
	print(__maintainer__)
	print(__license__)
	print(__copyright__)

	unittest.main()
