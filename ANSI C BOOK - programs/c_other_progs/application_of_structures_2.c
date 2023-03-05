#include<stdio.h>
#include<stdint.h>

//2. Application of structure - USING BITFIELD OPERATORS INSIDE THE STRUCTURE
//we have to take a 32 bit data and split it into multiple useful bits
/* what to do:
32 bits => 4 Bytes
 
=> split into 8 parts
  |-------------------------------|
  | CATEGORY       | No. Of bits  |  
  |-------------------------------|
  | address mode   | (1 bit)      | (left most bit) => base address + 31 bits
  | short address  | (2 bits)     |
  | long address   | (8 bits)     |
  | Sensor value   | (3 bits)     |
  | battery status | (3 bits)     |
  | Payload        |(12 bits)     |
  | status bit     | (1 bit)      |
  | CRC            | (2 bits)     |(right most bit) => base address
  |-------------------------------|
*/

typedef struct 
{
    uint32_t     crc            : 2 ; 
    uint32_t     status         : 1 ;
    uint32_t     payload        : 12 ; //requires 12 bits to store data so we go for 16 bit storage type
    uint32_t     battery        : 3 ;
    uint32_t     sensor         : 3 ;
    uint32_t     long_address   : 8 ;
    uint32_t     short_address  : 2 ;
    uint32_t     address_mode   : 1 ;
} Packet;

int main(void)
{
    Packet p1;
    Packet *pTop1 = &p1;
    uint32_t ip_data;

    printf("Enter the 32 bit long value in HEX:\n");
    scanf("%x", &ip_data);
    printf("Entered data in HEX:%#x\n", ip_data);

    //note: Order of data is very important!
    p1.crc           =  (ip_data >>  0 ) & 0x003;     // 1st 2 bits is required
    p1.status        =  (ip_data >>  2 ) & 0x001;     // next 1 bit
    p1.payload       =  (ip_data >>  3 ) & 0xFFF;     // or we can do this ~(0b1 << 13); we need next 12 bits for payload
    p1.battery       =  (ip_data >> 15 ) & 0x007;     // next 3 bits
    p1.sensor        =  (ip_data >> 18 ) & 0x007;     // next 3 bits
    p1.long_address  =  (ip_data >> 21 ) & 0x0FF;     // next 8 bits
    p1.short_address =  (ip_data >> 29 ) & 0x003;     // next 2 bits
    p1.address_mode  =  (ip_data >> 31 ) & 0x001;     // last bit

    putchar('\n');
    printf("| address mode   | (1 bit)      | = %d\n", pTop1->address_mode    );
    printf("| short address  | (2 bits)     | = %d\n", pTop1->short_address   );
    printf("| long address   | (8 bits)     | = %d\n", pTop1->long_address    );
    printf("| Sensor value   | (3 bits)     | = %d\n", pTop1->sensor          );
    printf("| battery status | (3 bits)     | = %d\n", pTop1->battery         );
    printf("| Payload        |(12 bits)     | = %d\n", pTop1->payload         );
    printf("| status bit     | (1 bit)      | = %d\n", pTop1->status          );
    printf("| CRC            | (2 bits)     | = %d\n", pTop1->crc             );

    printf("\nSize of the structure is: %dB\n",sizeof(p1));
    //we shall get 4B as answer
    return 0;
}