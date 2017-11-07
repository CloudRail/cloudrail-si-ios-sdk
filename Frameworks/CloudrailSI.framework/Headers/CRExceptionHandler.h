//
//  ExceptionHandler.h
//  CloudrailSI
//
//  Created by Felipe Cesar on 27/07/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CRExceptionHandler : NSObject
+ (BOOL)catchException:(void(^)(void))tryBlock error:(__autoreleasing NSError **)error;

@end
