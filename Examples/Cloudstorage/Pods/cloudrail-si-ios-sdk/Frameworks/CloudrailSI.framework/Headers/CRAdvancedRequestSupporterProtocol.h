//
//  CRAdvancedRequestSupporter.h
//  CloudrailSI
//
//  Created by Patrick Stoklasa on 17.12.16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CRAdvancedRequestResponse.h"
#import "CRAdvancedRequestSpecification.h"

@protocol CRAdvancedRequestSupporterProtocol <NSObject>

- (CRAdvancedRequestResponse *) advancedRequestWithSpecification: (CRAdvancedRequestSpecification *) specification;

@end
