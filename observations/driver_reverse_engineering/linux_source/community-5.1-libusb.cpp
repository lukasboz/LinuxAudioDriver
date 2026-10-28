#include <libusb-1.0/libusb.h>
#include <iostream>
#include <cstdint>

constexpr std::uint16_t vendor_id = 0x0db0;
constexpr std::uint16_t product_id = 0xcd0e;
//constexpr unsigned char mode = 0b00000100;

struct usb_exit
{
	~usb_exit()
	{
		libusb_exit(nullptr);
	}
};

struct usb_device_guard
{
	libusb_device_handle *m_handle;

	~usb_device_guard()
	{
		libusb_close(m_handle);
	}
};

int main()
{
	int result = libusb_init(nullptr);
	if ( result < 0 )
	{
		std::cerr << "Error initializing libusb: " << libusb_error_name(result) << '\n';
		return 1;
	}
	usb_exit usb_exit_guard;

	libusb_set_option(nullptr, LIBUSB_OPTION_LOG_LEVEL, LIBUSB_LOG_LEVEL_WARNING);

	auto device_handle = libusb_open_device_with_vid_pid(nullptr, vendor_id, product_id);
	if(!device_handle)
	{
		std::cerr << "Error opening usb device.\n";
		return 1;
	}
	usb_device_guard dguard{device_handle};

	unsigned char data[1] = {0b00000010};
	if ((result = libusb_control_transfer(device_handle, 0x40, 108, 0, 1, data, 1, 0)) < 0)
	{
		std::cerr << "libusb_control_transfer error: " << libusb_error_name(result) << '\n';
		return 1;
	}

	data[0] = 0b00000100;
	if ((result = libusb_control_transfer(device_handle, 0x40, 108, 0, 1, data, 1, 0)) < 0)
	{
		std::cerr << "libusb_control_transfer error: " << libusb_error_name(result) << '\n';
		return 1;
	}

	return 0;
}
