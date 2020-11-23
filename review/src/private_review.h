#pragma once
#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_ANDROID)

namespace ext_review {

bool isSupported();
void requestReview();

} // namespace

#endif
