void output_meminfo(multiboot_info_t *mboot_ptr) {
  //Lower Memory
  terminal_writestring_colored("[", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("INFO", VGA_COLOR_LIGHT_CYAN, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("] ", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring("LOWER MEMORY: ");
  multiboot_uint32_t uml = mboot_ptr->mem_lower;
  int ml = (int)uml;
  terminal_writeint_colored(ml, VGA_COLOR_LIGHT_RED, BOOT_BACKGROUND_COLOR);
  terminal_writestring("K\n");

/*
  //Upper Memory
  terminal_writestring_colored("[", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("INFO", VGA_COLOR_LIGHT_CYAN, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("] ", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring("UPPER MEMORY: ");
  multiboot_uint32_t umu = mboot_ptr->mem_upper;
  int mu = (int)umu;
  terminal_writeint_colored(mu, VGA_COLOR_LIGHT_RED, BOOT_BACKGROUND_COLOR);
  terminal_writestring("K\n");

  //MMap Length
  terminal_writestring_colored("[", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("INFO", VGA_COLOR_LIGHT_CYAN, BOOT_BACKGROUND_COLOR);
  terminal_writestring_colored("] ", VGA_COLOR_DARK_GREY, BOOT_BACKGROUND_COLOR);
  terminal_writestring("MMAP LENGTH: ");
  multiboot_uint32_t umlen = mboot_ptr->mmap_length;
  int mlen = (int)umlen;
  terminal_writeint_colored(mlen, VGA_COLOR_LIGHT_RED, BOOT_BACKGROUND_COLOR);
  terminal_writestring("K\n");
*/
}
