//
//  MWRegion.h
//  MWGeoFencing
//
//  Created by Mark Warnick on 5/29/13.
//  Copyright (c) 2013 Mark Warnick. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
@class MWRegion;
typedef void (^didStartMonitoringRegionBlock)(MWRegion *region);
typedef void (^didEnterRegionBlock)(MWRegion *region);
typedef void (^didExitRegionBlock)(MWRegion *region);

@interface MWRegion : CLRegion

@property (nonatomic, copy) didStartMonitoringRegionBlock startedMonitoringRegion;

@property (nonatomic, copy) didEnterRegionBlock enteredRegion;

@property (nonatomic, copy) didExitRegionBlock exitedRegion;
@end
