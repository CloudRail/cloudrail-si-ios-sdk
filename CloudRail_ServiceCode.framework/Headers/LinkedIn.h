
#import <Foundation/Foundation.h>

#import "ProfileProtocol.h"




@interface LinkedIn : NSObject <ProfileProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;



@end
