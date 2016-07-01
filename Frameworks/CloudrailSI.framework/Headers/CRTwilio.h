
#import <Foundation/Foundation.h>

#import "CRSMSProtocol.h"




@interface CRTwilio : NSObject <CRSMSProtocol>

-(instancetype)initWithAccountSid:(NSString *)accountSid authToken:(NSString *)authToken;
@end
