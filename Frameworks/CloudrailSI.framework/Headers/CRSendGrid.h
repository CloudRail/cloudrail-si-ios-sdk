
#import <Foundation/Foundation.h>

#import "CREmailProtocol.h"




@interface CRSendGrid : NSObject <CREmailProtocol>

-(instancetype)initWithUsername:(NSString *)username password:(NSString *)password;
@end
