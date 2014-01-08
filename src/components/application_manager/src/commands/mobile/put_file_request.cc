/*

 Copyright (c) 2013, Ford Motor Company
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following
 disclaimer in the documentation and/or other materials provided with the
 distribution.

 Neither the name of the Ford Motor Company nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#include "application_manager/commands/mobile/put_file_request.h"
#include "application_manager/application_manager_impl.h"
#include "application_manager/application_impl.h"
#include "config_profile/profile.h"
#include "utils/file_system.h"

namespace application_manager {

namespace commands {

PutFileRequest::PutFileRequest(const MessageSharedPtr& message)
    : CommandRequestImpl(message) {
}

PutFileRequest::~PutFileRequest() {
}

void PutFileRequest::Run() {
  LOG4CXX_INFO(logger_, "PutFileRequest::Run");

  Application* application = ApplicationManagerImpl::instance()->application(
      connection_key());

  if (!application) {
    LOG4CXX_ERROR(logger_, "Application is not registered");
    SendResponse(false, mobile_apis::Result::APPLICATION_NOT_REGISTERED);
    return;
  }

  if (mobile_api::HMILevel::HMI_NONE == application->hmi_level() &&
      profile::Profile::instance()->put_file_in_none() <=
      application->put_file_in_none_count()) {
      // If application is in the HMI_NONE level the quantity of allowed
      // PutFile request is limited by the configuration profile
      LOG4CXX_ERROR(logger_,
                    "Too many requests from the app with HMILevel HMI_NONE ");
      SendResponse(false, mobile_apis::Result::REJECTED);
  }

  if (!(*message_)[strings::params].keyExists(strings::binary_data)) {
    LOG4CXX_ERROR(logger_, "Binary data empty");
    SendResponse(false, mobile_apis::Result::INVALID_DATA);
    return;
  }

  const std::string& sync_file_name =
      (*message_)[strings::msg_params][strings::sync_file_name].asString();

  const std::vector<uint8_t> file_data =
      (*message_)[strings::params][strings::binary_data].asBinary();

  std::string relative_file_path =
      file_system::CreateDirectory(application->name());
  relative_file_path += "/";
  relative_file_path += sync_file_name;

  mobile_apis::Result::eType save_result =
      ApplicationManagerImpl::instance()->SaveBinary(
          application->name(),
          file_data,
          relative_file_path);

  switch (save_result) {
    case mobile_apis::Result::SUCCESS: {
      bool is_persistent_file = false;

      if ((*message_)[strings::msg_params].
          keyExists(strings::persistent_file)) {

        is_persistent_file =
            (*message_)[strings::msg_params][strings::persistent_file].asBool();
      }

      application->AddFile(sync_file_name, is_persistent_file);
      application->increment_put_file_in_none_count();
      SendResponse(true, save_result);
      break;
    }
    default:
      SendResponse(false, save_result);
      break;
  }
}

}  // namespace commands

}  // namespace application_manager
