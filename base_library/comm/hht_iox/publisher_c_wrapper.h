/*
 * @author 008196
 * @for IceOryx wait c
 * @version 0.1
 * @date 2023-06 ~ 2023-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PUBLISHER_C_KIT_H
#define PUBLISHER_C_KIT_H

// namespace HHT {
#ifdef __cplusplus
extern "C" {
#endif

//int PubClass_Pub(int evtID);

//typedef struct Publisher Publisher;

void newPubClass();

 int PubClass_Pub(int evtID);
// int PubClass_Pub(HHT::Publisher* v, int evtID);

void deletePubClass();
//void deletePubClass(HHT::Publisher* v);

//extern void PubDoipEvent(int value);

#ifdef __cplusplus
}
#endif

//}
#endif /* PUBLISHER_C_KIT_H */
