# Copyright (c) 2016, Ford Motor Company
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following
# disclaimer in the documentation and/or other materials provided with the
# distribution.
#
# Neither the name of the Ford Motor Company nor the names of its contributors
# may be used to endorse or promote products derived from this software
# without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

include_directories(
  ${GMOCK_INCLUDE_DIRECTORY}
  ${COMPONENTS_DIR}/application_manager/include/application_manager/
  ${COMPONENTS_DIR}/application_manager/include/application_manager/commands/
  ${COMPONENTS_DIR}/application_manager/test/include/
  ${COMPONENTS_DIR}/application_manager/test/include/application_manager/commands/
)

set (SOURCES
  ${AM_SOURCE_DIR}/src/smart_object_keys.cc
  ${AM_SOURCE_DIR}/test/mock_message_helper.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/delete_command_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/add_command_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/perform_interaction_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/change_registration_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/create_interaction_choice_set_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/register_app_interface_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/speak_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/alert_maneuver_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/show_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/alert_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/add_sub_menu_request_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/delete_sub_menu_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/set_media_clock_timer_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/set_global_properties_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/set_app_icon_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/set_display_layout_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/slider_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/scrollable_message_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/perform_audio_pass_thru_test.cc
  ${COMMANDS_TEST_SOURCE_DIR}/mobile/end_audio_pass_thru_request_test.cc
)

set(LIBRARIES
  gmock
  jsoncpp
  Utils
  ApplicationManager
  connectionHandler
  HMI_API
  MOBILE_API
  SmartObjects
)

create_test("mobile_commands_test" "${SOURCES}" "${LIBRARIES}" )
