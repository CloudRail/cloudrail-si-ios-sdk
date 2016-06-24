
#import <Foundation/Foundation.h>

#import "EmailProtocol.h"




@interface MailJet : NSObject <EmailProtocol>

-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;

@end
