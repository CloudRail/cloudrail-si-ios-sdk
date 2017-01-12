
#import <Foundation/Foundation.h>
#import "CRSMSProtocol.h"

@interface CRNexmo : NSObject <CRSMSProtocol>
@property (weak, nonatomic) id target;

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret;



@end
