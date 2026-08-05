#!/usr/bin/env python3


import time
import cgir

ir = cgir.Infrared()

code = ir.encode(cgir.FORMAT_NEC, [b'\xd0\x91\xd0\xb0',b'\xd0\xb9\xd1\x82\xd1\x8b'])

ir.send(code)

time.sleep(3) 

code = ir.encode(cgir.FORMAT_NEC, [b'\xd1\x82\xd1\x8b'])

ir.send(code)
