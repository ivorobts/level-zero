/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */
#pragma once
#include <vector>

#include "ze_ddi.h"
#include "zet_ddi.h"
#include "zes_ddi.h"

#include "ze_util.h"
#include "ze_object.h"

#include "ze_ldrddi.h"
#include "zet_ldrddi.h"
#include "zes_ldrddi.h"

namespace loader
{
    //////////////////////////////////////////////////////////////////////////
    struct driver_t
    {
        HMODULE handle = NULL;

        dditable_t dditable = {};
    };

    using driver_vector_t = std::vector< driver_t >;

    ///////////////////////////////////////////////////////////////////////////////
    class context_t
    {
    public:
        ze_api_version_t version = ZE_API_VERSION_1_1;

        driver_vector_t drivers;

        HMODULE validationLayer = nullptr;
        HMODULE tracingLayer = nullptr;

        bool forceIntercept = false;

        ze_result_t init();
        ~context_t();
    };

    extern context_t *context;
    extern ze_event_factory_t ze_event_factory;

}
