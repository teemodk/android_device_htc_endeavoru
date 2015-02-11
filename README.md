cm-12.0 for New Layout
http://review.cyanogenmod.org/#/c/85364/

repo init -u https://github.com/CyanogenMod/android.git -b cm-12.0

.repo/local_manifests/cm_manifest.xml:

<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <project name="TheMuppets/proprietary_vendor_htc"             path="vendor/htc"                remote="github" revision="cm-12.0" />
  <project name="CyanogenMod/android_kernel_htc_endeavoru"      path="kernel/htc/endeavoru"      remote="github" revision="cm-12.0" />
  <project name="teemodk/android_device_htc_endeavoru"          path="device/htc/endeavoru"      remote="github" revision="cm12nl" />
  <project name="teemodk/android_device_htc_tegra3-common"      path="device/htc/tegra3-common"  remote="github" revision="cm12nl" />
</manifest>
