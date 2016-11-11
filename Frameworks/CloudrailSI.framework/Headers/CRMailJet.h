
#import <Foundation/Foundation.h>
#import "CREmailProtocol.h"

@interface CRMailJet : NSObject <CREmailProtocol>
@property (weak, nonatomic) id target;

- (instancetype)initWithClientId:(NSString *)clientID clientSecret:(NSString *)clientSecret;



@end
