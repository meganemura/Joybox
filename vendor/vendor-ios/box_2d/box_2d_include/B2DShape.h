//
//  B2DShape.h
//  Box2D
//
//  Created by Juan Jose Karam on 3/6/13.
//  Copyright (c) 2013 Joybox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "B2DShapeTypes.h"

@class B2DTransform;
@class B2DRayCastOutput;
@class B2DRayCastInput;
@class B2DAABB;
@class B2DMassData;

@interface B2DShape : NSObject {
  b2Shape* shape;
  bool isTransientEntity;
}

@property (nonatomic, assign) b2Shape* shape;
@property (nonatomic, assign, readonly) B2DShapeTypes type;
@property (nonatomic, assign, readonly) NSInteger childCount;
@property (nonatomic, assign, readonly) CGFloat radius;

- (id)initWithShape:(b2Shape*)boxShape;

- (bool)testPointWithTransform:(B2DTransform *)transform andPoint:(CGPoint)point;
- (bool)rayCastWithOutput:(B2DRayCastOutput *)output
                    input:(B2DRayCastInput *)input
                transform:(B2DTransform *)transform
                 andChildren:(NSInteger)childIndex;
- (void)computeAABB:(B2DAABB *)aabb withTransform:(B2DTransform *)transform andChildIndex:(NSInteger)childIndex;
- (void)computeMass:(B2DMassData *)massData withDensity:(CGFloat)density;

@end
