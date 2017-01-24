
#import <Foundation/Foundation.h>
#import "CRSMSProtocol.h"

@interface CRTwilio : NSObject <CRSMSProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithAccountSid:(NSString *)accountSid authToken:(NSString *)authToken;



-(void)useAdvancedAuthentication;

@end
