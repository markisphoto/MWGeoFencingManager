//
//  MWGeoFencingManager.h
//  MWGeoFencing
//
//  Created by Mark Warnick on 5/28/13.
//  Copyright (c) 2013 Mark Warnick. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/** The MWGeoFencingManager encapsolates all logic pertaining to location. It will handel setting up the location manager, getting the callbacks, get ready for backgrounding or any other task related to loction.
 */

@class MWRegion;
@interface MWGeoFencingManager : NSObject

+ (instancetype)sharedInstance;

+ (void)startMonitoringForRegion:(MWRegion *)region;

+ (void)stopMonitoringForRegion:(MWRegion *)region;

// clue for improper use (produces compile time error)
+(instancetype) alloc __attribute__((unavailable("alloc not available, call sharedInstance instead")));
-(instancetype) init __attribute__((unavailable("init not available, call sharedInstance instead")));
+(instancetype) new __attribute__((unavailable("new not available, call sharedInstance instead")));


@end

