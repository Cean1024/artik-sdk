/*
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 */

#ifndef LWM2M_CPP_ARTIK_LWM2M_HH_
#define LWM2M_CPP_ARTIK_LWM2M_HH_

#include <string.h>
#include <stdlib.h>

#include <artik_module.h>
#include <artik_lwm2m.h>

/*! \file artik_lwm2m.hh
 *
 *  \brief C++ Wrapper to the LWM2M module
 *
 *  This is a class encapsulation of the C
 *  LWM2M module API \ref artik_lwm2m.h
 */

namespace artik {
/*!
 *  \brief Lwm2m sensor C++ Class
 */
class Lwm2m {
 private:
  artik_lwm2m_module* m_module;
  artik_lwm2m_handle m_handle;

 public:
  Lwm2m();
  ~Lwm2m();
  artik_error client_request(artik_lwm2m_config *params);
  artik_error client_release();
  artik_error client_connect();
  artik_error client_disconnect();
  artik_error client_write_resource(const char *uri, unsigned char *buffer,
      int length);
  artik_error client_read_resource(const char *uri, unsigned char *buffer,
      int* length);
  artik_error set_callback(artik_lwm2m_event_t event,
      artik_lwm2m_callback user_callback, void *user_data);
  artik_error unset_callback(artik_lwm2m_event_t event);
  artik_lwm2m_object *create_device_object(const char* manufacturer,
      const char* model, const char* serial, const char* fw_version,
      const char* hw_version, const char *sw_version, const char* device_type,
      int power_source, int power_volt, int power_current, int battery_level,
      int memory_total, int memory_free, const char* time_zone,
      const char *utc_offset, const char* binding);

  artik_lwm2m_object *create_connectivity_monitoring_object(int netbearer,
      int avlnetbearer, int signalstrength, int linkquality, int lenip,
      const char **ipaddr, int lenroute, const char **routeaddr,
      int linkutilization, const char *apn, int cellid, int smnc, int smcc);

  artik_lwm2m_object *create_firmware_object(
    bool supported, char *pkg_name, char *pkg_version);

  void free_object(artik_lwm2m_object* object);
  artik_error serialize_tlv_int(int *data, int size, unsigned char **buffer,
      int *bufferlen);
  artik_error serialize_tlv_string(char **data, int size,
      unsigned char **buffer, int *bufferlen);
};

}  // namespace artik

#endif  // LWM2M_CPP_ARTIK_LWM2M_HH_
