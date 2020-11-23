#if defined(DM_PLATFORM_ANDROID)
#include "../private_review.h"
#include "jni.h"

namespace review {

const char* JAR_PATH = "com/defold/review/Review";

bool isSupported() {
    ThreadAttacher attacher;
    JNIEnv *env = attacher.env;
    jclass cls = ClassLoader(env).load(JAR_PATH);
    jmethodID method = env->GetStaticMethodID(cls, "isSupported", "(Landroid/app/Activity;)Z");
    jboolean return_value = (jboolean)env->CallStaticBooleanMethod(cls,
        method, dmGraphics::GetNativeAndroidActivity());

    return JNI_TRUE == return_value;
}

void requestReview() {
    ThreadAttacher attacher;
    JNIEnv *env = attacher.env;
    jclass cls = ClassLoader(env).load(JAR_PATH);
    jmethodID method = env->GetStaticMethodID(cls, "requestReview", "(Landroid/app/Activity;)V");
    env->CallStaticVoidMethod(cls, method, dmGraphics::GetNativeAndroidActivity());
}

}//namespace

#endif
