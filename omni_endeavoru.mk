# Release name
PRODUCT_RELEASE_NAME := endeavoru

# Boot animation
TARGET_SCREEN_HEIGHT := 1280
TARGET_SCREEN_WIDTH := 720
# must be before including omni part
TARGET_BOOTANIMATION_SIZE := 720x480

# Inherit Omni GSM telephony parts
$(call inherit-product, vendor/omni/config/gsm.mk)

# Inherit some common Omni stuff
$(call inherit-product, vendor/omni/config/common.mk)

# Inherit from the common Open Source product configuration
# $(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
# Inherit from the common AOSP product configuration (this will call full_base_telephony)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)

# Inherit device configuration
$(call inherit-product, device/htc/endeavoru/full_endeavoru.mk)


# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := endeavoru
PRODUCT_NAME := omni_endeavoru
PRODUCT_BRAND := htc
PRODUCT_MODEL := One X
PRODUCT_MANUFACTURER := HTC

# Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=endeavoru \
    TARGET_DEVICE=endeavoru \
    BUILD_FINGERPRINT="htc/htc_europe/endeavoru:4.2.2/JDQ39/231174.2:user/release-keys" \
    PRIVATE_BUILD_DESC="4.18.401.2 CL231174 release-keys"
