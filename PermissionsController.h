/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SYSTEM_NETD_PERMISSIONS_CONTROLLER_H
#define SYSTEM_NETD_PERMISSIONS_CONTROLLER_H

#include "Permission.h"

#include <map>

class PermissionsController {
public:
    Permission getPermissionForUser(unsigned uid) const;
    void setPermissionForUser(Permission permission, unsigned uid);

    Permission getPermissionForNetwork(unsigned netId) const;
    void setPermissionForNetwork(Permission permission, unsigned netId);

    bool isUserPermittedOnNetwork(unsigned uid, unsigned netId) const;

private:
    std::map<unsigned, Permission> mUsers;
    std::map<unsigned, Permission> mNetworks;
};

#endif  // SYSTEM_NETD_PERMISSIONS_CONTROLLER_H
