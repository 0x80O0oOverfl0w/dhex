#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "machine_type.h"
#include "menu.h"
#include "output.h"
#include "input.h"
#include "markers.h"

tInt8 gotomask(tOutput* output, tUInt64* cursorpos, tInt64 baseaddr)
{
	tUInt64 actcursorpos=*cursorpos+baseaddr;
	tUInt64 newcursorpos=*cursorpos+baseaddr;
	tInt8	itemnums[25];
	tInt8	selected;
	tMenu	Menu1;
	tInt16	offsx;
	tInt16	offsy;
	tInt8	retval=RETOK;
	char	buf[17];
	int		i;

	offsx=COLS/2-30;
	offsy=LINES/2-10;

	drawcenterframe(output,17,70,"Goto...");
	setcolor(output,COLOR_BRACKETS);
	mvwprintw(output->win,offsy+3,offsx+8,"[                 ]");
	clearMenu(&Menu1);
	newMenuItem(&Menu1,"To",3,1,'T',0,&itemnums[0]);
	newMenuItem(&Menu1,"Go",3,48,'G',0,&itemnums[1]);
	newMenuItem(&Menu1,"Cancel",3,53,'C',1,&itemnums[2]);

	selected=-1;

	while (1)
	{
		setcolor(output,COLOR_FRAME);
		for (i=0;i<58;i++) mvwprintw(output->win,offsy+17,offsx+1+i," ");
		setcolor(output,COLOR_TEXT);
		mvwprintw(output->win,offsy+3,offsx+9,"%17llx",newcursorpos);
		selected=MenuInteract(output,&Menu1,offsy,offsx);

		if (selected==itemnums[0]) {
			newcursorpos=actcursorpos;
			hexinput(output,offsy+3,offsx+8,&newcursorpos,NULL,17);
		}

		if (selected==itemnums[1])
		{
			*cursorpos=newcursorpos-baseaddr;
			return RETOK;
		} //FIXME

		if (selected==itemnums[2])
		{
			return RETNOK;
		}
	}
	return	RETOK;
}

tInt8 gotomaskdiff(tOutput* output, tUInt64* cursorpos1, tUInt64* cursorpos2, tInt64 baseaddr1, tInt64 baseaddr2)
{
	tUInt64 actcursorpos=*cursorpos1+baseaddr1;
	tUInt64 newcursorpos=*cursorpos1+baseaddr1;
	tInt8	itemnums[25];
	tInt8	selected;
	tMenu	Menu1;
	tInt16	offsx;
	tInt16	offsy;
	tInt8	retval=RETOK;
	char	buf[17];
	int		i;

	offsx=COLS/2-30;
	offsy=LINES/2-10;

	drawcenterframe(output,17,70,"Goto...");
	setcolor(output,COLOR_BRACKETS);
	mvwprintw(output->win,offsy+3,offsx+8,"[                 ]");
	clearMenu(&Menu1);
	newMenuItem(&Menu1,"To",3,1,'T',0,&itemnums[0]);
	newMenuItem(&Menu1,"Go",3,48,'G',0,&itemnums[1]);
	newMenuItem(&Menu1,"Cancel",3,53,'C',1,&itemnums[2]);

	selected=-1;

	while (1)
	{
		setcolor(output,COLOR_FRAME);
		for (i=0;i<58;i++) mvwprintw(output->win,offsy+17,offsx+1+i," ");
		setcolor(output,COLOR_TEXT);
		mvwprintw(output->win,offsy+3,offsx+9,"%17llx",newcursorpos);
		selected=MenuInteract(output,&Menu1,offsy,offsx);

		if (selected==itemnums[0]) {
			newcursorpos=actcursorpos;
			hexinput(output,offsy+3,offsx+8,&newcursorpos,NULL,17);
		}

		if (selected==itemnums[1])
		{
			*cursorpos1=newcursorpos-baseaddr1;
			*cursorpos2=newcursorpos-baseaddr2;
			return RETOK;
		} //FIXME

		if (selected==itemnums[2])
		{
			return RETNOK;
		}
	}
	return	RETOK;
}