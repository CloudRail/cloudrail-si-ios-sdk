
#import <Foundation/Foundation.h>
#import "CRBusinessCloudStorageProtocol.h"
#import "CRAdvancedRequestSupporterProtocol.h"
#import "CRAuthenticationDelegate.h"
@interface CRGoogleCloudPlatform : NSObject <CRBusinessCloudStorageProtocol, CRAdvancedRequestSupporterProtocol>
@property (weak, nonatomic) id target;


-(instancetype)initWithClientEmail:(NSString *)clientEmail privateKey:(NSString *)privateKey projectId:(NSString *)projectId;


-(void)useAdvancedAuthentication;
-(NSString *) saveAsString;
-(void) loadAsString:(NSString*) savedState;
-(void) setAuthDelegate:(id<CRAuthenticationDelegate>)delegate;
@end
