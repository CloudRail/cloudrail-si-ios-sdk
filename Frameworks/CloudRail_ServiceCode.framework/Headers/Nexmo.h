
#import <Foundation/Foundation.h>

#import "SMSProtocol.h"




@interface Nexmo : NSObject <SMSProtocol>

-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;

@end
