//
//  AppDelegate.m
//  Demo
//
//  Created by Andrea on 16/04/14.
//  Copyright (c) 2014 Fancy Pixel. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // 设置应用的statusBar属性
	[[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
	[[UIApplication sharedApplication] setStatusBarHidden:NO];
    NSDictionary *attributes = @{ NSFontAttributeName: [UIFont fontWithName:@"GillSans-Light" size:20],
								  NSForegroundColorAttributeName: [UIColor whiteColor]};
	[[UINavigationBar appearance] setTitleTextAttributes:attributes];
	[[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];

    return YES;
}

@end
