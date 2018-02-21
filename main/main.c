#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#if 1
//bool getSpnAndFmi(unsigned long &spnAndFmi)
//{
//	double dval, dtemp;
//	unsigned long spn(0), fmi(0);
//
//	// Gets value from Fault code input
//	// Why add 0.005 though?
//	dtemp = dval = pConDouble->getValue() + 0.005;
//
//	// Invalid faultcode if <= 0.006 or > 16777215
//	if (dval <= 0.006 || dval > 0xFFFFFF)
//		return false;
//
//	spn = (unsigned long)(floor(dtemp));				// 100.01 -> 100
//	fmi = (unsigned long)((dval - floor(dtemp)) * 100);	// 100.01 -> 1
//
//	// This implementation moves the fmi code to start from the 16th bit
//	//  and the SPN code to start from the 0th bit
//	// However it only leaves room for the SPN code to be no more than 0xFFFF (65535)
//	// Shifting by 20 instead of 16 will instead give a max value of 0xFFFFF (1048575) 
//	//  which is enough for the high SPN values at 500k
//	// Shifting by 24 will give a max value of 0xFFFFFF (16777215)
//	//  which was the value that was checked earlier
//	spnAndFmi = (fmi | ((spn >> 11) & 0xFF)) << 16;
//
//	// This will then need to be adjusted depending on the shift number
//	// 0xFFFFF for 20 or 0xFFFFFF for 24
//	spnAndFmi |= spn & 0xFFFF;
//
//	//CM_xyprintf(1,6,"spnfmi high->low %06lx",spnAndFmi);
//	return true;
//}

char *decimal_to_binary(unsigned long n)
{
	int c, d, count;
	char *pointer;

	count = 0;
	pointer = (char*)malloc(32 + 1);

	if (pointer == NULL)
		exit(EXIT_FAILURE);

	for (c = 31; c >= 0; c--)
	{
		d = n >> c;

		if (d & 1)
			*(pointer + count) = 1 + '0';
		else
			*(pointer + count) = 0 + '0';

		count++;
	}
	*(pointer + count) = '\0';

	return  pointer;
}

void printHex(const char* str, unsigned long hex)
{
	printf(" %s: 0x%08lx (%s) (%d)\n", str, hex, decimal_to_binary(hex), hex);
	
}

int main()
{
	unsigned long spnAndFmi;

	double conDouble = 523232.31;

	printf("FaultCode Input: %lf\n", conDouble);

	double dval, dtemp;
	unsigned long spn = 0;
	unsigned long fmi = 0;

	dtemp = dval = conDouble + 0.005;

	if (dval <= 0.006 || dval > 0xFFFFFF)
		return 0;

	printf(" dtemp: %lf\n", dtemp);
	printf(" floor(dtemp): %lf\n", floor(dtemp));
	printf(" dval: %lf\n\n", dval);
	spn = (unsigned long)(floor(dtemp));
	fmi = (unsigned long)((dval - floor(dtemp)) * 100);

	printf("Translated Fault Code:\n");
	printHex("SPN", spn);
	printHex("FMI", fmi);
	printf("\n");

	printf("Conversion steps:\n");
	
	long spn1 = (spn >> 11);
	printHex("spn1 = spn  >> 11           ", spn1);
									    
	long spn2 = spn1 & 0xF0;					    
	printHex("spn2 = spn1 &  0xF0         ", spn2);
									    
	long fmi1 = fmi | spn2;		    
	printHex("fmi1 = fmi  |  spn2         ", fmi1);
									    
	spnAndFmi = fmi1 << 16;			    
	printHex("spnAndFmi = fmi1 << 16      ", spnAndFmi);
	
	spnAndFmi |= spn & 0xFFFF;
	printHex("spnAndFmi |= spn & 0xFFFF   ", spnAndFmi);
	
	_getch();
}

#endif

#if 0

int main()
{
	int a = 30009, b = 3973;
	char c = 35;
	int *p;
	p = (int*)&c;


//3973 - 3864 = 109

}

#endif

#if 0
/*
Antag att följande deklaration har gjorts
int i = 1 6 3 ;
Vilket värde antar i efter följande tilldelningsats:
i = i << 5 ;
Ange svaret som ett decimalt tal.
*/
int main()
{
	int i = 231;
	printf("%d\n", i);
	i = i << 6;
	printf("%d\n", i);
	_getch();
}
#endif

#if 0
/*
Om följande deklaration gäller
#define RXC 6
vad beräknas då följande till
(1 << RXC)
Ange svaret som ett decimalt tal.
*/
#define RXC 4
int main()
{
	int i = (1 << RXC);
	printf("%d", i);
	_getch();
}
#endif

#if 0
/*
I ett C-program nns följande kodfragment:
long x ;
unsigned char b ;
x = 0x8ECEE1C1 ;
b =  ( ( ( unsigned char ) &x )+1) ;
Vilket värde får variabeln b? Antag att little-endian lagring av data. Svaret ges i
hexadecimala talsystemet.
*/
int main()
{
	long x;
	unsigned char b;

	x = 0x8ECEE1C1;
//x = 0xB98DC3F8;
	b = *((unsigned char *)&x + 1);

	printf("%x", b);

	_getch();
}
#endif

#if 0
/*
Antag att följande pekardeklaration gäller:
long p=0X01D4 ;
Vilken adress i minnet accessas vid följande operation:
(p+11)
Antag att int är på 2 bytes, long och float på 4 bytes och double på 8 bytes. Svara
med det hexadecimala värdet med fyra siffror.

long = 4 bytes
11*4 = 44(10)
44(10) = 2C(16)
0x01D4 + 0x002C = 0x0200
*/
int main()
{
	float f = 10.5;
	float *p = &f;
	printf("*p = %p\n", &*p);
	
	*p = *(p + 11);
	printf("*(p + 11)=");
	printf("%p", &*(p+11));

	_getch();
}

#endif

