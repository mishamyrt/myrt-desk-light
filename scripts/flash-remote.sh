#!/bin/sh

# User defined constants
CONTROLLER_ADDRESS="192.168.31.122"
FIRMWARE_PATH="dist/light_controller.ino.ab"

curl -X POST \
     -H "Content-Type: application/octet-stream" \
     --data-binary "@$FIRMWARE_PATH" 192.168.31.122/lightstrip/update-firmware -v

# # Internal constant
# FIRMWARE_NAME="$(basename $FIRMWARE_PATH)"

# # Action
# echo "Preparing"
# TEMP_DIR="$(ssh $SSH_HOST mktemp -d)"
# REMOTE_FIRMWARE_PATH="$TEMP_DIR/$FIRMWARE_NAME"
# scp "$FIRMWARE_PATH" "$SSH_HOST:$REMOTE_FIRMWARE_PATH"
# ssh $SSH_HOST "
# sudo service light-server stop
# echo 'Flashing firmware'
# arduino-cli upload -t -i $REMOTE_FIRMWARE_PATH -p $DEVICE_PATH -b $FQBN
# echo 'Cleaning up'
# sudo service light-server start
# rm -rf $TEMP_DIR
# echo 'Done ☺️'
# "
