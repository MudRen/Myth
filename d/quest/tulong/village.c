inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "�������");
        set("long",HIG @LONG 
��ǰ�Ǽ�����Ϊ��ͨ�Ĵ��ᣬ�����������С������������׷
����֣���ֻ�ʷʵĴ�׶죬�����������쳤�˲��Ӹ¸µĽУ���
��������Ȼ�ҵ����������ÿ��Ϧ�����µ�ʱ�򣬺���é��
ձ�ɵ��ݶ���ᱻ�����Ĵ�����ס����������������һ�����˵���
������ζ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : "/d/quest/tulong/lake",               "west" : "/d/quest/tulong/spirit10",             "east" : "/d/quest/tulong/zhanglao",     ]));

        setup();
        replace_program(ROOM);

}


