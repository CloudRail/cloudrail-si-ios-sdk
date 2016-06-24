
#import <Foundation/Foundation.h>

#import "SMSProtocol.h"




@interface Twilio : NSObject <SMSProtocol>

-(instancetype)initWithAccountSid:(NSString *)accountSid authToken: (NSString *)authToken;

@end
