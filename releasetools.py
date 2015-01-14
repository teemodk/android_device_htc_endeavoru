# Copyright (C) 2013 The Android Open Source Project
# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""Custom OTA commands for endeavoru"""

import common
import os
import shutil

#TARGET_DIR = os.getenv('OUT')
#UTILITIES_DIR = os.path.join(TARGET_DIR, 'utilities')

def FullOTA_Assertions(self):
  self.script.AssertSomeBootloader("1.28.0000", "1.31.0000", "1.33.0000",
                                   "1.36.0000", "1.39.0000", "1.72.0000",
                                   "1.73.0000")

def FullOTA_InstallBegin(self):
  # New /cache has 2248704 Kbytes, function expects bytes
  #self.script.CacheFreeSpaceCheck(2*1024**3) # 2GiB

  self.script.AppendExtra('package_extract_file("system/bin/layout-check.sh", "/tmp/layout-check.sh");')
  self.script.AppendExtra('set_perm(0, 0, 0777, "/tmp/layout-check.sh");')
  #self.script.AppendExtra('assert(run_program("/tmp/layout-check.sh") == "0");')
  #self.script.AppendExtra('ifelsegreater_than_int(run_program("/tmp/layout-check.sh"), "0");')
  self.script.AppendExtra('ifelse(run_program("/tmp/layout-check.sh") != "0", abort("abortabort"));')

def FullOTA_InstallEnd(self):
  self.script.AppendExtra('delete("/system/bin/layout-check.sh");')
