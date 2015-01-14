#!/sbin/sh

# Old: /cache:  mmcblk0p13/CAC
#      /sdcard: mmcblk0p14/ISD
#      /data:   mmcblk0p15/UDA
#
# New: /cache:  mmcblk0p15/UDA
#      /sdcard: emulated
#      /data:   mmcblk0p14/ISD

# TODO: Don't assume that /cache is mounted and /data is not

# Check for new cache partition
mount | grep cache | egrep -q "mmcblk0p15|UDA"
if [ $? != 0 ]; then
    echo "You are running a recovery with the old parition layout. Aborting installation!" >&2
    echo "Please read and understand http://goo.gl/TODO to continue." >&2
    exit 1
fi

# Check if /data can be mounted as ext4
#mount -t ext4 /dev/block/mmcblk0p14 /data &> /dev/null
#if [ $? != 0 ]; then
#    echo "/data could not be mounted as ext4. You may need to format it." >&2
#    echo "!! YOU WILL LOSE ALL DATA ON YOUR SDCARD !!" >&2
#    echo "Please read and understand http://goo.gl/TODO to continue." >&2
#    exit 1
#fi

exit 0
