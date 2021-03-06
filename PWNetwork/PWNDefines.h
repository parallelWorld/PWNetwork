//
//  PWNDefines.h
//  PWNetworkDemo
//
//  Created by Huang Wei on 19/01/2017.
//  Copyright © 2017 Parallel World. All rights reserved.
//

#ifndef PWNDefines_h
#define PWNDefines_h

@class PWNRequest;

NS_ASSUME_NONNULL_BEGIN

#define PWNAssert( condition, ... ) NSCAssert( (condition) , ##__VA_ARGS__)
#define PWNParameterAssert( condition ) PWNAssert( (condition) , @"Invalid parameter not satisfying: %@", @#condition)
#define PWNAssertMainThread() PWNAssert( ([NSThread isMainThread] == YES), @"Must be on the main thread")
#define PWN_SAFE_BLOCK(BlockName, ...) ({ !BlockName ? nil : BlockName(__VA_ARGS__); })


typedef NS_ENUM(NSUInteger, PWNRequestType) {
    PWNRequestNormal,
    PWNRequestUpload,
    PWNRequestDownload,
};

typedef NS_ENUM(NSUInteger, PWNHTTPMethodType) {
    PWNHTTPMethodGET = 0,
    PWNHTTPMethodPOST,
    PWNHTTPMethodHEAD,
    PWNHTTPMethodDELETE,
    PWNHTTPMethodPUT,
    PWNHTTPMethodPATCH,
};

typedef NS_ENUM(NSUInteger, PWNRequestSerializerType) {
    PWNRequestSerializerRaw,
    PWNRequestSerializerJSON,
    PWNRequestSerializerPlist,
};

typedef NS_ENUM(NSUInteger, PWNResponseSerializerType) {
    PWNResponseSerializerRaw,
    PWNResponseSerializerJSON,
    PWNResponseSerializerPlist,
    PWNResponseSerializerXML,
};

#pragma mark - Callback blocks

typedef void (^PWNProgressBlock)(NSProgress *progress);
typedef void (^PWNSuccessBlock)(id _Nullable responseObject);
typedef void (^PWNFailureBlock)(NSError * _Nullable error);
typedef void (^PWNCompletionBlock)(id _Nullable responseObject, NSError * _Nullable error);
typedef void (^PWNCancelBlock)(PWNRequest * _Nullable request);


typedef void (^PWNRequestProcessBlock)(PWNRequest *request);
typedef void (^PWNResponseProcessBlock)(PWNRequest *request, id _Nullable responseObject, NSError * _Nullable __autoreleasing *error);


NS_ASSUME_NONNULL_END

#endif /* PWNDefines_h */
