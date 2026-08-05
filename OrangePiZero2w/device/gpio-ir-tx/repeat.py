#!/usr/bin/env python3

# Example program to receive infrared signals, display their contents, and resend the same signals.
# source https://github.com/IndoorCorgi/cgir.git

import time
import cgir

# Create an instance of the infrared transmission/reception and data analysis class
ir = cgir.Infrared()

while True:
    # Receiving operation
    print("Please send infrared signals towards the receiver...")
    
    # Receive infrared signals and put the result in ret, and the received content in code.
    # Specify the timeout in seconds. None means no timeout.
    ret, code = ir.record(timeout=10)
    
    if (ret == cgir.REC_NO_DATA):
      # If reception failed
      print("Timeout. Infrared signal could not be received.")
      exit()
    
    elif (ret == cgir.REC_SHORT):
      # If the received waveform is extremely short
      # Possible reception of noise or a repeat code
      print("Received, but it may be noise.")
      exit()
    
    elif (ret == cgir.REC_SUCCESS):
      # Reception successful. The `code` variable contains a list of Mark (38kHz pulse transmission) and Space (waiting) times recorded in microseconds.
      print("Reception successful")
    
    # Display the contents of the code
    print("Code: ")
    print(code)
    
    ir.codes=code
    ir.codes_path= input("Введите ваше кнопки для названия файла: ")+".json"
    ir.save_codes()
    print(f" save code to {ir.codes_path}")
    
    # The received code is an infrared waveform, and the actual data is unknown, so decode it to obtain the infrared format and data.
    # Refer to infrared.py for the data format
    format, frames = ir.decode(code)
    
    if (format == cgir.FORMAT_AEHA):
      print("Format: AEHA")
      print("Data: ")
      print(frames)
    elif (format == cgir.FORMAT_NEC):
      print("Format: NEC")
      print("Data: ")
      print(frames)
    elif (format == cgir.FORMAT_SONY):
      print("Format: SONY")
      print("Data: ")
      print(frames)
    elif (format == cgir.FORMAT_UNKNOWN):
      print("Format: Unknown")
    
    # In this example, the same code as the received code is sent.
    # The encode method can also be used to convert the data you want to send into a code before sending it.
    print("Sending the same infrared signal as received...")
    time.sleep(1) # Wait 1 seconds
    ir.send(code)
    print("Transmission complete")
    
