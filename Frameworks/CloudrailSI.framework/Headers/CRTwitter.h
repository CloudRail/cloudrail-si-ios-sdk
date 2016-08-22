
#import <Foundation/Foundation.h>
#import "CRProfileProtocol.h"
#import "CRSocialProtocol.h"

@interface CRTwitter : NSObject <CRProfileProtocol, CRSocialProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

@end
