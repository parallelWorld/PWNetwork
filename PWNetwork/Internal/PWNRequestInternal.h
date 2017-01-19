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

@interface PWNRequest ()

@property (nonatomic, assign) NSUInteger identifier;

@property (nonatomic, copy, nullable) PWNSuccessBlock successBlock;

@property (nonatomic, copy, nullable) PWNFailureBlock failureBlock;

@property (nonatomic, copy, nullable) PWNProgressBlock progressBlock;

@property (nonatomic, copy, nullable) PWNCompletionBlock completionBlock;

- (void)m_cleanCallbackBlocks;

@end
