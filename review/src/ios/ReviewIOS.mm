#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS)
#include "../private_review.h"
#include <StoreKit/StoreKit.h>

namespace review {

static Class getClass_SKStoreReviewController() {
    // Cache the class in a static var
    static const Class SKStoreReviewController_ = NSClassFromString(@"SKStoreReviewController");
    return SKStoreReviewController_;
}

bool isSupported() {
    Class SKStoreReviewController_ = getClass_SKStoreReviewController();
    return !!SKStoreReviewController_;
}

void requestReview() {
    Class SKStoreReviewController_ = getClass_SKStoreReviewController();
    if (SKStoreReviewController_) {
        [SKStoreReviewController_ performSelector:@selector(requestReview)];
    }
}

}//namespace

#endif
