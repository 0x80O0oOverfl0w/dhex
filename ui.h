#ifndef UI_H
#define	UI_H
#include "machine_type.h"
#include "buffers.h"
#include "search.h"
#include "output.h"
#include "correlation.h"
void searchmask(tOutput* output,tSearch* search,tBuffer* buf,tUInt64* cursorpos);
void searchmaskdiff(tOutput* output,tSearch* search, tBuffer* buf1, tBuffer* buf2, tUInt64* cursorpos1, tUInt64* cursorpos2);
tInt8 savedialog(tOutput* output,tBuffer* buf);
tInt8 correlationmask(tOutput* output,tCorrelation* correlation);
#endif
