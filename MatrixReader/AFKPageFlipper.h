//
//  AFKPageFlipper.h
//  AFKPageFlipper
//
//  Created by Marco Tabini on 10-10-11.
//  Copyright 2010 AFK Studio Partnership. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>


@class AFKPageFlipper;


@protocol AFKPageFlipperDataSource

- (NSInteger) numberOfPagesForPageFlipper:(AFKPageFlipper *) pageFlipper;
- (UIView *) viewForPage:(NSInteger) page inFlipper:(AFKPageFlipper *) pageFlipper;

@end

@protocol AFKPageFlipperDelegate <NSObject>

@optional
- (void)pageFlipper:(AFKPageFlipper *)pageFlipper didFlipToPage:(NSInteger)page;

@end


typedef enum {
	AFKPageFlipperDirectionLeft,
	AFKPageFlipperDirectionRight,
} AFKPageFlipperDirection;



@interface AFKPageFlipper : UIView {
	NSObject <AFKPageFlipperDataSource> *dataSource;
	NSInteger currentPage;
	NSInteger numberOfPages;
    
    // For BookReader
    NSInteger currentPDFPage;
    
    NSInteger currentEPubPage;
    NSInteger currentEPubChapter;
    NSInteger pageMode;
	
	UIView *currentView;
	UIView *nextView;
	
	CALayer *backgroundAnimationLayer;
	CALayer *flipAnimationLayer;
	
	AFKPageFlipperDirection flipDirection;
	float startFlipAngle;
	float endFlipAngle;
	float currentAngle;

	BOOL setNextViewOnCompletion;
	BOOL animating;
	
	BOOL disabled;
    
    NSMutableArray *chapters;
}

@property (nonatomic,retain) NSObject <AFKPageFlipperDataSource> *dataSource;
@property (nonatomic, assign) id <AFKPageFlipperDelegate> delegate;
@property (nonatomic,assign) NSInteger currentPage;
//For BookReader
@property (nonatomic, assign) NSInteger currentPDFPage;

@property (nonatomic, assign) NSInteger currentEPubPage;
@property (nonatomic, assign) NSInteger currentEPubChapter;
@property (nonatomic, assign) NSInteger pageMode;

@property (nonatomic, retain) UITapGestureRecognizer *tapRecognizer;
@property (nonatomic, retain) UIPanGestureRecognizer *panRecognizer;
//For BookReader
@property (nonatomic, retain) UIPinchGestureRecognizer *pinchRecognizer;

@property (nonatomic,assign) BOOL disabled;
@property (nonatomic, retain) NSMutableArray *chapters;

- (void) setCurrentPage:(NSInteger) value animated:(BOOL) animated;

@end
