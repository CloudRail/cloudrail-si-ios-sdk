
#import <Foundation/Foundation.h>

#import "ProfileProtocol.h"




@interface Twitter : NSObject <ProfileProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;


@end
