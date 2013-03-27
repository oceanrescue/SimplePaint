//
//  VNViewController.m
//  SimplePaint
//
//  Created by Valeriy Nikitin on 3/27/13.
//  Copyright (c) 2013 Valeriy Nikitin. All rights reserved.
//

#import "VNViewController.h"
#import "SPPaintView.h"


#define UIViewAutoresizingFlexibleAll (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight |    UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin)


@interface VNViewController ()
@property (nonatomic, retain) SPPaintView *paintView;
@end

@implementation VNViewController
@synthesize paintView = _paintView;

#pragma mark  -Init
-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {

    }
    return self;
}

-(SPPaintView*) paintView {
    if (!_paintView) {
        CGRect bounds = self.view.bounds;
        bounds.origin.y = 54;
        bounds.size.height -= 108;
        SPPaintView *pView = [[SPPaintView alloc] initWithFrame:bounds];
        self.paintView = pView;
        pView.autoresizingMask = UIViewAutoresizingFlexibleAll;
        pView = nil;
    }
    return _paintView;
}
#pragma mark - View lifecycle
- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self.view addSubview:self.paintView];
    [self.view sendSubviewToBack:self.paintView];
}
-(void) viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    if (!_paintView) {
        [self.view addSubview:self.paintView];
    }
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - IBActions
- (IBAction)penInstrumentsClicked:(id)sender {
    [self.paintView selectInstruments:kToolPen];
}

- (IBAction)clearAllCliked:(id)sender {
    [self.paintView clearPainting];
}

- (IBAction)highliterInstrumentsClicked:(id)sender {
    [self.paintView selectInstruments:kToolHighliter];
}

- (IBAction)eraserInstrumentsClicked:(id)sender {
    [self.paintView selectInstruments:kToolEraser];
}

- (IBAction)shadowInstrumentsClicked:(id)sender {
    if (CGSizeEqualToSize(self.paintView.shadowSize, CGSizeZero)) {
        self.paintView.shadowSize = CGSizeMake(5, 5);
    } else {
        self.paintView.shadowSize = CGSizeZero;
    }
}

- (IBAction)undoClicked:(id)sender {
    [self.paintView undoLastPainting];
}

- (IBAction)redoClicked:(id)sender {
    [self.paintView redoLastPainting];
}

@end
