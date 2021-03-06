// Utilities to handle RDH content from CRU data


#include <string>
#include "RAWDataHeader.h"


// Utility class to access RDH fields and check them
class RdhHandle {
  public:
  // create a handle to RDH structure pointed by argument
  RdhHandle(void *data);

  // destructor
  ~RdhHandle();
  
  // check RDH content
  // returns 0 on success, number of errors found otherwise
  // Error message sets accordingly
  int validateRdh(std::string &err);
  
  // print RDH content 
  void dumpRdh();
 
  // access RDH fields
  // functions defined inline here
  inline uint8_t getHeaderVersion() {
    return rdhPtr->version;  
  } 
  inline uint16_t getBlockLength() {
    return (uint16_t) rdhPtr->blockLength;
  }
  inline uint16_t getFeeId() {
    return (uint16_t) rdhPtr->feeId;
  }  
  inline uint8_t getLinkId() {
    return (uint8_t) rdhPtr->linkId;
  }  
  inline uint8_t getHeaderSize() {
    return rdhPtr->headerSize;
  }
  inline uint32_t getHbOrbit() {
    return (uint32_t) rdhPtr->heartbeatOrbit;
  }
  inline uint16_t getMemorySize() {
    return (uint16_t) rdhPtr->memorySize;
  }
  inline uint16_t getOffsetNextPacket() {
    return (uint16_t) rdhPtr->offsetNextPacket;
  }
  inline bool getStopBit() {
    return (bool) rdhPtr->stopBit;
  }
  private:
  o2::Header::RAWDataHeader *rdhPtr;  // pointer to RDH in memory
};


// Utility class to access/parse/check the content of a contiguous memory block consisting of RDH+data
class RdhBlockHandle {
  public:
  // create a handle to the block, providing pointer and size
  RdhBlockHandle(void *blockPtr, size_t size);

  // destructor
  ~RdhBlockHandle();
  
  // print summary
  // return 0 on success, an error code if the block is invalid
  int printSummary();
  
  private:
  void *blockPtr; // pointer to beginning of memory block
  size_t blockSize; // size of memory block
};
