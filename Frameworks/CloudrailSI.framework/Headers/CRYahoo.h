
#import <Foundation/Foundation.h>
#import "CRProfileProtocol.h"

@interface CRYahoo : NSObject <CRProfileProtocol>

-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;

//Specific for CloudStorage Interface
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;

@end
