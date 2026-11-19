# alya

![alya](https://cyberbedarf.de/img/alyabone.png)

A symmetrical, customisable, compact (60%, 14x5), mechanical keyboard without a big space bar. Enjoy the magic of thumb modifiers.

* Keyboard Maintainer: [Martin Errenst](https://github.com/crazyimp)
* Keyboard Maintainer: [Psycorama](https://github.com/psycorama)
* Little Helper: [Namigator](https://github.com/namiraja)
* Hardware Supported: Alya Matrix v0.4, bluepill
* Hardware Availability: [Alya](https://cyberbedarf.de/home.html)

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb alya/v0_4

Flashing example for this keyboard:

    qmk flash -kb alya/v0_4

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## TODO
* set `usb.pid`
* implement [backlight](https://docs.qmk.fm/reference_info_json#backlight)
```
    driver = software
    pin = B14
    on_state = 0
    data_pin = B13
    data_clear = B15
    data_clock = B12
```
* setup debug
* implement [swap hands](https://docs.qmk.fm/features/swap_hands)
