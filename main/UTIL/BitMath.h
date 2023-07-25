
#define SetBit(Reg,Pin)		Reg	|=	 (1<<Pin)
#define ClearBit(Reg,Pin)	Reg	&=	~(1<<Pin)
#define ToggleBit(Reg,Pin)	Reg ^=	 (1<<Pin)
#define ReadBit(Reg,Pin)  ((Reg >>	 Pin)&1)
