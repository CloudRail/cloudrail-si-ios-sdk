
#import <Foundation/Foundation.h>

#import "CRSMSProtocol.h"




@interface CRNexmo : NSObject <CRSMSProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret;
@end
