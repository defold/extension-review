#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS)
#include "DefReviewIOS.h"
#include <StoreKit/StoreKit.h>

static Class getClass_SKStoreReviewController() {
    // Cache the class in a static var
    static const Class SKStoreReviewController_ = NSClassFromString(@"SKStoreReviewController");
    return SKStoreReviewController_;
}

bool DefReview_isSupported() {
    Class SKStoreReviewController_ = getClass_SKStoreReviewController();
    return !!SKStoreReviewController_;
}

void DefReview_requestReview() {
    Class SKStoreReviewController_ = getClass_SKStoreReviewController();
    if (SKStoreReviewController_) {
        [SKStoreReviewController_ performSelector:@selector(requestReview)];
    }
}
#endif
