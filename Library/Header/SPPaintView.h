//
//  SPLineView.h
//  simple paint app
//
//  Created by mediaCenter on 7/10/12.
//  Copyright (c) 2012 Mistral. All rights reserved.
//
// based on LineSmoothing
//
//  Created by Tony Ngo on 9/11/11.
//


typedef NS_OPTIONS(NSUInteger, VNNotesInstrumentTool) {
    kVNNotesInstrumentUnknown       = 0,
    kVNNotesInstrumentPen           = 1,
    kVNNotesInstrumentHighlighter   = 2,
    kVNNotesInstrumentEraser        = 3,
    kVNNotesInstrumentText          = 4,
};

@interface VNGraphicsState : NSObject <NSCoding, NSCopying>
@property (nonatomic, retain) UIColor *color;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, retain) UIFont *font;
@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, assign) VNNotesInstrumentTool tool;
+ (VNGraphicsState*) defaultState;
@end



#import <UIKit/UIKit.h>

@class SPPaintLayer;
#import "SPPaintLayer.h"
@interface SPPaintView : UIImageView <SPPaintLayerRenderDelegate> {
    @private
    __unsafe_unretained id <SPPaintLayerRenderDelegate> _delegate;
    CGSize _fixedPaintingSize;
}

@property (nonatomic, assign) id <SPPaintLayerRenderDelegate> delegate;
/*!
 @property paintingSize
 @abstract the size of paint area
 @discussion paintingSize is used to fix paint area with corresponding frame (ex. under paint layer). If you need to save the paint size after device rotation.
 the default value is CGSizeZero. Not working now.
 */
@property (nonatomic) CGSize paintingSize __attribute__((deprecated));
/*!
 @property backgroundImage
 @abstract background image is a content under the paint layer. It could be anything. If you no provide the background image the background color is clear color.
 */
@property (nonatomic, retain) UIImage *backgroundImage;


/*!
 @property lineColor
 @abstract Color for stroke line.
 */
@property (nonatomic, retain) UIColor *lineColor;

/*!
 @property fillColor
 @abstract color to fill the area.
 */
@property (nonatomic, retain) UIColor *fillColor;

@property (nonatomic, retain) UIColor *shadowColor;
/*!
 @property shadowSize
 @abstract size of shadow to stroke line.
 */
@property (nonatomic) CGSize shadowSize;

/*!
 @property shadowBlur
 @abstract blur of shadow to stroke line.
 */
@property (nonatomic) CGFloat shadowBlur;

/*!
 @property lineWidth
 @abstract route segment line width.
 */
@property (nonatomic, assign) CGFloat lineWidth;
/*!
 @property strokeAlpha
 @abstract route segment line color transparency.
 */
@property (nonatomic) CGFloat strokeAlpha;
/*!
 @property fillAlpha
 @abstract Route segment fill color transparency.
 */
@property (nonatomic) CGFloat fillAlpha;

/*!
 @property lineDashPattern
 @abstract The dash pattern applied to the route segment’s path when stroked.
 @discussion The dash pattern is specified as an array of floats that specify the lengths of the painted segments and unpainted segments, respectively, of the dash pattern.
 
 For example, passing an array with the values [2,3] sets a dash pattern that alternates between a 2-user-space-unit-long painted segment and a 3-user-space-unit-long unpainted segment. Passing the values [1,3,4,2] sets the pattern to a 1-unit painted segment, a 3-unit unpainted segment, a 4-unit painted segment, and a 2-unit unpainted segment.
 
 Default is NULL, a solid line.
 */
@property (nonatomic, readonly) float *lineDashPattern;
/*!
 @property lineDashPatternCount
 @abstract lineDashPattern array length.
 */
@property (nonatomic, readonly) int lineDashPatternCount;
/*!
 @method setLineDash:count:
 @abstract Sets line dash pattern array of given length.
 */
- (void)setLineDash:(float *)pattern count:(NSInteger)count;
/*!
 @property isPaintingEnable
 @abstract isPaintingEnable manages availibility of paint. If TRUE - painting is enabled, otherwise NO. If NO this property restrict touches in SPPaintView and drawing. Helpfull if SPPaintView is on the top of views hierarchy.
 */
@property (nonatomic, setter = setPaintingEnable:) BOOL isPaintingEnable;
/*!
 @property fixedPaintingSize
 @abstract fixedPaintingSize uses to fit paint area in view with scale.
 @discussion fixedPaintingSize is used to determine scale and aspect ratio of the painting area when resize of view could occure. By default paint area has the same size with SPPaintView bounds. But if you need to restrict the paint area with the size of content below the paint (paint note above image) and properly layout painting you shoud use this property.
 */
@property (nonatomic, assign)  CGSize fixedPaintingSize;

- (void) clearPainting;
- (void) undoLastPainting;
- (void) redoLastPainting;
- (void) selectInstruments:(SPTools) tool;
- (UIImage *) getPainting;
@end
