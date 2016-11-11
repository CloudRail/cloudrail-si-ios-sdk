
#import <Foundation/Foundation.h>
#import "CRPaymentProtocol.h"

@interface CRStripe : NSObject <CRPaymentProtocol>
@property (weak, nonatomic) id target;

- (instancetype)initWithSecretKey:(NSString *)secretKey;



@end
