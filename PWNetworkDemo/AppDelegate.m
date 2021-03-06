//
//  AppDelegate.m
//  PWNetworkDemo
//
//  Created by Huang Wei on 19/01/2017.
//  Copyright © 2017 Parallel World. All rights reserved.
//

#import "AppDelegate.h"
#import "PWNetwork.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [PWNLogger sharedLogger].level = PWNLoggerLevelDebug;
    [[PWNLogger sharedLogger] startLogging];
    
    PWNDefaultCenter.generalHost = @"http://httpbin.org";
    PWNDefaultCenter.generalParameters = @{@"global_param": @"global param value"};
    PWNDefaultCenter.generalHeaders = @{@"global_header": @"global header value"};
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(networkChange:) name:PWNReachabilityDidChangeNotification object:nil];
    
    return YES;
}

- (void)networkChange:(NSNotification *)notification {
    PWNReachabilityStatus status = [[PWNReachability sharedInstance] currentReachabilityStatus];
    NSString *statusString = PWNStringFromNetworkReachabilityStatus(status);
    NSLog(@"Network changes to %@", statusString);
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
