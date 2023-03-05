#include <stdio.h>
#include<stdint.h>
#pragma pack (2)

typedef struct DataSet
{
	char        data1;
	int         data2;
	char        data3;
	short int   data4;
} DataSet;

int main(void)
{
	DataSet data;
	data.data1 = 0x11;
	data.data2 = 0xffffeeee;
	data.data3 = 0x22;
	data.data4 = 0xabcd;

	printf("Memory Address:\t\tAddress\n");
	for(register int i = 0; i<20;printf("="), ++i);
	printf("\n");

	uint8_t *ptr = (uint8_t *)&data;

	for(register int i = 0; i < sizeof(data); ++i)
	{
		printf("%p\t\t%X\n", ptr,*ptr);
		ptr++;
	}
	printf("End of stt\nTotal size of structure data is : %d\n",sizeof(data));

	//indefinite loop
}