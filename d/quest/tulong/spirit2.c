inherit ROOM;  
#include <ansi.h> 
void create() 
{ 
        set("short", "�����");
        set("long", HIG"�����������ʣ��������ƣ��������һ��ʫ��\n\n"NOR+HIW"        ��һ����ӡ�����ۣ��羫��Ӵ˲��ٷ��衣\n"NOR+HIW"        �ڶ�����ӡ��ˮ�䣬�������˻��������˷�â��\n"NOR+HIW"        ��������ӡ����ɽ�ң���صĸ���תΪ���ʡ�\n"NOR+HIW"        ���ĸ���ӡ�����׵磬����ֻʣ�±���Ļ��档\n"NOR+HIW"        �������ӡ�����֪����̫���Ĺ�âԶ���˾������������ݡ�\n"NOR+HIW"        ��������ӡҲ���������¹���Ĺ԰�ﲻ������Ϸ��\n"NOR+HIW"        ���ǵ��߸���ӡ����\n"NOR+HIW"        ����ô��Ҳ�벻��\n"NOR+HIW"        ���߸���ӡ����һ����������\n"NOR+HIW"        �Ҿ��������������\n\n"NOR+HIG"һ������������Ů��վ��ʫ���£��·�ȴ���ʲô��\n"NOR
        );
        set("exits", ([ 
   "south" : __DIR__"spirit1",
 ]));
        set("objects", ([ 
           "/d/quest/tulong/npc/leader" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


