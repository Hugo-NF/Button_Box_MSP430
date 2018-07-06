#ifndef MEMORY_H_
#define MEMORY_H_

static const unsigned char * INFOMEM = (unsigned char *) 0x1000;


/*
 * ======== save string ========
 */
// Save a array of byte to the information memory
inline void save_string(char* string, unsigned char* address){
    uint8_t i;
    char * segment;
    segment = (char *) INFOMEM;

    FCTL3 = FWKEY; // Unlock flash memory
    FCTL1 = (FWKEY | WRT); // Set write byte mode

    for(i=0; i < strlen(string); i++){
        segment[((unsigned char) address) + i] = string[i]; // Write byte
        while((FCTL3 & WAIT) != WAIT); // Wait for write to complete
    }

    FCTL1 &= !WRT; // clear write byte mode
    FCTL3 = (FWKEY | LOCK); // Lock flash memory
}

#endif /* MEMORY_H_ */
