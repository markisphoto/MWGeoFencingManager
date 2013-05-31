//
//  MWGeoFencingManager.h
//  MWGeoFencing
//
//  Created by Mark Warnick on 5/28/13.
//  Copyright (c) 2013 Mark Warnick. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/** The MWGeoFencingManager encapsulates all logic pertaining to location. It will handle setting up the location manager, getting the callbacks, get ready for backgrounding or any other task related to location.
 
 ### Notification
 Instead of using a one to one delegate patter I decided to use notification so multiple parts of the app can listen for and react to the notification differently.
 */

#define kNotificationDidStartMonitoringRegion       @"kNotificationDidStartMonitoringRegion"
#define kNotificationMonitoringDidFailForRegion     @"kNotificationMonitoringDidFailForRegion" //this also passes the error in the user dictionary. use key @"error" to get the error object

#define kNotificationDidEnterRegion                 @"kNotificationDidEnterRegion"
#define kNotificationDidExitRegion                  @"kNotificationDidExitRegion"

@interface MWGeoFencingManager : NSObject

+ (instancetype)sharedInstance;

/**---------------------------------------------------------------------------------------
 * @name Interacting with Location
 *  ---------------------------------------------------------------------------------------
 */

/** Begins monitoring a given region.
 
 @param region Object with the info for a region
 */
+ (void)startMonitoringForRegion:(CLRegion *)region;

/** Ends monitoring a given region.
 
 @param region Object with the info for a region
 */
+ (void)stopMonitoringForRegion:(CLRegion *)region;

// clue for improper use (produces compile time error)
+(instancetype) alloc __attribute__((unavailable("alloc not available, call sharedInstance instead")));
-(instancetype) init __attribute__((unavailable("init not available, call sharedInstance instead")));
+(instancetype) new __attribute__((unavailable("new not available, call sharedInstance instead")));

@end

