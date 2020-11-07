# AECS Android App

This is based on [hello-world-debian-android](https://gitlab.com/Matrixcoffee/hello-world-debian-android/).

## Build & Install

Run 'make'. If everything goes well, you will end up with aecsandroidapp.apk' in the root directory of the project, which you can transfer to your phone and install in any way you see fit, for example using `adb install aecsandroidapp.apk`.

Using `anbox`, you can launch the application with

    anbox launch --package=aecs.source.aecsandroidapp --component=aecs.source.aecsandroidapp.AECSAndroidApp
