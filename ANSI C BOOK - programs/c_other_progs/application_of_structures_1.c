#include<stdio.h>
#include<stdint.h>

//1. Application of structure
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

struct Packet
{
    uint8_t     crc; 
    uint8_t     status;
    uint16_t    payload; //requires 12 bits to store data so we go for 16 bit storage type
    uint8_t     battery;
    uint8_t     sensor;
    uint8_t     long_address;
    uint8_t     short_address;
    uint8_t     address_mode;
};
/*struct Packet 
{
    uint8_t     crc; 
    uint8_t     status;
    uint16_t    payload; //requires 12 bits to store data so we go for 16 bit storage type
    uint8_t     battery;
    uint8_t     sensor;
    uint8_t     long_address;
    uint8_t     short_address;
    uint8_t     address_mode;
}__attribute__ ((packed));*/

int main(void)
{
    struct Packet p1;
    struct Packet *pTop1 = &p1;
    uint32_t ip_data;//4b var

    printf("Enter the 32 bit long value in HEX:\n");
    scanf("%x", &ip_data);
    printf("Entered data in HEX:%#x\n", ip_data);

    //note that by the following operation we are NOT updating ip_data! => no changes is done to ip_data after the >> operator!
    p1.crc           =  (uint8_t)(ip_data >>  0 ) & 0x003;     // 1st 2 bits is required
    p1.status        =  (uint8_t)(ip_data >>  2 ) & 0x001;     // next 1 bit
    p1.payload       = (uint16_t)(ip_data >>  3 ) & 0xFFF;     // or we can do this ~(0b1 << 13); we need next 12 bits for payload
    p1.battery       =  (uint8_t)(ip_data >> 15 ) & 0x007;     // next 3 bits
    p1.sensor        =  (uint8_t)(ip_data >> 18 ) & 0x007;     // next 3 bits
    p1.long_address  =  (uint8_t)(ip_data >> 21 ) & 0x0FF;     // next 8 bits
    p1.short_address =  (uint8_t)(ip_data >> 29 ) & 0x003;     // next 2 bits
    p1.address_mode  =  (uint8_t)(ip_data >> 31 ) & 0x001;     // last bit

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

    return 0;
}