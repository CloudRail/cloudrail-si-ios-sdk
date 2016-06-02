
#import <Foundation/Foundation.h>

#import "CloudStorageProtocol.h"




@interface Box : NSObject <CloudStorageProtocol>

-(void) initializeServiceCode;
-(instancetype)initWithClientId:(NSString *) clientId clientSecret:(NSString *) clientSecret;


@end
