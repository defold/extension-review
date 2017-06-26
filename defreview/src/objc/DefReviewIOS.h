#pragma once
#if defined(DM_PLATFORM_IOS)

extern bool DefReview_isSupported();
extern void DefReview_requestReview();
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

#endif
