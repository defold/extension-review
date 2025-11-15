--[[
Review API
Functions and constants for interacting with review APIs
--]]

---@meta
---@diagnostic disable: lowercase-global
---@diagnostic disable: missing-return

---@class defold_api.review
review = {}

---Open native review/rating popup
function review.request_review() end

---Available only on iOS 10.3+. Android 5.0+ (API 21+) and the Google Play Store has to be installed.
---@return boolean is_supported
function review.is_supported() end