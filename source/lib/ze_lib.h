/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_lib.h
 *
 */
#pragma once
#include "ze_api.h"
#include "ze_ddi.h"
#include "zet_api.h"
#include "zet_ddi.h"
#include "zes_api.h"
#include "zes_ddi.h"
#include "layers/zel_tracing_api.h"
#include "layers/zel_tracing_ddi.h"
#include "ze_util.h"
#include <vector>
#include <mutex>

namespace ze_lib
{
    ///////////////////////////////////////////////////////////////////////////////
    class context_t
    {
    public:
#ifdef DYNAMIC_LOAD_LOADER
        HMODULE loader = nullptr;
#endif

        context_t();
        ~context_t();

        std::once_flag initOnce;

        ze_result_t Init();

        ze_result_t zeInit();
        ze_dditable_t   zeDdiTable = {};

        ze_result_t zetInit();
        zet_dditable_t  zetDdiTable = {};

        ze_result_t zesInit();
        zes_dditable_t  zesDdiTable = {};

        ze_result_t zelTracingInit();
        zel_tracing_dditable_t  zelTracingDdiTable = {};
    };

    extern context_t *context;

} // namespace ze_lib
