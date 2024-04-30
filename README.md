## rsrcer
rsrcer is a command-line utility that converts a resource file into a C array that can be used in a C source code file.

### Usage:
The program takes three arguments:
```
rsrcer input_file output_file array_name 
```

- `input_file`: the path to the input binary file to be converted. 
- `output_file`: the path to the output C source file to be generated.
- `array_name`: the name of C array to be generated.

Example:
```
rsrcer mydata.bin data.c mydata 
```
This will create a C source file `data.c` that defines a `const unsigned char mydata[]` array containing the bytes of `mydata.bin` file.

### License:
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.