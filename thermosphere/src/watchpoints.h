/*
 * Copyright (c) 2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "breakpoints_watchpoints_common.h"
#include "spinlock.h"

/// Structure to synchronize and keep track of watchpoints
typedef struct WatchpointManager {
    DebugRegisterPair watchpoints[16];
    RecursiveSpinlock lock;
    u32 maxWatchpoints;
    u16 allocationBitmap;
} WatchpointManager;

extern WatchpointManager g_watchpointManager;

void initWatchpoints(void);