# Modified DYMO M10
Goal of this repo is to show how to modify the DYMO M10 scale so it does not switch off by itself.
By default, it switches off after 3 minutes of no actions. To prevent this, a button (eg. the units selector) can be pressed.
This repo shows how to add a simple microcontroller to goggle the units button twince per minute to prevent power off.

## Teardown
You will need to open the scale. Follow the great tutorial at https://learn.adafruit.com/data-logging-iot-weight-scale/assembly to do so. Note that my scale needed an additional step to **remove the front faceplate from the scale**:
You will need to lift the glued on front lable to access 2twio additional screws:

