#include<stdio.h>
#include<stdint.h>
// this type of application of Union is also called Bit Extraction using union and structure together
//3. Application of Union - we use a combiantion of both structure and union
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
union Packet
{
    uint32_t Data;
    struct
    {
        uint32_t     crc            : 2 ; 
        uint32_t     status         : 1 ;
        uint32_t     payload        : 12 ; //requires 12 bits to store data so we go for 16 bit storage type
        uint32_t     battery        : 3 ;
        uint32_t     sensor         : 3 ;
        uint32_t     long_address   : 8 ;
        uint32_t     short_address  : 2 ;
        uint32_t     address_mode   : 1 ;
    }PacketField; //as struct is inside of union we can use it like this over here
};

int main(void)
{
    union Packet p1;
    uint32_t ip_data;

    printf("Enter the 32 bit long value in HEX:\n");
    scanf("%x", &ip_data);
    printf("Entered data in HEX:%#x\n", ip_data);

    p1.Data = ip_data; //all those 8-10 lines of data processing in one shot bruh!!!!!!
    //we just have to careful of the endianness thats all!
    putchar('\n');
    printf("| address mode   | (1 bit)      | = %d\n", p1.PacketField.address_mode    );
    printf("| short address  | (2 bits)     | = %d\n", p1.PacketField.short_address   );
    printf("| long address   | (8 bits)     | = %d\n", p1.PacketField.long_address    );
    printf("| Sensor value   | (3 bits)     | = %d\n", p1.PacketField.sensor          );
    printf("| battery status | (3 bits)     | = %d\n", p1.PacketField.battery         );
    printf("| Payload        |(12 bits)     | = %d\n", p1.PacketField.payload         );
    printf("| status bit     | (1 bit)      | = %d\n", p1.PacketField.status          );
    printf("| CRC            | (2 bits)     | = %d\n", p1.PacketField.crc             );

    printf("\nSize of the structure is: %dB\n",sizeof(p1));
    //we shall get 4B as answer
    return 0;
}