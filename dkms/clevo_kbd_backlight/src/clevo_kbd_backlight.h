// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Clevo Keyboard Backlight Driver for Linux
@file clevo_kbd_backlight.h
@version 2020.05.25
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


#ifndef _CLEVO_KBD_BACKLIGHT_H
#define _CLEVO_KBD_BACKLIGHT_H


/* MODULE MACROS */


#define DEVICE_NAME   "CLEVO Keyboard"
#define DRIVER_NAME   "clevo_kbd_backlight"
#define pr_fmt(fmt)   DRIVER_NAME ": " fmt
#define BUF_SIZE   16

#include <linux/list.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/acpi.h>
#include <acpi/button.h>
#include <linux/dmi.h>
#include <linux/input.h>


/** Test if the given string is empty/NULL */
#define isempty(ptr)   (!(ptr) || !*(ptr))


#define __CLEVO_PR(lvl, fmt, ...)   do { pr_##lvl(fmt, ## __VA_ARGS__); } while (0)
#define CLEVO_EMERG(fmt, ...)   __CLEVO_PR(emerg, fmt, ## __VA_ARGS__)
#define CLEVO_ALERT(fmt, ...)   __CLEVO_PR(alert, fmt, ## __VA_ARGS__)
#define CLEVO_CRIT(fmt, ...)   __CLEVO_PR(crit, fmt, ## __VA_ARGS__)
#define CLEVO_ERROR(fmt, ...)   __CLEVO_PR(err, fmt, ## __VA_ARGS__)
#define CLEVO_WARN(fmt, ...)   __CLEVO_PR(warning, fmt, ## __VA_ARGS__)
#define CLEVO_NOTICE(fmt, ...)   __CLEVO_PR(notice, fmt, ## __VA_ARGS__)
#define CLEVO_INFO(fmt, ...)   __CLEVO_PR(info, fmt, ## __VA_ARGS__)
#if defined(DEBUG) && DEBUG
#   define CLEVO_DEBUG(fmt, ...)   __CLEVO_PR(err, "[%s:%u] " fmt, __func__, __LINE__, ##__VA_ARGS__)
#else
#   define CLEVO_DEBUG(fmt, ...)   do { } while (0)
#endif

#define KB_MODE_DEFAULT   0


// Brightness & Region

#define BRIGHTNESS_MIN   0
#define BRIGHTNESS_25_PERCENT   64
#define BRIGHTNESS_MID   128
#define BRIGHTNESS_75_PERCENT   192
#define BRIGHTNESS_MAX   255
#define BRIGHTNESS_DEFAULT   BRIGHTNESS_MID

#define REGION_LEFT   0xF0000000
#define REGION_CENTER   0xF1000000
#define REGION_RIGHT   0xF2000000
#define REGION_EXTRA   0xF3000000
#define REGION_ALL   0xFF000000

#define KEYBOARD_BRIGHTNESS   0xF4000000

#define BRIGHTNESS_STEP   25


// Colors


#define color_struct(name, value)   { .color_name = #name, .color_val = value }


#define KB_COLOR_DEFAULT   0x00FF00
#define COLORS   { \
	color_struct(AQUA_MARINE, 0x7FFFD4), \
	color_struct(BEIGE, 0xF5F5DC), \
	color_struct(BLACK, 0x000000), \
	color_struct(BLUE, 0x0000FF), \
	color_struct(BROWN, 0xA52A2A), \
	color_struct(CYAN, 0x00FFFF), \
	color_struct(GREEN, 0x00FF00), \
	color_struct(GREY, 0xBBBBBB), \
	color_struct(MAGENTA, 0xFF00FF), \
	color_struct(ORANGE, 0xFFA500), \
	color_struct(PINK, 0xFFC0CB), \
	color_struct(PURPLE, 0x800080), \
	color_struct(RED, 0xFF0000), \
	color_struct(WHITE, 0xFFFFFF), \
	color_struct(YELLOW, 0xFFFF00), \
}


struct kbd_color {
	const char* const color_name;
	uint32_t color_val;
};

static const struct kbd_color kbd_colors[] = COLORS;
static const uint32_t num_kbd_colors = (uint32_t)(sizeof(kbd_colors) / sizeof((kbd_colors)[0]));


// Method IDs for CLEVO_GET

#define CLEVO_KBD_OFF   0xE007F001U
#define CLEVO_KBD_ON   0xE0003001U
#define CLEVO_WMI_EVENT   1
#define CLEVO_A2_POWER   5
#define CLEVO_WEBCAM_POWER   6
#define CLEVO_BLUETOOTH_POWER   7
#define CLEVO_TRACKPAD_POWER   9
#define GET_POWER_STATE_FOR_3G   0x0A
#define CLEVO_A4_POWER   0x0A
#define CLEVO_A7_POWER   0x11
#define CLEVO_WMI_A2_POWER   0x20
#define CLEVO_WMI_BLUETOOTH_POWER   0x21
#define CLEVO_WMI_WEBCAM_POWER   0x22
#define CLEVO_WMI_KB_BACKLIGHT   0x27
#define CLEVO_WMI_TRACKPAD_POWER   0x2A
#define CLEVO_KB_BACKLIGHT   0x3D
#define CLEVO_HOTKEY_ENABLE   0x46
#define CLEVO_WMI_IGNR_AC   0x48
#define CLEVO_WMI_POWER_BTN   0x49
#define CLEVO_WMI_A4_POWER   0x4C
#define SET_3G   0x4C
#define CLEVO_VGA   0x54  // 0 = DESCRETE, 0xFF = MSHYBRID
#define CLEVO_WMI_LCD_POWER   0x5E
#define CLEVO_WMI_FAN_CONTROL   0x65
#define SET_KB_LED   0x67
#define CLEVO_WMI_PER_FAN_SPEED   0x68   // Seperate fan speed values (set fans to manual)
#define CLEVO_WMI_PER_FAN_AUTO   0x69   // Reset fan speed control to automatic (0b1111)
#define CLEVO_WMI_INDX   0x6B
#define CLEVO_WMI_AIRPLANE_LED   0x6C
#define AIRPLANE_BUTTON   0x6D
#define CLEVO_EC   0x73
#define CLEVO_WMI_EC   0x75
#define TALK_BIOS_3G   0x78
#define CLEVO_WMI_ACC   0x79
#define CLEVO_I8042_SYNAPTIC_MODE 0x97
#define CLEVO_WMI_P65_OFFSET_AIRP 0xD9
#define CLEVO_WMI_P65_OFFSET_RINF 0xDB
#define CLEVO_WMI_P65_BIT_AIRP   0x40

#define CLEVO_UNUSED(x) (void)x



// WMI Codes

#define WMI_CODE_DECREASE_BACKLIGHT   0x81
#define WMI_CODE_INCREASE_BACKLIGHT   0x82
#define WMI_CODE_NEXT_MODE   0x83
#define WMI_CODE_TOGGLE_STATE   0x9F


/* MODULE SETTINGS */


MODULE_AUTHOR("Devyn Collier Johnson <DevynCJohnson@Gmail.com>");
MODULE_DESCRIPTION("Clevo Keyboard Driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("2020.05.25");

#define CLEVO_EMAIL_GUID   "ABBC0F6C-8EA1-11D1-00A0-C90629100000"
#define CLEVO_EVENT_GUID   "ABBC0F6B-8EA1-11D1-00A0-C90629100000"
#define CLEVO_GET_GUID   "ABBC0F6D-8EA1-11D1-00A0-C90629100000"


/* DATATYPES */


static struct kbd_struct {
	struct kbd_color_struct {
		uint32_t left;
		uint32_t center;
		uint32_t right;
		uint32_t extra;
	} color;
	uint8_t brightness;
	uint8_t has_extra;
	uint8_t kbdstate;
	uint8_t mode;
} keyboard = {
	.color =  {
		.left = KB_COLOR_DEFAULT,
		.center = KB_COLOR_DEFAULT,
		.right = KB_COLOR_DEFAULT,
		.extra = KB_COLOR_DEFAULT
	},
	.brightness = BRIGHTNESS_DEFAULT,
	.has_extra = 0,
	.kbdstate = 1,
	.mode = KB_MODE_DEFAULT
};


static struct kbd_mode_struct {
	const char* const name;
	uint32_t value;
	uint8_t key;
} modes[] = {
	{ .key = 0, .value = 0, .name = "CUSTOM" },
	{ .key = 1, .value = 0x1002a000, .name = "BREATHE" },
	{ .key = 2, .value = 0x33010000, .name = "CYCLE" },
	{ .key = 3, .value = 0x70000000, .name = "RANDOM_COLOR" },
	{ .key = 4, .value = 0x80000000, .name = "DANCE" },
	{ .key = 5, .value = 0x90000000, .name = "TEMPO" },
	{ .key = 6, .value = 0xA0000000, .name = "FLASH" },
	{ .key = 7, .value = 0xB0000000, .name = "WAVE" }
};


/* SYSFS INTERFACE FUNCTIONS */


// Utility Functions


static __attribute_const__ bool isws(const char character);
static void strip(char* string_ptr);
static __attribute_const__ int uppercase(const int symbol);
static int istrncmp(const char* restrict s1, const char* restrict s2, const size_t len);


// Getters

static ssize_t get_state_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_color_all_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_color_left_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_color_center_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_color_right_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_color_extra_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_brightness_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_mode_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);
static ssize_t get_hasextra_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer);


// Setters

static ssize_t set_state_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_color_all_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_color_left_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_color_center_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_color_right_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_color_extra_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_brightness_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static ssize_t set_mode_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size);
static void set_brightness(uint8_t brightness);
static void set_kb_state(uint8_t state);
static void set_mode(const uint8_t mode);
static int set_color(const uint32_t region, const uint32_t color);
static int set_color_region(const char* restrict buffer, const size_t size, const uint32_t region);


/* INIT & EXIT FUNCTIONS */


static int __init clevo_kbd_backlight_init(void);
static void __exit clevo_kbd_backlight_exit(void);
static int __init clevo_input_init(void);
static void __exit clevo_input_exit(void);


/* KEYBOARD CONTROL FUNCTIONS */


static int clevo_wmi_probe(struct platform_device* dev);
static int clevo_wmi_remove(struct platform_device* dev);
static int clevo_wmi_resume(struct platform_device* dev);
static void clevo_wmi_notify(const uint32_t value, void* context);
static int clevo_evaluate_method(const uint32_t method_id, uint32_t arg, uint32_t* restrict retval);


/* PARAMETER VALIDATORS */


static uint32_t color_validator(const char* restrict val);
static int mode_validator(const char* val, const struct kernel_param* kp);
static int brightness_validator(const char* val, const struct kernel_param* kp);


/* STATIC VARIABLES */


struct platform_device* clevo_platform_device = NULL;
static struct input_dev* clevo_input_device;
// static struct notifier_block lid_notifier;


static struct platform_driver clevo_platform_driver = {
	.driver = {
		.mod_name = DRIVER_NAME,
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.probe_type = PROBE_DEFAULT_STRATEGY,
		.suppress_bind_attrs = 0
	},
	.probe = clevo_wmi_probe,
	.remove = clevo_wmi_remove,
	.resume = clevo_wmi_resume
};


static const struct kernel_param_ops param_ops_mode_ops = {
	.flags = 0,
	.get = param_get_int,
	.set = mode_validator
};


static const struct kernel_param_ops param_ops_brightness_ops = {
	.flags = 0,
	.get = param_get_int,
	.set = brightness_validator
};


/* PARAMETER VARIABLES */


#define MOD_PERMS   S_IRUSR | S_IRGRP | S_IROTH


static uint32_t param_color_all = KB_COLOR_DEFAULT;
module_param_named(color_all, param_color_all, uint, MOD_PERMS);
MODULE_PARM_DESC(color_all, "Color for the whole keyboard");

static uint32_t param_color_left = KB_COLOR_DEFAULT;
module_param_named(color_left, param_color_left, uint, MOD_PERMS);
MODULE_PARM_DESC(color_left, "Color for the left section of the keyboard");

static uint32_t param_color_center = KB_COLOR_DEFAULT;
module_param_named(color_center, param_color_center, uint, MOD_PERMS);
MODULE_PARM_DESC(color_center, "Color for the center section of the keyboard");

static uint32_t param_color_right = KB_COLOR_DEFAULT;
module_param_named(color_right, param_color_right, uint, MOD_PERMS);
MODULE_PARM_DESC(color_right, "Color for the right section of the keyboard");

static uint32_t param_color_extra = KB_COLOR_DEFAULT;
module_param_named(color_extra, param_color_extra, uint, MOD_PERMS);
MODULE_PARM_DESC(color_extra, "Color for the extra section of the keyboard");

static uint16_t param_mode = KB_MODE_DEFAULT;
module_param_cb(mode, &param_ops_mode_ops, &param_mode, MOD_PERMS);
MODULE_PARM_DESC(mode, "Set the backlight mode of the keyboard");

static uint16_t param_brightness = BRIGHTNESS_DEFAULT;
module_param_cb(brightness, &param_ops_brightness_ops, &param_brightness, MOD_PERMS);
MODULE_PARM_DESC(brightness, "Set the keyboard brightness");

static bool param_state = true;
module_param_named(state, param_state, bool, MOD_PERMS);
MODULE_PARM_DESC(state, "Set the keyboard backlight on or off (TRUE = ON | FALSE = OFF)");


/* SYSFS DEVICE ATTRIBUTES */


static DEVICE_ATTR(brightness, 0664, get_brightness_fs, set_brightness_fs);
static DEVICE_ATTR(color_all, 0664, get_color_all_fs, set_color_all_fs);
static DEVICE_ATTR(color_center, 0664, get_color_center_fs, set_color_center_fs);
static DEVICE_ATTR(color_extra, 0664, get_color_extra_fs, set_color_extra_fs);
static DEVICE_ATTR(color_left, 0664, get_color_left_fs, set_color_left_fs);
static DEVICE_ATTR(color_right, 0664, get_color_right_fs, set_color_right_fs);
static DEVICE_ATTR(extra, 0444, get_hasextra_fs, NULL);
static DEVICE_ATTR(mode, 0664, get_mode_fs, set_mode_fs);
static DEVICE_ATTR(state, 0664, get_state_fs, set_state_fs);


#endif  // _CLEVO_KBD_BACKLIGHT_H
