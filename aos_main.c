// AOS 11 KERNEL - TUI MODE
// Based on BDK (Bot Development Kit)

#include <bdk/bdk.h>

// This function runs when the switch boots
void main() {
    // 1. Initialize Hardware (Screen, SD Card, Input)
    bdk_init();
    
    // 2. Clear Screen and Set Colors (Black Background, Cyan Text)
    gfx_clear_grey(0x00); // 0x00 is Black
    gfx_con_setpos(0, 0); // Top Left
    gfx_set_text_color(0xFFFF0000); // Cyan (ARGB)

    // 3. Print the Header
    printf("\n");
    printf("   === AOS 11 TERMINAL ===\n");
    printf("   Version 1.0 (Tegra-Base)\n");
    printf("   ------------------------\n\n");
    
    // 4. The Main "OS" Loop
    while (true) {
        // Print the prompt
        printf(0xFF00FF00, "AOS@root:~$ "); // Green Prompt
        
        // Wait for user to press A to open keyboard
        // (Since we don't have a physical keyboard, we summon the virtual one)
        char* input = kbd_get_input("Enter Command");

        // Echo back what they typed
        printf("%s\n", input);

        // Simple Command Handling
        if (strcmp(input, "help") == 0) {
            printf("Available commands: help, clear, reboot, shutdown, whoami\n");
        }
        else if (strcmp(input, "reboot") == 0) {
            printf("Rebooting...\n");
            power_reboot();
        }
        else if (strcmp(input, "shutdown") == 0) {
            power_poweroff();
        }
        else if (strcmp(input, "clear") == 0) {
            gfx_clear_grey(0x00);
            gfx_con_setpos(0, 0);
            printf("\n   === AOS 11 TERMINAL ===\n\n");
        }
        else if (strcmp(input, "whoami") == 0) {
            printf("root (AOS Admin)\n");
        }
        else {
            printf("Error: Command '%s' not found.\n", input);
        }

        // Refresh screen to show changes
        gfx_flush();
    }
}
