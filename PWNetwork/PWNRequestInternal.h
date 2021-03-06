//
//  PWNRequestInternal.h
//  PWNetworkDemo
//
//  Created by Huang Wei on 19/01/2017.
//  Copyright © 2017 Parallel World. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "PWNDefines.h"
#import "PWNRequest.h"

@class PWNUploadFormData;

NS_ASSUME_NONNULL_BEGIN

@interface PWNRequest ()

@property (nonatomic, copy, nullable) NSString *identifier;

@property (nonatomic, copy, nullable) PWNSuccessBlock successBlock;

@property (nonatomic, copy, nullable) PWNFailureBlock failureBlock;

@property (nonatomic, copy, nullable) PWNProgressBlock progressBlock;

@property (nonatomic, copy, nullable) PWNCompletionBlock completionBlock;

@property (nonatomic, strong, nullable) NSURLSessionTask *task;

@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *entireParameters;

@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *entireHeaders;

@property (nonatomic, copy, nullable) NSString *downloadFilePath;

@property (nonatomic, strong, nullable) NSMutableArray<PWNUploadFormData *> *uploadFormDatas;

- (void)m_cleanCallbackBlocks;

@end

NSString *PWNStringForRequestType(PWNRequestType type);

NS_ASSUME_NONNULL_END
