//
//  CRBucket.h
//  CloudrailSI
//
//  Created by Felipe Cesar on 16/09/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRBucket : CRSandboxObject

@property (nonatomic) NSString * identifier;
@property (nonatomic) NSString * name;

- (instancetype) initWithName:(NSString *) name identifier:(NSString *) identifier;

@end
