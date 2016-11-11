//
//  PersistableProtocol.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 30/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 * An interface for services that keep persistent data.
 */
@protocol CRPersistableProtocol <NSObject>

/**
 *  A method to retrieve the data from a service that is intended for persistent storage
 * @return The data of the service that should be stored persistently, e.g. access credentials
 */
- (nonnull NSString *)saveAsString;

/**
 *  Loads/restores data saved by saveAsString method into the service
 * @param savedState The persistent data that was stored
 */
- (void)loadAsString:(nonnull NSString*) savedState;

@end
