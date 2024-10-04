px4_add_module(
    MODULE custom_plugins__move_land_pad
    MAIN MoveLandPadPlugin
    SRCS
        MoveLandPadPlugin.cpp
    DEPENDS
        # List any dependencies your plugin might have
    )

