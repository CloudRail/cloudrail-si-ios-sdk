
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"

@interface CRMailJet : NSObject <CREmailProtocol>

-(instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret;



@end
