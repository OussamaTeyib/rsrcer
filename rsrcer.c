// convert a resource file into a C source file arry.

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: input_file output_file array_name");
        return -1;
    } 

    FILE* input = fopen(argv[1], "rb");
    if (!input)
    {
        fprintf(stderr, "ERROR: cannot open the file!\n");
        return -1;
    }
       
    // get the size of the input file
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    rewind(input);
    
    FILE* output = fopen(argv[2], "w");
    if(!output)
    {
        fprintf(stderr, "ERROR: cannot create a file!\n");
        fclose(input);
        return -1;
    }   

    unsigned char byte;
    int count = 0;
    fprintf(output, "unsigned char %s[] = {", argv[3]); 
    while (1 == fread(&byte, 1, 1, input))
    {
        count++;
        fprintf(output, "0x%02X", byte);
        if (count < size)
            fprintf(output, ", ");
    }
    fprintf(output, "};\n");
    
    printf("%d bytes successfully printed!\n", count);
    fclose(input);
    fclose(output);
    return 0;
}