//
//  VNViewController.h
//  SimplePaint
//
//  Created by Valeriy Nikitin on 3/27/13.
//  Copyright (c) 2013 Valeriy Nikitin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VNViewController : UIViewController
- (IBAction)penInstrumentsClicked:(id)sender;
- (IBAction)clearAllCliked:(id)sender;
- (IBAction)highliterInstrumentsClicked:(id)sender;
- (IBAction)eraserInstrumentsClicked:(id)sender;
- (IBAction)shadowInstrumentsClicked:(id)sender;
- (IBAction)undoClicked:(id)sender;
- (IBAction)redoClicked:(id)sender;

@end
