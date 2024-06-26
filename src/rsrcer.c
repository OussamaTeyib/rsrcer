// Convert a resource file into a C array.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Invalid number of arguments!\n");
        fprintf(stderr, "Usage: rsrcer <input_file> <output_file> <array_name>");
        return EXIT_FAILURE;
    } 

    FILE* input = fopen(argv[1], "rb");
    if (!input)
    {
        fprintf(stderr, "ERROR: can't open input file!\n");
        return EXIT_FAILURE;
    }
       
    // get the size of the input file
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    rewind(input);
    
    FILE* output = fopen(argv[2], "w");
    if(!output)
    {
        fprintf(stderr, "ERROR: can't create output file!\n");
        fclose(input);
        return EXIT_FAILURE;
    }   

    unsigned char byte;
    size_t count = 0;
    fprintf(output, "const unsigned char %s[] = {", argv[3]); 
    while (1 == fread(&byte, 1, 1, input))
    {
        fprintf(output, "0x%02X", byte);
        if (count < (size_t) (size - 1)) // '-1' to avoid the last byte
            fprintf(output, ", ");
        count++;
    }
    fprintf(output, "};\n");
    fprintf(output, "const size_t %s_size = %zu;\n", argv[3], count);

    printf("%zu bytes successfully printed!\n", count);
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}