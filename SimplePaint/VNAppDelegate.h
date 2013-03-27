//
//  VNAppDelegate.h
//  SimplePaint
//
//  Created by Valeriy Nikitin on 3/27/13.
//  Copyright (c) 2013 Valeriy Nikitin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class VNViewController;

@interface VNAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) VNViewController *viewController;

@end
