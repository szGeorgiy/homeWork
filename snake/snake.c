#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

// Константы цвета
#define RED 1
#define BLUE 2
#define GREEN 3
#define CYAN 4

// Константы сложности
#define EASE 0
#define MEDIUM 1
#define HARD 2 

// Константы победы
#define APPLE_TO_WIN 10

const int SPEED[] = {0, 150000, 100000, 50000};

/* Игровые режимы*/
char game_mod[] = {'e', '1', '2', '3', '4', '5'};

// Перечисление для направлений змейки
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;


void draw_default_screen(char **screen, int height) {
    for (int i = 0; i < height; i++) {
        mvaddstr(i, 0, screen[i]);
    }
}

int startMenu(char **screen, int height, int width) {
    int ret;
    char c = 0;
    int tmp;

    draw_default_screen(screen, height);
    attron(COLOR_PAIR(3));
    
    const char *select = "Select game mod";
    const char *game_mod_1 = "1 - Ease single mod";
    const char *game_mod_2 = "2 - Normal single mod";
    const char *game_mod_3 = "3 - HARD single mod";
    const char *game_mod_4 = "4 - Two pleyers mod";
    const char *game_mod_5 = "5 - Battle with AI";
    const char *to_exit = "Press 'e' to exit";
    int x_width_1 = (width - strlen(select)) / 2;
    int x_width_2 = (width - strlen(game_mod_1)) / 2;
    int x_width_3 = (width - strlen(game_mod_2)) / 2;
    int x_width_4 = (width - strlen(game_mod_3)) / 2;
    int x_width_5 = (width - strlen(game_mod_4)) / 2;
    int x_width_6 = (width - strlen(game_mod_5)) / 2;
    int x_width_7 = (width - strlen(to_exit)) / 2;
    int y_heigth = height / 2;
    mvprintw(y_heigth - 4, x_width_1, "%s", select);
    mvprintw(y_heigth - 2, x_width_2, "%s", game_mod_1);
    mvprintw(y_heigth - 1, x_width_2, "%s", game_mod_2);
    mvprintw(y_heigth, x_width_2, "%s", game_mod_3);
    mvprintw(y_heigth + 1, x_width_2, "%s", game_mod_4);
    mvprintw(y_heigth + 2, x_width_2, "%s", game_mod_5);
    mvprintw(y_heigth + 4, x_width_7, "%s", to_exit);
    attroff(COLOR_PAIR(3));
    refresh();

    tmp = 1;
    while (tmp){
        c = getch();
        for( int i = 0; i < strlen(game_mod); i++){
            if (c == game_mod[i]){
                tmp = 0;
                break;
            }
        }
    }

    if (c == 'e'){
        return 0;
    }

    ret = c - '0';
    return ret;
}

void init_screen() {
    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    curs_set(FALSE);
    timeout(0);
}

void create_default_screen(char **screen, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                screen[i][j] = '#';
            } else {
                screen[i][j] = ' ';
            }
        }
        screen[i][width] = '\0';
    }
}

void draw_death_screen(char **screen, int width, int height) {
    draw_default_screen(screen, height);
    
    const char *message1 = "GAME OVER";
    const char *message2 = "Press 'e' to exit";
    int message1_len = strlen(message1);
    int message2_len = strlen(message2);
    int x_position_1 = (width - message1_len) / 2; // Вычисляем координату x для центра
    int x_position_2 = (width - message2_len) / 2; 
    
    mvprintw(height / 2, x_position_1, "%s", message1); // Выводим сообщение по центру
    mvprintw(height / 2 + 1, x_position_2, "%s", message2);
    refresh(); // Обновляем экран
}

void draw_win_screen(char **screen, int width, int height, int color) {
    draw_default_screen(screen, height);
    
    const char *red = "RED";
    const char *blue = "BLUE";
    const char *message1 = " SNAKE WIN";
    const char *message2 = "Press 'e' to exit";

    int message2_len = strlen(message2);
    int message1_len = strlen(message1);
    if (color == 1){
        message1_len += strlen(red);
    }
    if (color == 2){
        message1_len += + strlen(red);
    }
    int x_position_1 = (width - message1_len) / 2; // Вычисляем координату x для центра
    int x_position_2 = (width - message2_len) / 2; 
    
    if (color == 1){
        mvprintw(height / 2, x_position_1, "%s%s", red, message1); // Выводим сообщение по центру
    }
    if (color == 2){
        mvprintw(height / 2, x_position_1, "%s%s", blue, message1); // Выводим сообщение по центру
    }
    mvprintw(height / 2 + 1, x_position_2, "%s", message2);
    refresh(); // Обновляем экран
}

void draw_lose_screen(char **screen, int width, int height, int color) {
    draw_default_screen(screen, height);
    
    const char *red = "RED";
    const char *blue = "BLUE";
    const char *message1 = " SNAKE LOSE";
    const char *message2 = "Press 'e' to exit";

    int message2_len = strlen(message2);
    int message1_len = strlen(message1);
    if (color == 1){
        message1_len += strlen(red);
    }
    if (color == 2){
        message1_len += + strlen(red);
    }
    int x_position_1 = (width - message1_len) / 2; // Вычисляем координату x для центра
    int x_position_2 = (width - message2_len) / 2; 
    
    if (color == 1){
        mvprintw(height / 2, x_position_1, "%s%s", red, message1); // Выводим сообщение по центру
    }
    if (color == 2){
        mvprintw(height / 2, x_position_1, "%s%s", blue, message1); // Выводим сообщение по центру
    }
    mvprintw(height / 2 + 1, x_position_2, "%s", message2);
    refresh(); // Обновляем экран
}

typedef struct {
    int x;
    int y;
    int length;
    int capacity;
    int (*tail)[2];
    Direction dir;  // Поле для направления движения
} Snake;


void init_snake(Snake* snake, int startX, int startY) {
    snake->x = startX; // Установите координаты головы
    snake->y = startY; // Установите координаты головы
    snake->length = 3; // Изменяем начальную длину на 3
    snake->capacity = 3;
    snake->tail = malloc(snake->capacity * sizeof(*snake->tail));
    snake->dir = UP; // Начальное направление (например, вверх)

    // Инициализируем хвост
    for (int i = 0; i < snake->length; i++) {
        snake->tail[i][0] = startX;          // X-координата всегда такая же
        snake->tail[i][1] = startY + i + 1; // Начинать с startY + 1 для хвоста
    }
}

void grow_snake(Snake* snake) {
    if (snake->length >= snake->capacity) {
        snake->capacity *= 2; 
        snake->tail = realloc(snake->tail, snake->capacity * sizeof(*snake->tail));
    }
    if (snake->length > 0) {
        snake->tail[snake->length][0] = snake->tail[snake->length - 1][0];
        snake->tail[snake->length][1] = snake->tail[snake->length - 1][1];
    }
    snake->length++;
}

void draw_snake(Snake* snake, int color) {
    attron(COLOR_PAIR(color));
    // Затем отрисовываем хвост
    for (int i = 0; i < snake->length; i++) {
       if (i < snake->capacity) { // Проверка на выход за пределы массива
           mvprintw(snake->tail[i][1], snake->tail[i][0], "0");
       }
    }

    // Сначала отрисовываем голову
    mvprintw(snake->y, snake->x, "@");
    attroff(COLOR_PAIR(color));
}

void update_snake(Snake* snake) {

    // Сдвигаем хвост
    for (int i = snake->length - 1; i > 0; i--) {
        snake->tail[i][0] = snake->tail[i - 1][0]; // перемещаем хвост
        snake->tail[i][1] = snake->tail[i - 1][1];
    }
    
    // Обновляем первую позицию хвоста на текущие координаты головы
    snake->tail[0][0] = snake->x;
    snake->tail[0][1] = snake->y;
}

void move_snake(Snake* snake) {
    switch (snake->dir) {
        case UP:    snake->y--; break;
        case DOWN:  snake->y++; break;
        case LEFT:  snake->x--; break;
        case RIGHT: snake->x++; break;
    }
}

void take_command(int comand, Snake *snake_uldr, Snake *snake_wasd){
    const int uldr[] = {KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT};
    const int wasd[] = {'w', 'a', 's', 'd', 'W', 'A', 'S', 'D'};
    int uldr_to_snake = 0;
    int wasd_to_snake = 0;
    for (int i = 0; i < 4; i++){
        if (comand == uldr[i]){
            uldr_to_snake = 1;
            break;
        }
    }
    for (int i = 0; i < 8; i++){
        if (comand == wasd[i]){
            wasd_to_snake = 1;
            break;
        }
    }
    if (snake_uldr == NULL){
        uldr_to_snake = 0;
    }
    if (snake_wasd == NULL){
        wasd_to_snake = 0;
    }
    if (uldr_to_snake){
        switch (comand) {
            case KEY_UP:    if (snake_uldr->dir != DOWN) snake_uldr->dir = UP; break;
            case KEY_LEFT:  if (snake_uldr->dir != RIGHT) snake_uldr->dir = LEFT; break;
            case KEY_DOWN:  if (snake_uldr->dir != UP) snake_uldr->dir = DOWN; break;
            case KEY_RIGHT: if (snake_uldr->dir != LEFT) snake_uldr->dir = RIGHT; break;
        }
    }
    if (wasd_to_snake){
        switch (comand) {
            case 'W': if (snake_wasd->dir != DOWN) snake_wasd->dir = UP; break;
            case 'A': if (snake_wasd->dir != RIGHT) snake_wasd->dir = LEFT; break;
            case 'S': if (snake_wasd->dir != UP) snake_wasd->dir = DOWN; break;
            case 'D': if (snake_wasd->dir != LEFT) snake_wasd->dir = RIGHT; break;
            case 'w': if (snake_wasd->dir != DOWN) snake_wasd->dir = UP; break;
            case 'a': if (snake_wasd->dir != RIGHT) snake_wasd->dir = LEFT; break;
            case 's': if (snake_wasd->dir != UP) snake_wasd->dir = DOWN; break;
            case 'd': if (snake_wasd->dir != LEFT) snake_wasd->dir = RIGHT; break;
        }
    }
}

int win_condition(Snake *snake){
    if (snake->length >= APPLE_TO_WIN){
        return 1;
    }
    return 0;
}

/**
 * Яблоки
*/

typedef struct {
    int apple_on_field;
    int x; // Координата x
    int y; // Координата y
} Apple;

// Функция для добавления яблока в случайном месте, не попадающем на змейку
void add_apple(Apple *apple, Snake *snake, int width, int height) {
    if (apple->apple_on_field == 0){
        apple->apple_on_field = 1;
        
        int valid_position = 0;

        while (!valid_position) {
            // Генерируем случайные координаты для яблока
            apple->x = rand() % (width-2) + 1;
            apple->y = rand() % (height-2) + 1;

            // Проверяем, что координаты яблока не накладываются на змею
            valid_position = 1; // Предположительно, позиция хороша
            
            for (int i = 0; i < snake->length; i++) {
                if (apple->x == snake->tail[i][0] && apple->y == snake->tail[i][1]) {
                    valid_position = 0; // Найдена коллизия с телом змейки
                    break; // Выходим из цикла, пробуем другую позицию
                }
            }
        }
    }
}

void draw_apple(Apple *apple) {
    if (apple->apple_on_field){
        attron(COLOR_PAIR(GREEN));
        mvprintw(apple->y, apple->x, "0"); // Отрисовка яблока с символом 'A'
        attroff(COLOR_PAIR(GREEN));
        refresh();
    }
}

// Функция для проверки столкновения с телом змейки
bool is_collision_with_self(Snake *snake, int new_x, int new_y) {
    for (int i = 0; i < snake->length; i++) {
        if (snake->tail[i][0] == new_x && snake->tail[i][1] == new_y) {
            return true;
        }
    }
    return false;
}

void update_ai_direction(Snake *ai_snake, Apple *apple, int width, int height) {
    int ai_x = ai_snake->x;
    int ai_y = ai_snake->y;
    int apple_x = apple->x;
    int apple_y = apple->y;

    // Сначала создаем массив для хранения всех возможных направлений
    Direction possible_directions[4];
    int count = 0;

    // Проверяем каждое направление
    if (ai_x < width - 1 && !is_collision_with_self(ai_snake, ai_x + 1, ai_y)) {
        possible_directions[count++] = RIGHT;
    }
    if (ai_x > 0 && !is_collision_with_self(ai_snake, ai_x - 1, ai_y)) {
        possible_directions[count++] = LEFT;
    }
    if (ai_y < height - 1 && !is_collision_with_self(ai_snake, ai_x, ai_y + 1)) {
        possible_directions[count++] = DOWN;
    }
    if (ai_y > 0 && !is_collision_with_self(ai_snake, ai_x, ai_y - 1)) {
        possible_directions[count++] = UP;
    }

    // Логика выбора направления: адаптивно выбираем ближайшее к яблоку
    int best_direction = -1;
    int best_distance = width + height - 2; // максимальная возможная дистанция в сетке

    for (int i = 0; i < count; i++) {
        int direction_x = ai_x;
        int direction_y = ai_y;

        // Имитируем движение в выбранном направлении
        switch (possible_directions[i]) {
            case RIGHT: direction_x++; break;
            case LEFT: direction_x--; break;
            case DOWN: direction_y++; break;
            case UP: direction_y--; break;
        }

        // Рассчитываем расстояние до яблока
        int distance_to_apple = abs(direction_x - apple_x) + abs(direction_y - apple_y);
        
        // Проверяем наилучшее направление
        if (distance_to_apple < best_distance) {
            best_distance = distance_to_apple;
            best_direction = possible_directions[i];
        }
    }

    // Если найдено безопасное наилучшее направление, устанавливаем его
    if (best_direction != -1) {
        ai_snake->dir = best_direction;
    }
}

/**
 * Колизии
*/

/* Проверка коллизии змея-экран */
int field_collision(Snake *snake, int width, int height) {
    // Проверяем, вышла ли голова змейки за границы игрового поля
    if (snake->x <= 0 || snake->x >= (width -1) || snake->y <= 0 || snake->y >= (height-1)) {
        return 1; // Столкновение с границей
    }
    return 0; // Нет столкновения
}

/* Проверка коллизии змея-хвост */
int self_collision(Snake *snake) {
    // Проверяем, сталкивается ли голова змеи с ее телом
    for (int i = 1; i < snake->length; i++) {
        if (snake->tail[i][0] == snake->x && snake->tail[i][1] == snake->y) {
            return 1; // Столкновение с телом
        }
    }
    return 0; // Нет столкновения
}

/* Проверка коллизии змея-яблоко */
int apple_collision(Snake *snake, Apple *apple){
    if ((snake->x == apple->x) && (snake->y == apple->y)){
        return 1;
    }
    return 0;
}

/* Проверка коллизии змея-змея */
int snake_collision(Snake *head_snake, Snake *tail_snake){
    for (int i = 0; i < tail_snake->length; i++){
        if (head_snake->x == tail_snake->tail[i][0] && head_snake->y == tail_snake->tail[i][1]){
            return 1;
        }
    }
    return 0;
}

int main() {
    int width;
    int height;

    init_screen();
    getmaxyx(stdscr, height, width);

    char **screen = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        screen[i] = malloc((width + 1) * sizeof(char));
    }

    create_default_screen(screen, width, height);
    int game_mod = startMenu(screen, height, width);

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    clear();

    if (game_mod >= 1 && game_mod <= 3) {
        /**
         * Однопользоваетльский режим
        */
        /* Init змейки */
        Snake snake1;
        init_snake(&snake1, width / 2, height / 2);
        /* Init яблока */
        Apple apple = {.apple_on_field = 0};
        

        while (1) {
            int input = getch();
            if (input == 'e') {
                break;
            }

            /* Создаём и рисуем яблоко */
            add_apple(&apple, &snake1, width, height);

            // Обработка ввода для смены направления
            take_command(input, &snake1, &snake1);

            // Двигаем змейку
            move_snake(&snake1);
            
            // Обновляем позицию хвоста
            update_snake(&snake1);

            // Проверка на столкновение с границей игрового поля
            if (field_collision(&snake1, width, height)) {
                draw_death_screen(screen, width, height);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break; // Завершаем игру, если произошло столкновение
            }

            // Проверка на столкновение с собой
            if (self_collision(&snake1)){
                draw_death_screen(screen, width, height);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            // Проверка на столкновение в яблоком
            if (apple_collision(&snake1, &apple)){
                apple.apple_on_field = 0;
                grow_snake(&snake1);
            }

            // Проверка условий победы
            if (win_condition(&snake1)){
                draw_win_screen(screen, width, height, 1);
                refresh();
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            
            draw_default_screen(screen, height);
            draw_apple(&apple);
            draw_snake(&snake1, RED);
            refresh();
            usleep(SPEED[game_mod]); // задержка для замедления игры
        }
        free(snake1.tail);
    } else if(game_mod == 4) {
        /**
         * Многопользовательский режим
        */
        // /* Init змейки */
        Snake snake1;
        Snake snake2;
        init_snake(&snake1, width / 4, height / 2);
        init_snake(&snake2, 3 * width / 4, height/2);
        
        /* Init яблока */
        Apple apple = {.apple_on_field = 0};
        
        /* Игровой цикл */
        while (1){
            int input = getch();
            if (input == 'e') {
                break;
            }

            /* Создаём и рисуем яблоко */
            add_apple(&apple, &snake1, width, height);

            // Обработка ввода для смены направления
            take_command(input, &snake2, &snake1);

            // Двигаем змеек
            move_snake(&snake1);
            move_snake(&snake2);

            // Обновляем позицию хвоста
            update_snake(&snake1);
            update_snake(&snake2);

            // Проверка на столкновение с границей игрового поля
            if (field_collision(&snake1, width, height)) {
                draw_lose_screen(screen, width, height, 1);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break; // Завершаем игру, если произошло столкновение
            }
            if (field_collision(&snake2, width, height)) {
                draw_lose_screen(screen, width, height, 2);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break; // Завершаем игру, если произошло столкновение
            }
            // Проверка на столкновение с собой
            if (self_collision(&snake1)){
                draw_lose_screen(screen, width, height, 1);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }
            if (self_collision(&snake2)){
                draw_lose_screen(screen, width, height, 2);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            // Проверка на столкновение в яблоком
            if (apple_collision(&snake1, &apple)){
                apple.apple_on_field = 0;
                grow_snake(&snake1);
            }
            if (apple_collision(&snake2, &apple)){
                apple.apple_on_field = 0;
                grow_snake(&snake2);
            }

            // Проверка на столкновение со змейкой
            if (snake_collision(&snake2, &snake1)){
                draw_lose_screen(screen, width, height, 2);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }
            if (snake_collision(&snake1, &snake2)){
                draw_lose_screen(screen, width, height, 1);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            // Проверка условий победы
            if (win_condition(&snake1)){
                draw_win_screen(screen, width, height, 1);
                refresh();
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }
            if (win_condition(&snake2)){
                draw_win_screen(screen, width, height, 2);
                refresh();
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }


            
            draw_default_screen(screen, height);
            draw_apple(&apple);
            draw_snake(&snake1, RED);
            draw_snake(&snake2, BLUE);
            refresh();
            usleep(SPEED[1]); // задержка для замедления игры

        }
        free(snake1.tail);
        free(snake2.tail);
    }
    if(game_mod == 5) {
        /**
         * Игра с искусственным интелектом (искусственным - да, интеллектом - нет)
        */
        // /* Init змейки */
        Snake snake1;
        Snake snake2;
        init_snake(&snake1, width / 4, height / 2);
        init_snake(&snake2, 3 * width / 4, height/2);
        
        /* Init яблока */
        Apple apple = {.apple_on_field = 0};
        
        /* Игровой цикл */
        while (1){
            int input = getch();
            if (input == 'e') {
                break;
            }

            /* Создаём и рисуем яблоко */
            add_apple(&apple, &snake1, width, height);

            // Обработка ввода для смены направления
            take_command(input, &snake1, &snake1);
            update_ai_direction(&snake2, &apple, width, height);

            // Двигаем змеек
            move_snake(&snake1);
            move_snake(&snake2);

            // Обновляем позицию хвоста
            update_snake(&snake1);
            update_snake(&snake2);

            // Проверка на столкновение с границей игрового поля
            if (field_collision(&snake1, width, height)) {
                draw_lose_screen(screen, width, height, 1);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break; // Завершаем игру, если произошло столкновение
            }
            if (field_collision(&snake2, width, height)) {
                draw_lose_screen(screen, width, height, 2);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break; // Завершаем игру, если произошло столкновение
            }
            // Проверка на столкновение с собой
            if (self_collision(&snake1)){
                draw_lose_screen(screen, width, height, 1);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }
            if (self_collision(&snake2)){
                draw_lose_screen(screen, width, height, 2);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            // Проверка на столкновение в яблоком
            if (apple_collision(&snake1, &apple)){
                apple.apple_on_field = 0;
                grow_snake(&snake1);
            }
            if (apple_collision(&snake2, &apple)){
                apple.apple_on_field = 0;
                grow_snake(&snake2);
            }

            // Проверка на столкновение со змейкой
            if (snake_collision(&snake2, &snake1)){
                draw_lose_screen(screen, width, height, 2);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }
            if (snake_collision(&snake1, &snake2)){
                draw_lose_screen(screen, width, height, 1);
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            // Проверка условий победы
            if (win_condition(&snake1)){
                draw_win_screen(screen, width, height, 1);
                refresh();
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }
            if (win_condition(&snake2)){
                draw_win_screen(screen, width, height, 2);
                refresh();
                while (1){
                    if (getch() == 'e'){
                        break;
                    }
                }
                break;
            }

            
            draw_default_screen(screen, height);
            draw_apple(&apple);
            draw_snake(&snake1, RED);
            draw_snake(&snake2, BLUE);
            refresh();
            usleep(SPEED[1]); // задержка для замедления игры

        }
        free(snake1.tail);
        free(snake2.tail);
    }


    for (int i = 0; i < height; i++) {
        free(screen[i]);
    }
    free(screen);

    endwin();
    printf("width %d height %d\n", width, height);
    printf("game mod %d\n", game_mod);
    return 0;
}
