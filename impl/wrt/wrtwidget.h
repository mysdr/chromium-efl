/*
   Copyright (C) 2014 Samsung Electronics

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef WRTWIDGET_H
#define WRTWIDGET_H

#include <string>
#include "url/gurl.h"
#include "v8/include/v8.h"
#include "public/ewk_ipc_message.h"

class WrtWidget {
 public:
  WrtWidget();

  void SetWidgetInfo(int widgetHandle,
                     double scaleFactor,
                     const std::string& encodedBundle,
                     const std::string& theme);

  void messageReceived(const Ewk_IPC_Wrt_Message_Data& data);

  void ParseUrl(const GURL& url, GURL& new_url);

  void StartSession(v8::Handle<v8::Context>,
                    int routingHandle);

  void StopSession(v8::Handle<v8::Context>);

 private:
  int widgetHandle_;
  double scale_;
  std::string theme_;
  std::string encodedBundle_;
};

#endif // WRTWIDGET_H