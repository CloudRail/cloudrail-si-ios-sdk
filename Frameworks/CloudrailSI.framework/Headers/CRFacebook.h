
#import <Foundation/Foundation.h>
#import "CRProfileProtocol.h"
#import "CRSocialProtocol.h"

@interface CRFacebook : NSObject <CRProfileProtocol, CRSocialProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

@end
