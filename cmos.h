#define from_bcd(val)  ((val / 16) * 10 + (val & 0xf))

unsigned char CMOS[128];

void outportb(unsigned short _port, unsigned char _data) {
	asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

unsigned char inportb(unsigned short _port) {
	unsigned char rv;
	asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

void ReadFromCMOS(void)
{
	unsigned char index;

	for(index = 0; index < 128; index++)
	{
		outportb(0x70, index);

		CMOS[index] = inportb(0x71);
	}
}

void get_date(uint16_t * month, uint16_t * day) {
	ReadFromCMOS();

	*month = from_bcd(CMOS[8]);
	*day   = from_bcd(CMOS[7]);
}
