# Binary to C Array Converter
rsrcer is a small command-line utility that converts a resource file into a C array that can be included in a C source code file.

## Usage
The program takes three arguments:

```
rsrcer input_file output_file array_name 
```

- `input_file`: the path to the input binary file to be converted. 
- `output_file`: the path to the output C source file to be generated.
- `array_name`: the name of the C array to be generated.

### Example usage:

```
binary2c mydata.bin data.c mydata 
```

This will create a C source file `data.c` that defines a `const unsigned char mydata[]` array containing the bytes of the `mydata.bin` file.

## Features
- Converts resources files into C arrays for easy inclusion in C programs.
- Outputs a `const size_t` variable holding the size of the array, for convenience.
- Outputs the C source file with a consistent and readable format.
- Reports errors and usage messages to stderr for convenience.

## Credits
This program was written by **Oussama Teyib**.
