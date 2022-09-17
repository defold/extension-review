package com.defold.review;

import android.app.Activity;
import android.os.Build;

import com.google.android.play.core.review.ReviewInfo;
import com.google.android.play.core.review.ReviewManager;
import com.google.android.play.core.review.ReviewManagerFactory;
import com.google.android.gms.tasks.Task;
import com.google.android.gms.tasks.OnCompleteListener;

public class Review {

    public static void requestReview(final Activity appActivity) {
        final ReviewManager manager = ReviewManagerFactory.create(appActivity);
            Task<ReviewInfo> request = manager.requestReviewFlow();
            request.addOnCompleteListener(new OnCompleteListener<ReviewInfo>() {
                    @Override
                    public void onComplete(Task<ReviewInfo> reviewTask){
                        if(reviewTask.isSuccessful()) {
                            ReviewInfo reviewInfo = reviewTask.getResult();

                            manager.launchReviewFlow(appActivity, reviewInfo);
                        }
                    }
            });
    }

    public static boolean isSupported(final Activity appActivity) {
        if (Build.VERSION.SDK_INT >= 21) {
            try {
                appActivity.getPackageManager().getPackageInfo("com.android.vending", 0);
                return true;
            } catch (Exception e) {
                return false;
            }
        }
        return false;
    }
}
