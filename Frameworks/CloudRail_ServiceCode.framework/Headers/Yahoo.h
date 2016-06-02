
#import <Foundation/Foundation.h>

#import "ProfileProtocol.h"




@interface Yahoo : NSObject <ProfileProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;

@end
