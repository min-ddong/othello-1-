import unittest

from hello import *

class Test01_HelloWorld(unittest.TestCase):
    def test_list_int(self):
        """
        Calling the helloworld method should return 'Hello World!'
        """
        result = helloworld()
        self.assertEqual(result, "Hello World!")

class Test02_HelloName(unittest.TestCase):
    def test_list_int(self):
        """
        Calling the helloname method passing the argument 'Steve' should return 'Hello Steve!'
        """
        result = helloname("Steve")
        self.assertEqual(result, "Hello Steve!")

if __name__ == '__main__':
    with open('test.txt', "w") as f:
        runner = unittest.TextTestRunner(f)
        unittest.main(testRunner=runner)
