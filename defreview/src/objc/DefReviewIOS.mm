#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS)
#include "DefReviewIOS.h"
#include <StoreKit/StoreKit.h>

NSString *minVersion = @"10.3";

bool DefReview_isSupported() {
    BOOL status = NO;
    if(SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(minVersion)){
        status = YES;
    }
    return status == YES;
}

void DefReview_requestReview() {
	Class SKStoreReviewController_ = NSClassFromString(@"SKStoreReviewController");
	if (SKStoreReviewController_) {
        [SKStoreReviewController_ performSelector:@selector(requestReview)];
    }
}
#endif
