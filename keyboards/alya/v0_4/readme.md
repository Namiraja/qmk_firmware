# Alya

![alya](https://cyberbedarf.de/img/alyabone.png)

A symmetrical, customisable, compact (60%, 14x5), mechanical keyboard without a big space bar. Enjoy the magic of thumb modifiers.

* Keyboard Maintainer: [Martin Errenst](https://github.com/crazyimp)
* Keyboard Maintainer: [Psycorama](https://github.com/psycorama)
* Little Helper: [Namigator](https://github.com/namiraja)
* Hardware Supported: Alya Matrix v0.4, bluepill
* Hardware Availability: [Alya](https://cyberbedarf.de/home.html)

Still in development and not part of the main/master branch yet. Switch to alya_v4:

    git checkout alya_v4
    
Make example for this keyboard (after [setting up your build environment](https://docs.qmk.fm/#/getting_started_build_tools)):

    qmk compile -kb alya/v0_4 -km default

Flashing example for this keyboard (don't forget to enter the bootloader):

    qmk flash -kb alya/v0_4 -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader:

* **Physical reset button**: Briefly press the button on the Bluepill
* **Keycode in layout**: Press the key mapped to `QK_BOOT`, default is Fn+Esc

## Keymap

Create a new keymap directory:

    qmk new-keymap -kb alya/v0_4 -km <your username>

You can find it in `keyboards/alya/v0_4/keymaps/`. Change it however you want. See the [Keycodes Overview](https://docs.qmk.fm/keycodes) for inspiration. Now flash:

    qmk flash -kb alya/v0_4 -km <your username>

You can set your default keyboard and keymap to skip the `-kb` and `-km`:

    qmk config compile.keyboard=alya/v0_4
    qmk config compile.keymap=<your keymap name>

## TODO
* set `usb.pid`
* setup debug
* implement [backlight](https://docs.qmk.fm/reference_info_json#backlight)
```
    driver = software
    pin = B14
    on_state = 0
    data_pin = B13
    data_clear = B15
    data_clock = B12
```
* implement [swap hands](https://docs.qmk.fm/features/swap_hands)
* expand readme: new-layout
* windows, mac, linux layouts with unicode support
