

Привет! 
Это дополнитльное задание, которое мы будем развивать несколько недель. К концу семестра мы должны получить проект
аналогичный https://track.toggl.com/timer.

### Часть 0

Заводим аккаунт на github.com

Установить на свой рабочий компьютер git (https://git-scm.com/). Прочитать немного, что это такое (например, https://githowto.com/ru)

Локально на компьютере создаем папку, в которой будут хранится проекты, например  
```
olga$ mkdir seminar3 
olga$ cd seminar3
olga$ git clone https://github.com/OKriw/Seminar3.git
```


В консоли будет что-то такое:  
```
Cloning into 'Seminar3'...  
remote: Enumerating objects: 15, done.  
remote: Counting objects: 100% (15/15), done.  
remote: Compressing objects: 100% (11/11), done.  
remote: Total 15 (delta 2), reused 6 (delta 2), pack-reused 0  
Unpacking objects: 100% (15/15), done.  
Olgas-MacBook-Pro:sem3 olga$ ls  -al  
total 0  
drwxr-xr-x   3 olga  staff    96 Sep 16 20:29 .  
drwxr-xr-x@ 76 olga  staff  2432 Sep 16 20:27 ..  
drwxr-xr-x  11 olga  staff   352 Sep 16 20:29 Seminar3 
```

Далее создаем свою ветку и переключаемся в нее:
```
git branch Your-name-semina3-timer
git checkout Your-name-semina3-timer
```
 ###### Важно!
 Всю разработку ведем строго в своей ветке.

Идем в папку Seminar3 и смотрим что к чему.
Открываем проект в своей среде разработки, я пользуюсь CLion.
### Часть 1 
##### Пишем простой трекер временни.
В toogle timer можно дать имя своей активности - задачи, дела и тд., нажать кнопку старт и начнется отсчет времени.  
Как только вы сменили активность или закончили работать можно остановить таймер и увидеть время затраченное на задачу.
Потом можно вернуться снова к этой задаче или начать новую, причем время для одной и той же задачи будет все время расти.
На сегодняшнее занятие мы с вами сделаем такой таймер.

Смотрим на `class Timer` - ваша задача написать обьявленные функции,
собрать и запустить проект, раскоментировать содержимое функции `main` и убедится что вы получили такой вывод. 

```
--Task checks--

seminar3 --  00:00:00
seminar3 --  00:00:04
seconds spent on seminar3 04
--Task checks End--
```
Теперь пройдемся по функциям:
```
    void start_timer();
    void stop_timer(); 
```
Основные функции нашего таймера - вызвали старт начался отсчет, нажали стоп -  
дальше не трекаем, снова старт - продолжаем увеличивать время счетчика.
Единственная функция которая может сбросить время - `void clear_timer();`  
После нее отсчет снова начинается с 0.  
`void print_time();` - вывести время в виде hh:mm:ss  

`int get_elapsed_time(char fmt);`  - вернуть время в секундах/минутах/часах  
`string format_elapsed_time();` - вернуть строку вида hh:mm:ss

После того как проверили делаем свой коммит.
```
git status
git add <list of files>
git commit -m "<message for commit>"
```


##### Полезные ссылки:
 * https://habr.com/ru/post/324984/ подсмотреть как использовать chrono
 
 ### Часть 3
 К этому моменту у нас есть 2 класса Timer и Task.
 Сегодня мы немного отвлечемся от них и займемся консольными вещами и конечными автоматами.
 Для начала обновите свой мастер и посмотрите какие новые классы появились.
 
 #### Console:
 Часть связанную с консолью можно сделать отдельно, потом  просто добавить в нужные методы наших классов.
 Для начала давайте пордумаем как запкскаются программы с ключами?
 А как это написать?
 Чтобы не изобретать велосипеды давайте воспользуемся #include <unistd.h> (https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html)
 и из нее   вытащим функцию  int getopt(int argc, char * const argv[], const char *optstring).
 
Задача - добавить поддержку ключей для нашего консольного приложения:
Короткие ключи -s (storage) -c (client) -o (output)
Примеры:
```
Olgas-MacBook-Pro:TTimer olga$ ./cmake-build-debug/TTimer -s mem
Found argument mem
```
```
Olgas-MacBook-Pro:TTimer olga$ ./cmake-build-debug/TTimer -s mem -o out -c client
Found argument mem
Found argument out
Found argument client
```
Пока это заглушка котоая не влияет на нашу пограмму, однако чуть позже мы начнем менять поведение таймера зависимо от заданных ключей.

Давайте теперь вернемся к классу Task и подумаем о жизненном цикле task и ее состояниях. И попытаемся договорится о правилах которым будет следовать
наше приложение.

<pre>
Task.h:
 enum states {
    stopped, //initial state
    running,
    deleted //when we want to delete from the storage
};
class Task {
private:
    ...
    bool isValid(states new_state);
    states state;
public:
    ...
    bool isRunning();
    bool isStopped();
    bool isDeleted();
    states getState();
    ...
    void delete_t();
};
 </pre>
 
  ![State 1](State.png)
 Мы видим новое поле и несколько функций. Теперь Task хранит не только имя и таймер, но и состояние текущей задачи. Зачем?
 Квкой класс мы реализуем следующим? Надеюсь к этому моменту становится понятно, что нам нужен конечный автомат. Это некоторая прослойка между командами и
 и Task, которая решает можно ли запустить, удалить или остановить таску.
 Я хочу чтобы вы реализовали класс Mng.h, который отвечает за проверку всех поставленных условий, а так же запускает, останавливает и удаляет задачу.
 Кстати сразу вопрос - почему у класса приватный конструктор? Как это называется и зачем это нужно?
 
 Теперь остается последний класс, тот кто будет сообщать менаджеру задач что вы хотите сделать. Это класс Client.h с единственным методом run.
 Класс Client непосредственно принимает ваши запросы, парсит их и передает менаджеру, который их и обрабатывает. 
 Сразу возникает вопос как мы будем создавать и связывать Client и Mgr? Какие есть варианты?
 <pre>
help  see this message
Usage:
option <arg>
create <task name> --create task with name <task_name>
start <task name>  --start task with name <task_name>
stop --stop current task
stat <task name>/<all>  --display statistics
quit --quit task tracker
quit

 </pre>
 
 В результате при запуске вашего приложения я хочу увидеть:
<pre>
Olgas-MacBook-Pro:TTimer olga$ ./cmake-build-debug/TTimer -s mem -o out -c client
Found argument mem
Found argument out
Found argument client
Getting instance of the manager
Manager is created
Client created
Manager is connected
create Task1
start Task1
stop Task1
stat Task1
Task1 --  00:00:05
create Task2
stop Task2
Error stopping task Task2, state: 0
start Task2
startTask2
OPTION UNKNOWN
use 'help' to get help
start Task2
Error starting task Task2 ,state: 1
stop Task2
stat Task2
Task2 --  00:00:19
 </pre>
 Теперь открываем master и и пишем=)
 
