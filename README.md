#  Ultrahaptics Max Object::Amplitude Modulation

Source and Xcode module to build a Max object that implements the Amplitude Modulation emitter in Cycling '74s Max7 environment.


## Usage:
1. Add uhptx.mxo from 'externals' folder to Max project folder , or add the 'externals' folder to the Max file path.
2. Set Max to run in 64-bit mode.
3. Ensure Ultrahaptics device is plugged in and powered on.
4. Initialize object in Max using the object name 'uhptx.am'.


## Requirements:
1. Minimum v2.5 of Ultrahaptics SDK
2. Max 7, running at 64-bit
3. Object only works on OSX version. Tested on OSX 10.13.6.

## Building instructions
If choosing to build the xcode project, Max SDK and Ultrahaptics SDK files are not included with this repository. They need to be included into the Framework and Header search paths for Xcode, or copied to the following locations:
1. Place max-includes folder from MAX SDK in c74support/
2. Place 'Headers' and 'Libraries' folder from Ultrahaptics SDK in c74support/uhptx-includes

## Release Notes/Version History:

### v1.1: 1 Feb 2019
1. Now using Ultrahaptics SDK v2.6.

### v1: 19 March 2018
1. Support for 4 emitter points.
2. Update with bangs (occuring atleast 10ms apart).
3. .maxhelp file created.
