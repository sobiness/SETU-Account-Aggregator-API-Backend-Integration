#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int binarytodecimal(int num)
{
    int binary_num, decimal_num = 0, base = 1, rem;
    while (num > 0)
    {
        rem = num % 10;
        decimal_num = decimal_num + rem * base;
        num = num / 10;
        base = base * 2;
    }
    return decimal_num;
}
 
int main()
{
    int no_pages, no_frames;
    char logic[100], physic[100];
    int table[100][100];
    printf("Enter no. of Pages: ");
    scanf("%d", &no_pages);
    printf("Enter no. of Frames: ");
    scanf("%d", &no_frames);
    printf("Page Table\n");
    for (int i = 0; i < no_pages; i++)
    {
        printf("Page %d is mapped to frame: ", i);
        scanf("%d", &table[i][0]);
    }
    printf("Enter Logical Address:");
    scanf("%s", logic);
    int page_bit = (int)log2(no_pages);
    int frame_bit = (int)log2(no_frames);
    char logic_bit_adr[page_bit], physic_bit_adr[page_bit];
    memcpy(logic_bit_adr, logic, page_bit);
    logic_bit_adr[page_bit] = '\0';
    const char *offset = &logic[page_bit];
 
    int bit_page = binarytodecimal(atoi(logic_bit_adr));
    int bit_frame = table[bit_page][0];
    printf("%d", bit_frame);
 
    int index = 0;
    while (bit_frame > 0)
    {
        index += sprintf(&physic_bit_adr[index], "%d", bit_frame % 2);
        printf("%d", bit_frame % 2);
        bit_frame = bit_frame / 2;
    }
    while (strlen(physic_bit_adr) != frame_bit)
    {
        strcat(physic_bit_adr, "0");
    }
 
    strcat(strrev(physic_bit_adr), offset);
    printf("\nPhysical Address: %s", physic_bit_adr);
    return 0;
}