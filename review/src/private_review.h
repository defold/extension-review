#pragma once
#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_ANDROID)

namespace review {

bool isSupported();
void requestReview();

} // namespace

#endif
