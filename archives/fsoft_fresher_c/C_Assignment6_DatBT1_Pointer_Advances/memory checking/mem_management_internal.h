#ifndef _mem_management_internal_h_
#define _mem_management_internal_h_
/**HEADER********************************************************************
* Copyright (c) Freescale Semiconductor, Inc. All rights reserved.
*
* Freescale Semiconductor, Inc.
* Proprietary & Confidential
*
* This source code and the algorithms implemented therein constitute
* confidential information and may comprise trade secrets of Freescale Semiconductor, Inc.
* or its associates, and any use thereof is subject to the terms and
* conditions of the Confidential Disclosure Agreement pursual to which this
* source code was originally received.
*****************************************************************************
* $FileName: mem_management_internal.h$
* $Version : 3.8.1.0$
* $Date    : Sept-12-2011$
*
* Comments: Memory management.
*END************************************************************************/

typedef struct _mem_entry_head_struct {
    //  uint_8 file_name[15];
    const char* file_name;
    int         file_loc;
    uint32_t    requested_size;
    uint32_t    allocated_add;
    bool    is_from_operator;
    // TODO: 64bits signature does not support on IAR
    //uint_64   buf_head_sign;
    uint32_t    buf_head_sign;
} MEM_ENTRY_HEAD, _PTR_ MEM_ENTRY_HEAD_PTR;

typedef struct _mem_entry_tail {
    // TODO: 64bits signature does not support on IAR
    //uint_64 buf_tail_sign;
    uint32_t buf_tail_sign;
} MEM_ENTRY_TAIL, _PTR_ MEM_ENTRY_TAIL_PTR;

#define MEM_MAX_SAVE_BUF_PTR        200
typedef struct _mem_allocation_table_struct {
    uint32_t totalAllocSize;
    uint32_t totalFreedSize;
    uint32_t totalNewSize;
    uint32_t totalDeleteSize;
    MEM_ENTRY_HEAD_PTR buf_ptr[MEM_MAX_SAVE_BUF_PTR];
    uint32_t nextSaveIdx;
// TODO: Fix race-condition with a semaphore */
} MEM_ALLOCATION_TABLE, _PTR_ MEM_ALLOCATION_TABLE_PTR;

extern MEM_ALLOCATION_TABLE g_mem_allocation_table;

#endif //_mem_management_internal_h_

/* EOF */


