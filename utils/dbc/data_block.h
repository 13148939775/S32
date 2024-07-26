
#ifndef DATA_BLOCK_H
#define DATA_BLOCK_H

#include <cstdint>

enum : uint32_t {
    BLK_DEFAULTSC       = 0x00,
    BLK_READINGSC       = 0x01,
    BLK_LOOKINGSC       = 0x02,
    BLK_SLEEPINGSC      = 0x03,
    BLK_LIGHTSHOWSC     = 0x04,
    BLK_COOLINGSC       = 0x05,
    BLK_DRIVERCOOLSC    = 0x06,
    BLK_LISTENMUSIC     = 0x07,
    BLK_FRAGRANCESC     = 0x08,
    BLK_MAX             = 0x09      
};

struct DoorState{
    std::string name;
    bool status;
};

struct LightState{
    std::string name;
    bool status;
};

const uint32_t DATA_BLK_MAX_ID = static_cast<uint32_t>(BLK_MAX);

class DataBlock {
public:
    explicit DataBlock(uint32_t blkID)
      : blkID_(blkID) { }

    uint32_t GetId() const
    {
        return blkID_;
    }
private:
    uint32_t blkID_;
};

template < typename T>
class DataBlockImpl : public DataBlock {
public:
    explicit DataBlockImpl(uint32_t blkID)
      : DataBlock(blkID)
    { }

    ~DataBlockImpl() { };

    T Read()
    {
        return t_;
    }

    T& Write()
    {
        return t_;
    }
private:
    T t_;
};

#endif