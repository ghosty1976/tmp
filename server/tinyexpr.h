/**
 * @file tinyexpr.h
 * @brief Легковесный парсер математических выражений (лицензия Zlib).
 * @author Lewis Van Winkle
 * @see http://codeplea.com
 */

#ifndef TINYEXPR_H
#define TINYEXPR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct te_expr
 * @brief Внутреннее представление парсированного выражения.
 */
typedef struct te_expr {
    int type; ///< Тип узла (TE_VARIABLE, TE_FUNCTION и т.д.).
    union {
        double value;         ///< Численное значение (для констант).
        const double *bound;  ///< Ссылка на переменную.
        const void *function; ///< Указатель на функцию.
    };
    void *parameters[1]; ///< Параметры (для функций/замыканий).
} te_expr;

/**
 * @enum Типы узлов выражения.
 */
enum {
    TE_VARIABLE = 0,          ///< Переменная.
    TE_FUNCTION0 = 8, TE_FUNCTION1, TE_FUNCTION2, TE_FUNCTION3, TE_FUNCTION4, TE_FUNCTION5, TE_FUNCTION6, TE_FUNCTION7,    ///< Функции 0-7 аргументов.
    TE_CLOSURE0 = 16, TE_CLOSURE1, TE_CLOSURE2, TE_CLOSURE3, TE_CLOSURE4, TE_CLOSURE5, TE_CLOSURE6, TE_CLOSURE7,    ///< Замыкания 0-7 аргументов.
    TE_FLAG_PURE = 32         ///< Флаг "чистой" функции.
};

/**
 * @struct te_variable
 * @brief Описание переменной для парсера.
 */
typedef struct te_variable {
    const char *name;     ///< Имя переменной.
    const void *address;  ///< Указатель на значение.
    int type;            ///< Тип (TE_VARIABLE и т.д.).
    void *context;       ///< Контекст (для замыканий).
} te_variable;

/**
 * @brief Парсинг и вычисление выражения "на лету".
 * @param expression Строка с выражением (например, "sqrt(x^2 + y^2)").
 * @param[out] error Код ошибки (0 - OK).
 * @return Результат вычисления или NaN при ошибке.
 */
double te_interp(const char *expression, int *error);

/**
 * @brief Компиляция выражения с привязкой переменных.
 * @param expression Строка с выражением.
 * @param variables Массив переменных.
 * @param var_count Количество переменных.
 * @param[out] error Код ошибки.
 * @return Указатель на скомпилированное выражение или NULL.
 */
te_expr *te_compile(const char *expression, const te_variable *variables, int var_count, int *error);

/**
 * @brief Вычисление скомпилированного выражения.
 * @param n Указатель на выражение.
 * @return Результат вычисления.
 */
double te_eval(const te_expr *n);

/**
 * @brief Отладочная печать синтаксического дерева.
 * @param n Указатель на выражение.
 */
void te_print(const te_expr *n);

/**
 * @brief Освобождение памяти выражения.
 * @param n Указатель на выражение (может быть NULL).
 */
void te_free(te_expr *n);

#ifdef __cplusplus
}
#endif

#endif /*TINYEXPR_H*/