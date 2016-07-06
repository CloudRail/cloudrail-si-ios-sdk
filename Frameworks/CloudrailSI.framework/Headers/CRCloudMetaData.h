//
//  CloudMetaData.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 02/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRCloudMetaData : CRSandboxObject

@property (nonatomic) NSString * path;
@property (nonatomic) NSString * name;
@property (nonatomic) NSNumber * size;
@property (nonatomic) NSNumber * folder;
@property (nonatomic) NSNumber * modifiedAt;
@end
