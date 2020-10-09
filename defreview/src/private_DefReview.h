#pragma once
#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_ANDROID)

namespace defReview {

bool isSupported();
void requestReview();

} // namespace

#endif
