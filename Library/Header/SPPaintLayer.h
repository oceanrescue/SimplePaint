//
//  SPPaintLayer.h
//  simple paint app
//
//  Created by submarine on 7/12/12.
//  Copyright (c) 2012 Mistral. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>


@protocol SPPaintLayerRenderDelegate <NSObject>
- (void) paintCanUndo:(BOOL)flag;
- (void) paintCanRedo:(BOOL)flag;
@optional
- (void) paintLayerFinishRenderImage:(UIImage *) image;
@end

#define kPaintLayerMinDistanceSquared 4
#define kPaintLayerMaxPoints 50
#define kPaintLayerEraserInset 20
#define kPaintLayerEraserOutCircleWidth 3
#define kPaintLayerEraserInnerCircleWidth 1
//debug
#define SHOW_UPDATE_RECT 0
#define SAVE_BITMAP 0
#define SAVE_FINAL_BITMAP 0
#define LOG_CTX_BOUNDS 0
#define SHOW_DRAWING_TIME 0

typedef enum SPTools {
    kToolEraser     = 1,
    kToolPen        = 2,
    kToolHighliter  = 3,
    kToolClearAll   = 4,
    kToolUndo       = 5,
    kToolRedo       = 6
} SPTools;

@interface SPPaintLayer : CALayer {
//    BOOL _drawAsync;

    CGMutablePathRef _path;
//    CGPathRef _drawingPath;

    NSInteger _numPoints;
    CGPoint _currentPoint;
    CGPoint _previousPoint;
    CGPoint _prePreviousPoint;
        
    CGImageRef _bitmapImage;
    CGColorRef _bgroundColor;
            
    BOOL _hasStartedPath;
    BOOL _isRendering;
    
    SPTools _renderPathMode;
    __unsafe_unretained id <SPPaintLayerRenderDelegate> _renderDelegate;
    CGSize _fixedPaintingSize;
}
@property (nonatomic, assign) id <SPPaintLayerRenderDelegate> renderDelegate;
@property (nonatomic) BOOL showEraserBounds;

@property (nonatomic, retain) CGImageRef bitmapImage __attribute__ ((NSObject));
@property (nonatomic, retain) CGColorRef bGroundColor __attribute__ ((NSObject));

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

@property (nonatomic, setter = setShadowColorForLine:) CGColorRef shadowColorForLine;

/*!
 @property lineColor
 @abstract Color for stroke line.
 */
@property (nonatomic, setter = setLineColor:) CGColorRef lineColor;

/*!
 @property fillColor
 @abstract color to fill the area.
 */

@property (nonatomic, setter = setFillColor:) CGColorRef fillColor;

/*!
 @property lineWidth
 @abstract route segment line width.
 */
@property (nonatomic) CGFloat lineWidth;
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
 @property fixedPaintingSize
 @abstract fixedPaintingSize uses to fix the scale of painting width.
 @discussion fixedPaintingSize is used to determine scale of the painting width when resize of layer could occure. By default paint area has the same size with SPPaintView bounds. These bounds could be changed at any time and painting should has proper width.
 */
@property (nonatomic, assign)  CGSize fixedPaintingSize;


- (UIImage *) renderDrawingWithPath:(CGPathRef) path andBitmap:(CGImageRef)bitmap;
- (void) beginPathAtPoint:(CGPoint) point;
- (void) addNextPoint:(CGPoint) point;
- (void) endPath;
- (void) undoLast;
- (void) redoLast;
- (void) clearContent;
- (void) selectInstruments:(SPTools) tool;

@end
