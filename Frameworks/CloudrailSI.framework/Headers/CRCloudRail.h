//
//  CRCloudRail.h
//  CloudrailSI
//
//  Created by Felipe Cesar on 21/07/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This static class saves the app key provided by the developer.
 */
@interface CRCloudRail : NSObject

/**
 *  return the current appKey (nil by default)
 *
 *  @return NSString
 */
+(NSString *) appKey;

/**
 *  Set the current appKey
 *
 * @param key The app key to be set.
 */
+(void) setAppKey:(NSString *) key;
@end
