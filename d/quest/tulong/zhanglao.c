inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "������");
        set("long",HIG @LONG 
���Ǿ��鳤�����ڵķ��䣬һ���׺��ӵľ��������������ڴ�
ǰ��˼��ʲô��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "west" : "/d/quest/tulong/village",     "southeast" : "/d/quest/tulong/xiuxishi",     ]));

        setup();
        replace_program(ROOM);

}


