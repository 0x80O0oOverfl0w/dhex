#ifndef MARKERS_H
#define	MARKERS_H
#include "machine_type.h"
#include "output.h"
#include "datatypes.h"

tInt8 gotomask(tOutput* output, tUInt64* cursorpos, tInt64 baseaddr);
tInt8 gotomaskdiff(tOutput* output, tUInt64* cursorpos1, tUInt64* cursorpos2, tInt64 baseaddr1, tInt64 baseaddr2);

#endif