#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <switch.h>

int main(int argc, char **argv)
{
    // Initialize the console text system
    consoleInit(NULL);

    // Set a vibrant blue color for the header (ANSI code)
    printf("\x1b[1;36m"); 
    printf("\n\n   === AOS 11 OPERATING SYSTEM ===\n\n");
    printf("\x1b[0m"); // Reset color

    printf("   [+] Verifying Wii U System Integrity...\n");
    printf("   [+] Connection Established.\n\n");

    // The Countdown Loop
    for(int i = 5; i > 0; i--) {
        // \r moves cursor to start of line to overwrite the number
        printf("\r   ✨ SUCCESS! Booting back to Hekate in %d...", i);
        consoleUpdate(NULL);
        
        // Wait exactly 1 second (1 billion nanoseconds)
        svcSleepThread(1000000000ULL);
    }

    printf("\n\n   [+] Rebooting hardware...\n");
    consoleUpdate(NULL);
    
    // Command to reboot the console back to payload/RCM mode
    bpcRebootToRcm();

    consoleExit(NULL);
    return 0;
}
