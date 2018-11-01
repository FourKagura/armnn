//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ClBackend.hpp"
#include "ClBackendId.hpp"
#include "ClWorkloadFactory.hpp"

#include <backendsCommon/BackendRegistry.hpp>
#include <boost/log/trivial.hpp>

namespace armnn
{

namespace
{

static StaticRegistryInitializer<BackendRegistry> g_RegisterHelper
{
    BackendRegistryInstance(),
    ClBackend::GetIdStatic(),
    [](const EmptyInitializer&)
    {
        return IBackendInternalUniquePtr(new ClBackend);
    }
};

} // anonymous namespace

const BackendId& ClBackend::GetIdStatic()
{
    static const BackendId s_Id{ClBackendId()};
    return s_Id;
}

IBackendInternal::IWorkloadFactoryPtr ClBackend::CreateWorkloadFactory() const
{
    return std::make_unique<ClWorkloadFactory>();
}

} // namespace armnn