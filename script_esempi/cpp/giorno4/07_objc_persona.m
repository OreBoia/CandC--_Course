// NOTA: richiede un compilatore Apple/clang con framework Foundation (tipicamente
// solo su macOS). Non compilabile/eseguibile su questa macchina Linux: incluso
// come materiale di lettura per l'aula (vedi giorno4_cpp_stl_objc.md, sezione 4).
//
// Compilazione su macOS:
//   clang -framework Foundation 07_objc_persona.m -o persona

#import <Foundation/Foundation.h>

@interface Persona : NSObject
@property NSString *nome;
- (void)saluta;
@end

@implementation Persona
- (void)saluta {
    NSLog(@"Ciao, sono %@", self.nome);
}
@end

int main() {
    @autoreleasepool {
        Persona *p = [[Persona alloc] init];   // creazione oggetto
        p.nome = @"Maria";
        [p saluta];                            // INVIO di un messaggio
    }
    return 0;
}
