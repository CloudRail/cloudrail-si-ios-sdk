
#import <Foundation/Foundation.h>
#import "CRPaymentProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"

@interface CRStripe : NSObject <CRPaymentProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithSecretKey:(NSString *)secretKey;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;

@end
