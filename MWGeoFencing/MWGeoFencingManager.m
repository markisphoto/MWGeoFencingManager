//
//  MWGeoFencing.m
//  MWGeoFencing
//
//  Created by Mark Warnick on 5/28/13.
//  Copyright (c) 2013 Mark Warnick. All rights reserved.
//

#import "MWGeoFencingManager.h"

@interface MWGeoFencingManager ()<CLLocationManagerDelegate>

@property (retain, nonatomic) CLLocationManager *manager;
@end

@implementation MWGeoFencingManager

#pragma mark - Singleton
static id sharedInstance;

+ (void) initialize {
    // subclassing would result in an instance per class, probably not what we want
    NSAssert([MWGeoFencingManager class] == self, @"Subclassing is not welcome");
    sharedInstance = [[super alloc] initUniqueInstance];
}

+(instancetype) sharedInstance {
    return sharedInstance;
}

-(instancetype) initUniqueInstance {
    return [super init];
}

#pragma mark - Lazy load
- (CLLocationManager *)locationManager {
    if (!_manager) {
        _manager = [[CLLocationManager alloc] init];
        _manager.delegate = self;
    }
    
    return _manager;
}

#pragma mark - Public 
+(void)startMonitoringForRegion:(CLRegion *)region {
    [[MWGeoFencingManager sharedInstance].manager startMonitoringForRegion:region];
}

+(void)stopMonitoringForRegion:(CLRegion *)region {
    [[MWGeoFencingManager sharedInstance].manager stopMonitoringForRegion:region];
}

#pragma mark - CCLocationManagerDelegate
- (void)locationController:(CLLocationManager *)controller didEnterRegion:(CLRegion *)region {
    [[NSNotificationCenter defaultCenter] postNotificationName:kNotificationDidEnterRegion object:region];
}

-(void)locationController:(CLLocationManager *)controller didExitRegion:(CLRegion *)region {
    [[NSNotificationCenter defaultCenter] postNotificationName:kNotificationDidExitRegion object:region];
}

-(void)locationManager:(CLLocationManager *)manager didStartMonitoringForRegion:(CLRegion *)region {
    [[NSNotificationCenter defaultCenter] postNotificationName:kNotificationDidStartMonitoringRegion object:region];
}

- (void)locationManager:(CLLocationManager *)manager monitoringDidFailForRegion:(CLRegion *)region withError:(NSError *)error {
    [[NSNotificationCenter defaultCenter] postNotificationName:kNotificationMonitoringDidFailForRegion object:region userInfo:@{@"error": error}];
}
@end
