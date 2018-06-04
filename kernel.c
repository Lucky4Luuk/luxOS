//https://wiki.osdev.org/Going_Further_on_x86
//https://wiki.osdev.org/User:Zesterer/Bare_Bones
//https://wiki.osdev.org/Setting_Up_Paging
//https://wiki.osdev.org/Higher_Half_x86_Bare_Bones

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "itoa.h"
#include "multiboot.h"
#include "terminal.h"
#include "utils.h"
//#include "monitor.h"

/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

multiboot_info_t *mboot_ptr;
//vbe_mode_info_struct_t *vbe_mode_info_v;

void kernel_main(multiboot_info_t *mboot_info, unsigned int magic)
{
	// Initialize terminal interface
	terminal_initialize();

	// Write first messages (logo and welcome to blueboot message)
  terminal_setcolor(VGA_COLOR_LIGHT_MAGENTA, BOOT_BACKGROUND_COLOR);
	terminal_writestring(" _     _   ___   _______ _____ \n");
  terminal_writestring("| |   | | | \\ \\ / /  _  /  ___|\n");
  terminal_writestring("| |   | | | |\\ V /| | | \\ `--. \n");
  terminal_writestring("| |   | | | |/   \\| | | |`--. \\\n");
  terminal_writestring("| |___| |_| / /^\\ \\ \\_/ /\\__/ /\n");
  terminal_writestring("\\_____/\\___/\\/   \\/\\___/\\____/ \n");
  terminal_setcolor(BOOT_FOREGROUND_COLOR, BOOT_BACKGROUND_COLOR);
  terminal_writestring("\nBlueBoot initialized.\n");
  terminal_writestring("Welcome to BlueBoot!\n\n");

  // Initialize parts of the OS

  //Load ram
  terminal_writestring_colored("[", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("INFO", VGA_COLOR_LIGHT_CYAN, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("] ", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring("MAGIC: ");
  terminal_writeint_colored(magic, VGA_COLOR_LIGHT_RED, BOOT_BACKGROUND_COLOR);
  terminal_writestring("\n");

	mboot_ptr = mboot_info;

  output_meminfo(mboot_ptr);
	//ALL DEPRECATED NOW
	//vbe_mode_info_v = (vbe_mode_info_struct_t*)(mboot_ptr->vbe_mode_info);
	//unsigned char* screen = (unsigned char*)(vbe_mode_info_v->framebuffer);
	//putpixel(screen, 1,1, 5);
}
