//
//  CRAdvancedRequestSpecification.h
//  CloudrailSI
//
//  Created by Patrick Stoklasa on 17.12.16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "CRSandboxObject.h"

@interface CRAdvancedRequestSpecification : CRSandboxObject

@property (nonatomic) NSString * url;
@property (nonatomic) NSString * method;
@property (nonatomic) NSInputStream * body;
@property (nonatomic) NSMutableDictionary * headers;
@property (nonatomic) NSNumber * appendAuthorization;
@property (nonatomic) NSNumber * checkErrors;
@property (nonatomic) NSNumber * appendBaseUrl;

- (instancetype) initWithUrl:(NSString *) url;

#pragma mark - Different methods to set the body

- (void) setBodyAsString: (NSString *) body;
- (void) setBodyStringifyJson: (id) body;
- (void) setBodyStringifyXml: (id) body;

@end
