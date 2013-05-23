/**
 * @file CAlwaysFalseSchemaItem.cpp
 * @brief CAlwaysFalseSchemaItem source file.
 */
// Copyright (c) 2013, Ford Motor Company
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following
// disclaimer in the documentation and/or other materials provided with the
// distribution.
//
// Neither the name of the Ford Motor Company nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 'A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include "SmartObjects/CAlwaysFalseSchemaItem.hpp"
#include "SmartObjects/CObjectSchemaItem.hpp"
#include "SmartObjects/CSmartObject.hpp"

NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember::SMember(void):
mSchemaItem(NsSmartDeviceLink::NsSmartObjects::CAlwaysFalseSchemaItem::create()),
mIsMandatory(true)
{
}

NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember::SMember(const utils::SharedPtr<NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::ISchemaItem> & SchemaItem,
                                                               const bool IsMandatory):
mSchemaItem(SchemaItem),
mIsMandatory(IsMandatory)
{
}

utils::SharedPtr<NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem> NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::create(const std::map<std::string, NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember> & Members)
{
    return new NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem(Members);
}

NsSmartDeviceLink::NsSmartObjects::Errors::eType NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::validate(const NsSmartDeviceLink::NsSmartObjects::CSmartObject & Object)
{
    NsSmartDeviceLink::NsSmartObjects::Errors::eType result = NsSmartDeviceLink::NsSmartObjects::Errors::ERROR;

    if (NsSmartDeviceLink::NsSmartObjects::SmartType_Map == Object.getType())
    {
        result = NsSmartDeviceLink::NsSmartObjects::Errors::OK;
        const std::set<std::string> objectKeys = Object.enumerate();

        for (std::map<std::string, NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember>::const_iterator i = mMembers.begin(); i != mMembers.end(); ++i)
        {
            if (objectKeys.end() != objectKeys.find(i->first))
            {
                result = i->second.mSchemaItem->validate(Object.getElement(i->first));
            }
            else
            {
                if (true == i->second.mIsMandatory)
                {
                    result = NsSmartDeviceLink::NsSmartObjects::Errors::MISSING_MANDATORY_PARAMETER;
                }
            }

            if (NsSmartDeviceLink::NsSmartObjects::Errors::OK != result)
            {
                break;
            }
        }

        if (NsSmartDeviceLink::NsSmartObjects::Errors::OK == result)
        {
            for (std::set<std::string>::const_iterator k = objectKeys.begin(); k != objectKeys.end(); ++k)
            {
                if (mMembers.end() == mMembers.find(*k))
                {
                    result = NsSmartDeviceLink::NsSmartObjects::Errors::UNEXPECTED_PARAMETER;
                    break;
                }
            }
        }
    }
    else
    {
        result = NsSmartDeviceLink::NsSmartObjects::Errors::INVALID_VALUE;
    }

    return result;
}

void NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::applySchema(NsSmartDeviceLink::NsSmartObjects::CSmartObject & Object)
{
    if (NsSmartDeviceLink::NsSmartObjects::SmartType_Map == Object.getType())
    {
        for (std::map<std::string, NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember>::const_iterator i = mMembers.begin(); i != mMembers.end(); ++i)
        {
            if (true == Object.keyExists(i->first))
            {
                i->second.mSchemaItem->applySchema(Object[i->first]);
            }
        }
    }
}

void NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::unapplySchema(NsSmartDeviceLink::NsSmartObjects::CSmartObject & Object)
{
    if (NsSmartDeviceLink::NsSmartObjects::SmartType_Map == Object.getType())
    {
        for (std::map<std::string, NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember>::const_iterator i = mMembers.begin(); i != mMembers.end(); ++i)
        {
            if (true == Object.keyExists(i->first))
            {
                i->second.mSchemaItem->unapplySchema(Object[i->first]);
            }
        }
    }
}

void NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::BuildObjectBySchema(
    NsSmartDeviceLink::NsSmartObjects::CSmartObject& object) const {
  for (std::map<std::string,
      NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember>::
          const_iterator i = mMembers.begin();
      i != mMembers.end(); ++i) {
    
        i->second.mSchemaItem->BuildObjectBySchema(object[i->first]);
      }
}

NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::CObjectSchemaItem(const std::map<std::string, NsSmartDeviceLink::NsSmartObjects::CObjectSchemaItem::SMember> & Members):
mMembers(Members)
{
}
