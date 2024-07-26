#ifndef HH_OTA_INTERFACE_H
#define HH_OTA_INTERFACE_H
#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief read or write VIN/SN from DOIP
* @param [in] mode: 0：read 1: write
* @param [in] did: VIN 0xf190, SN 0xf18c
* @param [in] buffer: did data
* @return 0: successful, -1: failed
*/
int get_vin_sn(int mode,unsigned short int did,unsigned char *buffer);

#ifdef __cplusplus
}
#endif
#endif