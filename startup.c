#include <stdint.h>

#define SRAM_START 0x20000000U                         /* Inicio da SRAM CORTEX-M */
#define SRAM_SIZE  (128U * 1024U)                       /* Tamanho SRAM STM32F411 128K */
#define SRAM_END   ((SRAM_START) + (SRAM_SIZE))         /* Final da SRAM STM32F411 */

#define STACK_START SRAM_END                            /* Início da Stack */

/* Aqui inicializamos as funções de interrupção para os vetores de interrupção , e utilizamos o __attribute__ alias para que ela seja
usada como um apelido para a função "default_hanlder" e não haja a necessidade de criarmos uma função para cada caso não formos tratar
cada uma das excessões de maneira distinta, e utilizamos o atributo weak para que caso seja necessário criar uma função específica para
uma excessão, essa nova função sobrescreve a "default_handler" na sua chamada*/
void reset_handler      (void);
void nmi_handler        (void) __attribute__ ((weak, alias("default_handler")));
void hardfault_hanlder  (void) __attribute__ ((weak, alias("default_handler")));
void memmanage_handler  (void) __attribute__ ((weak, alias("default_handler")));
void busfault_handler   (void) __attribute__ ((weak, alias("default_handler")));
void usagefault_handler (void) __attribute__ ((weak, alias("default_handler")));
void svc_handler        (void) __attribute__ ((weak, alias("default_handler")));
void debugmon_handler   (void) __attribute__ ((weak, alias("default_handler")));
void pendsv_handler     (void) __attribute__ ((weak, alias("default_handler")));
void systick_handler    (void) __attribute__ ((weak, alias("default_handler")));



uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
    STACK_START,                                        /* 0x0000 0000 */
    (uint32_t)reset_handler,                            /* 0x0000 0004 */
    (uint32_t)nmi_handler,                              /* 0x0000 0008 */
    (uint32_t)hardfault_hanlder,                        /* 0x0000 000c */
    (uint32_t)memmanage_handler,                        /* 0x0000 0010 */
    (uint32_t)busfault_handler,                         /* 0x0000 0014 */
    (uint32_t)usagefault_handler,                       /* 0x0000 0018 */
    0,                                                  /* 0x0000 001c */
    0,                                                  /* 0x0000 0020 */
    0,                                                  /* 0x0000 0024 */
    0,                                                  /* 0x0000 0028 */
    (uint32_t)svc_handler,                              /* 0x0000 002c */
    (uint32_t)debugmon_handler,                         /* 0x0000 0030 */
    0,                                                  /* 0x0000 0034 */
    (uint32_t)pendsv_handler,                           /* 0x0000 0038 */
    (uint32_t)systick_handler,                          /* 0x0000 003c */
};


/* Definindo a função reset handler */
void reset_handler(void)
{

}

/* Definindo a função  default_handler*/
void default_handler(void)
{
    while(1){};
}

