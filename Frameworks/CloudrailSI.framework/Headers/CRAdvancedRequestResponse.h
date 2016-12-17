//
//  CRAdvancedRequestResponse.h
//  CloudrailSI
//
//  Created by Patrick Stoklasa on 17.12.16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRAdvancedRequestResponse : CRSandboxObject

@property (nonatomic) NSInputStream * body;
@property (nonatomic) NSDictionary * headers;
@property (nonatomic) NSNumber * status;
@property (nonatomic) NSString * _stringBody;

#pragma mark - Body transformation methods

- (NSString *) bodyAsString;
- (id) bodyJsonParsed;
- (NSDictionary *) bodyXmlParsed;

@end
