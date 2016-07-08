
#import <Foundation/Foundation.h>

#import "CRProfileProtocol.h"




@interface CRSlack : NSObject <CRProfileProtocol>
-(instancetype)initWithClientId:(NSString *)clientId clientSecret: (NSString *)clientSecret;
-(instancetype)initWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret redirectUri:(NSString *)redirectUri state:(NSString *)state;
@end
