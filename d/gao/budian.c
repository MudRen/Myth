// gate.c

inherit ROOM;

void create()
{
  set ("short", "���Ҳ���");
  set ("long", @LONG

����Ķ����䲻�߼���ȴ�൱���ϵ����˵Ŀ�ζ��������������
���˻��治�٣����к��һ���߳߶೤�Ĺ�̨����̨��ļ�������
һƥƥ�Ĳ��Ϻͳ��£�
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road2",
]));

set("objects", ([
                __DIR__"npc/pangsao": 1]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


