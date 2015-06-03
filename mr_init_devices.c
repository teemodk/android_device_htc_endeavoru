#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    "/sys/devices/tegradc.0/graphics/fb0",

    "/sys/block/mmcblk0",
    "/sys/devices/platform/sdhci-tegra.3",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p4",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p14",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p15",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p19",
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/bus/mmc/drivers/mmc_test",
    "/sys/bus/sdio/drivers/wl1271_sdio",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    "/sys/devices/platform/gpio-keys.0/input*",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",

    // for adb
    "/sys/devices/virtual/tty/ptmx",
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p12", // /system
    "/sys/devices/platform/sdhci-tegra.3/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p13", // /cache
    "/sys/devices/virtual/misc/android_adb",
    "/sys/class/android_usb/*",
    "/sys/class/android_usb/android0/*",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/class/android_usb/android0/f_mtp",
    "/sys/class/android_usb/android0/f_adb/*",
    "/sys/class/android_usb/android0/f_mtp/*",
    "/sys/bus/usb",

    // USB drive is in here
    "/sys/devices/platform/tegra-ehci.1*",

    NULL
};