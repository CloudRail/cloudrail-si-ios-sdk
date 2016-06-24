
#import <Foundation/Foundation.h>

#import "EmailProtocol.h"




@interface SendGrid : NSObject <EmailProtocol>


-(instancetype)initWithUsername:(NSString *)username password: (NSString *)password;
@end
