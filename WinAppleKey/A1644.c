#include "driver.h"

void ProcessA1644Buffer(BYTE* buf, ULONG size)
{
	BYTE* pModifier = &buf[0];
	BYTE* pKey1 = &buf[2];
	BYTE* pKey2 = &buf[3];
	BYTE* pKey3 = &buf[4];
	BYTE* pKey4 = &buf[5];
	BYTE* pKey5 = &buf[6];
	BYTE* pKey6 = &buf[7];
	BYTE* pSpecialKey = &buf[8];

	// Optionally process optional Alt-Cmd swap
	if (*pModifier & HidLCtrlMask)
	{
		*pModifier &= ~HidLCtrlMask;
		*pModifier |= HidLAltMask;
	}

	// Physical Fn pressed?
	if (*pSpecialKey & 0x2)
		*pModifier |= HidLCtrlMask; // Set LCtrl modifier
	else
		*pModifier &= ~HidLCtrlMask; // Clear LCtrl modifier

	// Eject Pressed?
	if (*pSpecialKey & 0x1)
		*pKey1 = HidDel; // Set Del key

	*pSpecialKey = 0; //Clear special key
}