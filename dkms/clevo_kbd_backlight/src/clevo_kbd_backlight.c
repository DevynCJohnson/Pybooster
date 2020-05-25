// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
/**
@brief Clevo Keyboard Backlight Driver for Linux
@file clevo_kbd_backlight.c
@version 2020.05.25
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section BUILD
```sh
make clean && make
```

@section INSTALL
```sh
sudo dkms install -m clevo_kbd_backlight -v 2020.05.25
```

@section LOAD_MODULE
```sh
sudo modprobe clevo_kbd_backlight
```

@section UNLOAD_MODULE
```sh
sudo modprobe -r clevo_kbd_backlight
```

@section BUILD_AND_INSTALL
```sh
make clean
sudo cp -f -R . /usr/src/clevo_kbd_backlight-2020.05.25
sudo dkms add -m clevo_kbd_backlight -v 2020.05.25
sudo dkms build -m clevo_kbd_backlight -v 2020.05.25
sudo dkms install -m clevo_kbd_backlight -v 2020.05.25
```

@section UNINSTALLING
Remove the dkms module and the source code
```sh
sudo dkms remove -m clevo_kbd_backlight -v 2020.05.25 --all
sudo rm -f -r /usr/src/clevo_kbd_backlight-2020.05.25`
```

@section SYSFS_DOCUMENTATION
Path: /sys/devices/platform/clevo_kbd_backlight
 - brightness: Works on a scale of "0" (off) - "255" (brightess)
 - color_all: Must use the hexadecimal format "0xFF00FF" (Magenta) or a name of a color
 - color_center: Must use the hexadecimal format "0xFF00FF" (Magenta) or a name of a color
 - color_extra: Must use the hexadecimal format "0xFF00FF" (Magenta) or a name of a color
 - color_left: Must use the hexadecimal format "0xFF00FF" (Magenta) or a name of a color
 - color_right: Must use the hexadecimal format "0xFF00FF" (Magenta) or a name of a color
 - extra: "0" if no extra region is present or "1" if present
 - mode: One of several backlight behaviors specified on a scale "0" - "7"
 - state: "0" is off and "1" is on

Changing Values via the Shell:
```sh
cd /sys/devices/platform/clevo_kbd_backlight
printf '%s' '1' > ./state
# Try the different modes
printf '%s' '0' > ./mode
printf '%s' '1' > ./mode
printf '%s' '2' > ./mode
printf '%s' '3' > ./mode
printf '%s' '4' > ./mode
printf '%s' '5' > ./mode
printf '%s' '6' > ./mode
printf '%s' '7' > ./mode
# Change colors on different regions
printf '%s\n' '0x00FF00' > ./color_center
printf '%s\n' '0xFF00FF' > ./color_left
printf '%s\n' '0xFFFF00' > ./color_right
printf '%s' 'yellow' > ./color_all
# Change brightness
printf '%s\n' '150' > ./brightness
```

@section KERNEL_PARAMETER_DOCUMENTATION
```sh
sudo su
echo "options clevo_kbd_backlight mode=0 color_left=0xFF0000 color_center=0x00FF00 color_right=0x000000" > /etc/modprobe.d/clevo_kbd_backlight.conf
echo clevo_kbd_backlight >> /etc/modules
modprobe clevo_kbd_backlight <params>
```
 - brightness: Set the brightness of keyboard
 - color_all: Set the color of the whole keyboard
 - color_center: Set the color of the center of the keyboard
 - color_extra: Set the color of the extra region of the keyboard (if present)
 - color_left: Set the color of the left-side of the keyboard
 - color_right: Set the color of the right-side of the keyboard
 - mode: Set the behavior of the keyboard
 - state: Set the state (on/off) of the keyboard

@section MODE_DOCUMENTATION
 - CUSTOM: 0
 - BREATHE: 1
 - CYCLE: 2
 - RANDOM_COLOR: 3
 - DANCE: 4
 - TEMPO: 5
 - FLASH: 6
 - WAVE: 7

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


#include "clevo_kbd_backlight.h"


/* UTILITY FUNCTIONS */


/** Test if the character is whitespace */
static __attribute_const__ bool isws(const char character) {
	switch ((int)character) {
		case '\0':
		case ' ':
		case '\n':
		case '\t':
		case '\x0C':
		case '\r':
			return TRUE;
		default:
			break;
	}
	return FALSE;
}


/** Strip leading and trailing whitespace in a string */
static void strip(char* string_ptr) {
	// Setup
	const size_t stringlen = strnlen(string_ptr, BUF_SIZE);
	char* start_ptr = string_ptr;
	char* end_ptr = string_ptr + stringlen;
	char* placement_ptr = string_ptr;
	// Remove Trailing Space
	while (isws(*end_ptr)) {
		*end_ptr-- = '\0';
	}
	// Remove Leading Space
	if (!isws(*start_ptr)) {
		return;
	}
	while (isws(*start_ptr++));
	while (*start_ptr) {
		*placement_ptr++ = *start_ptr++;
	}
	*placement_ptr = '\0';
}


/** Convert the char to a uppercase ASCII letter */
static __attribute_const__ int uppercase(const int symbol) {
	return (((0x60 < symbol) && (symbol < 0x7b)) ? (int)(symbol & '_') : symbol);
}


/** Compare two strings case-insensitively; This function starts comparing the first character of each string; If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached. */
static int istrncmp(const char* restrict s1, const char* restrict s2, const size_t len) {
	const unsigned char* restrict c1 = (const unsigned char*)s1;
	const unsigned char* restrict c2 = (const unsigned char*)s2;
	register unsigned char ch = 0;
	register int d = 0;
	register size_t n = len;
	if ((s1 == NULL) || (s2 == NULL)) { return -1; }
	while (n--) {
		ch = uppercase(*c1++);
		if (ch == ' ') { ch = '_'; }
		d = (int)(ch) - ((int)*c2++);
		if (d || (!ch) || (!*c2)) { break; }
	}
	return d;
}


/* FUNCTIONS (GETTERS) */


/** SysFS interface used to view the keyboard state (ON / OFF) */
static ssize_t get_state_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%d\n", keyboard.kbdstate);
}


/** SysFS interface used to view the color (as a hex value) of the whole keyboard */
static ssize_t get_color_all_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%06x\n%06x\n%06x\n%06x\n", keyboard.color.left, keyboard.color.center, keyboard.color.right, keyboard.color.extra);
}


/** SysFS interface used to view the color (as a hex value) of the left-side of the keyboard */
static ssize_t get_color_left_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%06x\n", keyboard.color.left);
}


/** SysFS interface used to view the color (as a hex value) of the center of the keyboard */
static ssize_t get_color_center_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%06x\n", keyboard.color.center);
}


/** SysFS interface used to view the color (as a hex value) of the right-side of the keyboard */
static ssize_t get_color_right_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%06x\n", keyboard.color.right);
}


/** SysFS interface used to view the color (as a hex value) of the extra region of the keyboard */
static ssize_t get_color_extra_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%06x\n", keyboard.color.extra);
}


/** SysFS interface used to show the brightness of the keyboard on a scale 0-255 (where 255 is the brightest) */
static ssize_t get_brightness_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%d\n", keyboard.brightness);
}


/** SysFS interface used to retrieve the value of the current keyboard mode */
static ssize_t get_mode_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%d\n", keyboard.mode);
}


/** SysFS interface used to check if the keyboard has an extra region */
static ssize_t get_hasextra_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, char* restrict buffer) {
	return sprintf(buffer, "%d\n", keyboard.has_extra);
}


/* FUNCTIONS (SETTERS) */


/** SysFS interface used to set the keyboard state to "on" or "off" */
static ssize_t set_state_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	unsigned int val = 0;
	const int ret = kstrtouint(buffer, 0, &val);
	if (ret) { return ret; }
	val = clamp_t(uint8_t, val, 0, 1);
	set_kb_state(val);
	return ret ? : size;
}


/** SysFS interface used to set the color (given a hex value of the format "0xFF00FF") of the whole keyboard */
static ssize_t set_color_all_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	return set_color_region(buffer, size, REGION_ALL);
}


/** SysFS interface used to set the color (given a hex value of the format "0xFF00FF") of the left-side of the keyboard */
static ssize_t set_color_left_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	return set_color_region(buffer, size, REGION_LEFT);
}


/** SysFS interface used to set the color (given a hex value of the format "0xFF00FF") of the center of the keyboard */
static ssize_t set_color_center_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	return set_color_region(buffer, size, REGION_CENTER);
}


/** SysFS interface used to set the color (given a hex value of the format "0xFF00FF") of the right-side of the keyboard */
static ssize_t set_color_right_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	return set_color_region(buffer, size, REGION_RIGHT);
}


/** SysFS interface used to set the color (given a hex value of the format "0xFF00FF") of the extra region of the keyboard */
static ssize_t set_color_extra_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char *buffer, size_t size) {
	if (keyboard.has_extra == 1) {
		return set_color_region(buffer, size, REGION_EXTRA);
	}
	return 0;
}


/** SysFS interface used to set the brightness of the keyboard on a scale 0-255 (where 255 is the brightest) */
static ssize_t set_brightness_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	unsigned int val = 0;
	const int ret = kstrtouint(buffer, 0, &val);
	if (ret) { return ret; }
	val = clamp_t(uint8_t, val, BRIGHTNESS_MIN, BRIGHTNESS_MAX);
	set_brightness(val);
	return ret ? : size;
}


/** SysFS interface used to set the value of the current keyboard mode as a value 0-7 */
static ssize_t set_mode_fs(__maybe_unused struct device* child, __maybe_unused struct device_attribute* attr, const char* buffer, const size_t size) {
	unsigned int val = 0;
	const int ret = kstrtouint(buffer, 0, &val);
	if (ret) { return ret; }
	val = clamp_t(uint8_t, val, 0, ARRAY_SIZE(modes) - 1);
	set_mode(val);
	return ret ? : size;
}


/** Set the value of the current keyboard mode as a value 0-7 */
static void set_mode(const uint8_t mode) {
	CLEVO_DEBUG("Set mode to %s (Clevo Keyboard Backlight Driver)\n", modes[mode].name);
	if (!clevo_evaluate_method(SET_KB_LED, modes[mode].value, NULL)) {
		keyboard.mode = mode;
	}
	if (mode == 0) {
		set_color(REGION_LEFT, keyboard.color.left);
		set_color(REGION_CENTER, keyboard.color.center);
		set_color(REGION_RIGHT, keyboard.color.right);
		if (keyboard.has_extra == 1) {
			set_color(REGION_EXTRA, keyboard.color.extra);
		}
	}
}


/** Set the brightness of the keyboard on a scale 0-255 (where 255 is the brightest) */
static void set_brightness(const uint8_t brightness) {
	CLEVO_DEBUG("Set brightness to %d (Clevo Keyboard Backlight Driver)\n", brightness);
	if (!clevo_evaluate_method(SET_KB_LED, 0xF4000000 | brightness, NULL)) {
		keyboard.brightness = brightness;
	}
}


/** Set the keyboard state to "on" or "off" */
static void set_kb_state(const uint8_t kbdstate) {
	register uint32_t cmd = CLEVO_KBD_OFF;
	CLEVO_DEBUG("Set keyboard state to %d (Clevo Keyboard Backlight Driver)\n", kbdstate);
	if (kbdstate == 0) {
		cmd = CLEVO_KBD_ON;
	}
	if (!clevo_evaluate_method(SET_KB_LED, cmd, NULL)) {
		keyboard.kbdstate = kbdstate;
	}
}


/** Set the color (given a hex value of the format "0xFF00FF") of the specified area of the keyboard */
static int set_color(const uint32_t region, const uint32_t color) {
	const uint32_t cset = ((color & 0x0000FF) << 16) | ((color & 0xFF0000) >> 8) | ((color & 0x00FF00) >> 8);
	uint32_t cmd = 0;
	int retval = 0;
	CLEVO_DEBUG("Set Color '%08x' for region '%08x' (Clevo Keyboard Backlight Driver)\n", color, region);
	if (region == REGION_ALL) {
		cmd = REGION_LEFT | cset;
		retval = clevo_evaluate_method(SET_KB_LED, cmd, NULL);
		if (retval == 0) {
			cmd = REGION_CENTER | cset;
			retval = clevo_evaluate_method(SET_KB_LED, cmd, NULL);
		}
		if (retval == 0) {
			cmd = REGION_RIGHT | cset;
			retval = clevo_evaluate_method(SET_KB_LED, cmd, NULL);
		}
		if (retval == 0 && keyboard.has_extra == 1) {
			cmd = REGION_EXTRA | cset;
			retval = clevo_evaluate_method(SET_KB_LED, cmd, NULL);
		}
		return retval;
	}
	cmd = region | cset;
	return clevo_evaluate_method(SET_KB_LED, cmd, NULL);
}


/** Set the color (given a hex value of the format "0xFF00FF") of the specified area of the keyboard */
static int set_color_region(const char* restrict buffer, const size_t size, const uint32_t region) {
	uint32_t val = 0;
	int ret = 0;
	char strbuffer[BUF_SIZE] = { 0 };
	if (unlikely(isempty(buffer))) {
		return 0xFFFFFFFD;
	}
	// Prepare the buffer string
	(void)strncpy(strbuffer, buffer, BUF_SIZE);
	strip(strbuffer);
	if (strbuffer[1] == 'X') { strbuffer[1] = 'x'; }
	// Get the color
	if (strbuffer[0] == '0' && strbuffer[1] == 'x') {  // Color Hexadecimal Format
		ret = kstrtouint(strbuffer, 16, &val);
		if (ret) { return ret; }
	} else {  // Color Name
		val = color_validator(strbuffer);
		if (val == 0xFFFFFFFF) { return 0xFFFFFFFF; }
	}
	// Set color in the specified region
	if (!set_color(region, val)) {
		switch (region) {
			case REGION_LEFT:
				keyboard.color.left = val;
				break;
			case REGION_CENTER:
				keyboard.color.center = val;
				break;
			case REGION_RIGHT:
				keyboard.color.right = val;
				break;
			case REGION_EXTRA:
				keyboard.color.extra = val;
				break;
			case REGION_ALL:
				keyboard.color.left = val;
				keyboard.color.center = val;
				keyboard.color.right = val;
				keyboard.color.extra = val;
				break;
			default:
				return 0xFFFFFFFE;
		}
	}
	return ret ? : size;
}


/* INIT & EXIT FUNCTIONS */


/** Initialize the backlight capabilities of this driver */
static int __init clevo_kbd_backlight_init(void) {
	if (!wmi_has_guid(CLEVO_EVENT_GUID))  {
		CLEVO_ERROR("No known WMI event notification GUID found (Clevo Keyboard Backlight Driver)\n");
		return -ENODEV;
	}
	if (!wmi_has_guid(CLEVO_GET_GUID))  {
		CLEVO_ERROR("No known WMI control method GUID found (Clevo Keyboard Backlight Driver)\n");
		return -ENODEV;
	}
	CLEVO_DEBUG("Model '%s' found (Clevo Keyboard Backlight Driver)\n", dmi_get_system_info(DMI_PRODUCT_NAME));
	clevo_platform_device = platform_create_bundle(&clevo_platform_driver, clevo_wmi_probe, NULL, 0, NULL, 0);
	if (unlikely(IS_ERR(clevo_platform_device))) {
		CLEVO_ERROR("Cannot init platform driver (Clevo Keyboard Backlight Driver)");
		return PTR_ERR(clevo_platform_device);
	}
	if (unlikely(clevo_input_init())) {
		CLEVO_ERROR("Could not register input device (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_state) != 0) {
		CLEVO_ERROR("Sysfs attribute creation failed for keyboard state (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_color_left) != 0) {
		CLEVO_ERROR("Sysfs attribute creation failed for keyboard left-side color (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_color_center) != 0) {
		CLEVO_ERROR("Sysfs attribute creation failed for keyboard center color (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_color_right) != 0) {
		CLEVO_ERROR("Sysfs attribute creation failed for keyboard right-side color (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_color_all) != 0) {
		CLEVO_ERROR("Sysfs attribute creation failed for whole keyboard color (Clevo Keyboard Backlight Driver)\n");
	}
	if (set_color(REGION_EXTRA, KB_COLOR_DEFAULT) != 0) {
		CLEVO_DEBUG("Keyboard does not support extra region (Clevo Keyboard Backlight Driver)\n");
		keyboard.has_extra = 0;
	} else {
		keyboard.has_extra = 1;
		if (device_create_file(&clevo_platform_device->dev, &dev_attr_color_extra) != 0) {
			CLEVO_ERROR("SysFS attribute creation failed for keyboard extra region (Clevo Keyboard Backlight Driver)\n");
		}
		set_color(REGION_EXTRA, param_color_extra);
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_extra) != 0) {
		CLEVO_ERROR("SysFS attribute creation failed for keyboard extra information flag (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_mode) != 0) {
		CLEVO_ERROR("SysFS attribute creation failed for keyboard mode (Clevo Keyboard Backlight Driver)\n");
	}
	if (device_create_file(&clevo_platform_device->dev, &dev_attr_brightness) != 0) {
		CLEVO_ERROR("SysFS attribute creation failed for keyboard brightness (Clevo Keyboard Backlight Driver)\n");
	}
	set_color(REGION_LEFT, param_color_left);
	set_color(REGION_CENTER, param_color_center);
	set_color(REGION_RIGHT, param_color_right);
	set_mode(param_mode);
	set_brightness(param_brightness);
	set_kb_state(param_state);
	return 0;
}


/** Clean-up and close the backlight capabilities of this driver */
static void __exit clevo_kbd_backlight_exit(void) {
	clevo_input_exit();
	device_remove_file(&clevo_platform_device->dev, &dev_attr_state);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_color_all);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_color_left);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_color_center);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_color_right);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_extra);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_mode);
	device_remove_file(&clevo_platform_device->dev, &dev_attr_brightness);
	if (keyboard.has_extra == 1) {
		device_remove_file(&clevo_platform_device->dev, &dev_attr_color_extra);
	}
	platform_device_unregister(clevo_platform_device);
	platform_driver_unregister(&clevo_platform_driver);
	CLEVO_DEBUG("exit (Clevo Keyboard Backlight Driver)\n");
}


/** Initialize the input capabilities of this driver */
static int __init clevo_input_init(void) {
	int err = 0;
	clevo_input_device = input_allocate_device();
	if (unlikely(!clevo_input_device))  {
		CLEVO_ERROR("Error allocating input device (Clevo Keyboard Input Driver)\n");
		return -ENOMEM;
	}
	clevo_input_device->name = DEVICE_NAME;
	clevo_input_device->phys = DRIVER_NAME "/input0";
	clevo_input_device->id.bustype = BUS_HOST;
	clevo_input_device->dev.parent = &clevo_platform_device->dev;
	set_bit(EV_KEY, clevo_input_device->evbit);
	err = input_register_device(clevo_input_device);
	if (unlikely(err)) {
		CLEVO_ERROR("Error registering input device (Clevo Keyboard Input Driver)\n");
		input_free_device(clevo_input_device);
		return err;
	}
	return 0;
}


/** Clean-up and close the input capabilities of this driver */
static void __exit clevo_input_exit(void) {
	if (likely(clevo_input_device)) {
		input_unregister_device(clevo_input_device); { clevo_input_device = NULL; }
	}
}


/* KEYBOARD CONTROL FUNCTIONS */


static int clevo_wmi_probe(struct platform_device* dev) {
	const int status = wmi_install_notify_handler(CLEVO_EVENT_GUID, clevo_wmi_notify, NULL);
	CLEVO_DEBUG("clevo_xsm_wmi_probe status = %0#6x (Clevo Keyboard Driver)\n", status);
	if (unlikely(ACPI_FAILURE(status))) {
		CLEVO_ERROR("Could not register WMI notify handler %0#6x (Clevo Keyboard Driver)\n", status);
		return -EIO;
	}
	return clevo_evaluate_method(CLEVO_HOTKEY_ENABLE, 0, NULL);
}


static int clevo_wmi_remove(struct platform_device* dev) {
	return wmi_remove_notify_handler(CLEVO_EVENT_GUID);
}


static int clevo_wmi_resume(struct platform_device* dev) {
	return clevo_evaluate_method(CLEVO_HOTKEY_ENABLE, 0, NULL);
}


static void clevo_wmi_notify(const uint32_t value, void* context) {
	uint32_t event = 0;
	clevo_evaluate_method(CLEVO_WMI_EVENT, 0, &event);
	CLEVO_DEBUG("WMI event %0#6x (Clevo Keyboard Driver)\n", event);
	switch (event) {
		case WMI_CODE_DECREASE_BACKLIGHT:
			if (keyboard.brightness == BRIGHTNESS_MIN || (keyboard.brightness - BRIGHTNESS_STEP) < BRIGHTNESS_MIN) {
				set_brightness(BRIGHTNESS_MIN);
			} else {
				set_brightness(keyboard.brightness - BRIGHTNESS_STEP);
			}
			break;
		case WMI_CODE_INCREASE_BACKLIGHT:
			if (keyboard.brightness == BRIGHTNESS_MAX || (keyboard.brightness + BRIGHTNESS_STEP) > BRIGHTNESS_MAX) {
				set_brightness(BRIGHTNESS_MAX);
			} else {
				set_brightness(keyboard.brightness + BRIGHTNESS_STEP);
			}
			break;
		case WMI_CODE_NEXT_MODE:
			set_mode((keyboard.mode + 1) > (ARRAY_SIZE(modes) - 1) ? 0 : (keyboard.mode + 1));
			break;
		case WMI_CODE_TOGGLE_STATE:
			set_kb_state(keyboard.kbdstate == 0 ? 1 : 0);
			break;
		default:
			break;
	}
}


static int clevo_evaluate_method(const uint32_t method_id, uint32_t arg, uint32_t* restrict retval) {
	uint32_t tmp = 0U;
	struct acpi_buffer in = { (acpi_size)sizeof(arg), &arg };
	struct acpi_buffer out = { ACPI_ALLOCATE_BUFFER, NULL };
	union acpi_object* obj = NULL;
	const acpi_status status = wmi_evaluate_method(CLEVO_GET_GUID, 0, method_id, &in, &out);
	CLEVO_DEBUG("Evaluate method: %0#4x IN : %0#6x (Clevo Keyboard Driver)\n", method_id, arg);
	if (unlikely(ACPI_FAILURE(status))) {
		CLEVO_ERROR("Evaluate method error (Clevo Keyboard Driver)");
		if (unlikely(ACPI_FAILURE(status))) {
			return -EIO;
		}
	}
	obj = (union acpi_object*)out.pointer;
	if (obj && obj->type == ACPI_TYPE_INTEGER) {
		tmp = (uint32_t)obj->integer.value;
	}
	CLEVO_DEBUG("%0#4x OUT: %0#6x IN: %0#6x (Clevo Keyboard Driver)\n", method_id, tmp, arg);
	if (likely(retval)) {
		*retval = tmp;
	}
	kfree(obj);
	return 0;
}


/* PARAMETER VALIDATORS */


/** Check if the string is a name of a color. */
static uint32_t color_validator(const char* restrict val) {
	for (uint32_t i = 0; i < num_kbd_colors; i++) {
		if (istrncmp(val, kbd_colors[i].color_name, BUF_SIZE) == 0) {
			return (uint32_t)kbd_colors[i].color_val;
		}
	}
	return 0xFFFFFFFF;
}


static int mode_validator(const char* val, const struct kernel_param* kp) {
	int mode = 0;
	const int ret = kstrtoint(val, 10, &mode);
	if (ret != 0 || mode < 0 || mode > (ARRAY_SIZE(modes) - 1)) {
		return -EINVAL;
	}
	return param_set_int(val, kp);
}


static int brightness_validator(const char* val, const struct kernel_param* kp) {
	int brightness = 0;
	const int ret = kstrtoint(val, 10, &brightness);
	if (ret != 0 || brightness < BRIGHTNESS_MIN || brightness > BRIGHTNESS_MAX) {
		return -EINVAL;
	}
	return param_set_int(val, kp);
}


/* INITIATE MODULE */


module_init(clevo_kbd_backlight_init);
module_exit(clevo_kbd_backlight_exit);
