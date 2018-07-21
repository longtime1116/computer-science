#include <stdio.h>

#define BLOCK_SIZE (512)

int main (int argc, char *argv[])
{
    int ret = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile.raw\n");
        return 1;
    }

    FILE *outptr = NULL;
    char *infname = argv[1];
    FILE *inptr = fopen(infname, "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", infname);
        ret = 2;
        goto END;
    }

    unsigned char buff[512];
    int jpeg_count = 0;
    while (1)
    {
        int read_len = fread(buff, 1, BLOCK_SIZE, inptr);
        char *outfname = NULL;

        // started with JPEG header?
        if (read_len >= 4 &&
            buff[0] == 0xff &&
            buff[1] == 0xd8 &&
            buff[2] == 0xff &&
            (buff[3] & 0xf0) == 0xe0)
        {
            // close the JPEG written
            if (outptr != NULL)
            {
                fclose(outptr);
                outptr = NULL;
            }

            if (jpeg_count > 999)
            {
                fprintf(stderr, "Too many jpeg files are output\n");
                ret = 3;
                goto END;
            }
            // TODO: use sprintf and change name dynamically
            outfname = "hoge.jpg";

            // open a file for next JPEG
            if ((outptr = fopen(outfname, "wb")) == NULL)
            {
                fprintf(stderr, "Could not open %s\n", outfname);
                ret = 2;
                goto END;
            }
        }

        // continue until find the first JPEG header
        if (outptr == NULL)
        {
            continue;
        }

        if (fwrite(buff, 1, read_len, outptr) != read_len)
        {
            fprintf(stderr, "Fail to write: %s\n", outfname);
            ret = 2;
            goto END;
        }

        if (read_len != BLOCK_SIZE)
        {
            // close the last JPEG
            fclose(outptr);
            outptr = NULL;
            break;
        }
    }

END:
    if (inptr != NULL)
    {
        fclose(inptr);
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    return ret;
}
