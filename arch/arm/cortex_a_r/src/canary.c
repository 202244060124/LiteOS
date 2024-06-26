/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: Aach32 Canary
 * Author: Huawei LiteOS Team
 * Create: 2020-01-01
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --------------------------------------------------------------------------- */

#include "arch/canary.h"
#include "arch/regs.h"
#include "stdlib.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#ifdef __GNUC__
/* stack protector */
UINTPTR __stack_chk_guard = 0x000a0dff;

#ifdef LOSCFG_ARCH_CORTEX_A7
STATIC UINT64 ArchGetTimerCnt(VOID)
{
    UINT64 cntpct;
    cntpct = ARM_SYSREG64_READ(CP15_REG64(c14, 0));
    return cntpct;
}
#endif

/*
 * If the SP compiling options:-fstack-protector-strong or -fstack-protector-all is enabled,
 * We recommend to implement true random number generator function for __stack_chk_guard
 * value to replace the function implementation template shown as below.
 */
#pragma GCC push_options
#pragma GCC optimize("-fno-stack-protector")
LITE_OS_SEC_TEXT_INIT WEAK VOID ArchStackGuardInit(VOID)
{
#ifdef LOSCFG_ARCH_CORTEX_A7
    int rnd;
    UINT64 seed;

    seed = ArchGetTimerCnt();
    srand((unsigned int)seed);
    rnd = rand();
    __stack_chk_guard = (UINTPTR)rnd;
#endif
}
#pragma GCC pop_options
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
