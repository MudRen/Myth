//in wangxian DIR
//jinse.c

#include <ansi.h>
inherit ROOM;
void create()
{
          set("short",YEL"ɽ����");
          set("long",@LONG
������ɽ���µ�һ��С·����˵��һ������ʳ�˹�
���֣������ҿ����˿�����Ϊ���¡�
LONG); 
         
           set("exits",([ /* sizeof() == 1 */
           "back" : __DIR__"minghu1",
           ]));
        set("objects", ([ /* sizeof() == 1 */  
        "/d/wizz/dewbaby/npc/jinse" : 1,
        ]));
     set("no_fight",1);
     set("no_sleep",1);
     set("no_eat",1);
     set("no_magic",1);
          
           setup();
}


