#include <stdio.h>
#include <windows.h>

enum OrderStatus 
{
    NEW,
    PROCESSING,
    SHIPPED,
    DELIVERED,
    CANCELLED
};

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    enum OrderStatus status = NEW;
    switch (status) 
    {
        case NEW:
            printf("Статус заказа: Новый\n");
            break;
        case PROCESSING:
            printf("Статус заказа: В обработке\n");
            break;
        case SHIPPED:
            printf("Статус заказа: Отправлен\n");
            break;
        case DELIVERED:
            printf("Статус заказа: Доставлен\n");
            break;
        case CANCELLED:
            printf("Статус заказа: Отменен\n");
            break;
        default:
            printf("Неизвестный статус заказа\n");
    }   
    
return 0;
}