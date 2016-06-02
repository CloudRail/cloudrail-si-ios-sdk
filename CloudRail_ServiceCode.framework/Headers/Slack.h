
#import <Foundation/Foundation.h>

#import "ProfileProtocol.h"




@interface Slack : NSObject <ProfileProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;



@end
