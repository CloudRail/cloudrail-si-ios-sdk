//
//  SandboxObject.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 22/04/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CRSandboxObject : NSObject

- (id) get:(NSString*) key;
- (void) setObject:(id) object forKey:(NSString*) key;

@end
