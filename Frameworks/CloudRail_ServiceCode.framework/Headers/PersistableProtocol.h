//
//  PersistableProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 30/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PersistableProtocol <NSObject>


/**
 * @brief A method to retrieve the data from a service that is intended for persistent storage
 * @return The data of the service that should be stored persistently, e.g. access credentials
 */
-(NSString *) saveAsString;

/**
 * @brief Loads/restores data saved by {@link #saveAsString() saveAsString} into the service
 * @param savedState The persistent data that was stored
 * @throws ParseException
 */
-(void) loadAsString:(NSString*) savedState;

@end
