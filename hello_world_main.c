/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

static SemaphoreHandle_t xBinarySemaphore; // Declarando o semáforo global

void vTarefa1(void *pvParameters)
{
    while (1) {
        if(xSemaphoreTake(xBinarySemaphore, portMAX_DELAY)) {  // Tenta pegar o semáforo, espera indefinidamente se não estiver disponível
            printf("[Tarefa 1] Executou - Pedro Galante Branco RM 88992\n");
            vTaskDelay(pdMS_TO_TICKS(1000)); // Delay para não ficar rápido demais
            xSemaphoreGive(xBinarySemaphore); // Libera o semáforo para que outras tarefas possam usá-lo
            vTaskDelay(pdMS_TO_TICKS(50)); // Dá tempo de outras tarefas pegarem o semáforo
        }
    }
}

void vTarefa2(void *pvParameters)
{
    while (1) {
        if(xSemaphoreTake(xBinarySemaphore, portMAX_DELAY)) {  // Tenta pegar o semáforo, espera indefinidamente se não estiver disponível
            printf("[Tarefa 2] Executou - Pedro Galante Branco RM 88992\n"); // Delay para não ficar rápido demais
            vTaskDelay(pdMS_TO_TICKS(1000)); // Delay para não ficar rápido demais
            xSemaphoreGive(xBinarySemaphore); // Libera o semáforo para que outras tarefas possam usá-lo
            vTaskDelay(pdMS_TO_TICKS(50)); // Dá tempo de outras tarefas pegarem o semáforo
        }
    }
}

void vTarefa3(void *pvParameters)
{
    while (1) {
        if(xSemaphoreTake(xBinarySemaphore, portMAX_DELAY)) {  // Tenta pegar o semáforo, espera indefinidamente se não estiver disponível
            printf("[Tarefa 3] Executou - Pedro Galante Branco RM 88992\n");
            vTaskDelay(pdMS_TO_TICKS(1000)); // Delay para não ficar rápido demais
            xSemaphoreGive(xBinarySemaphore); // Libera o semáforo para que outras tarefas possam usá-lo
            vTaskDelay(pdMS_TO_TICKS(50)); // Dá tempo de outras tarefas pegarem o semáforo
        }
    }
}

void app_main(void)
{
 xBinarySemaphore = xSemaphoreCreateBinary(); // Cria um semáforo binário

    if (xBinarySemaphore == NULL) {
        printf("Falha ao criar semáforo binário\n");
        return;
    }

    // Inicialmente, semáforo não está dado, então nenhuma tarefa pode pegar
    // Pode dar o semáforo aqui se quiser começar liberado:
    xSemaphoreGive(xBinarySemaphore);
    xTaskCreate(vTarefa1, "Tarefa1", 2048, NULL, 5, NULL); // Cria a tarefa 1
    xTaskCreate(vTarefa2, "Tarefa2", 2048, NULL, 5, NULL); // Cria a tarefa 2
    xTaskCreate(vTarefa3, "Tarefa3", 2048, NULL, 5, NULL); // Cria a tarefa 3
}
