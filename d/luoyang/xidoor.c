inherit ROOM;

void create()
{
        set("short", "�ڳ�����");
        set("long", @LONG
�����ڳ����Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ��
��С���������Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������
������׽��֮��Ĺٸ�ͨ����һ����ֱ����ʯ���������������죬��
ȥ���������ڳ��ˣ�����һ�Ÿ߸߿�������ǻ��Ǻӡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"wroad7",
                "west" : __DIR__"wbridge",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 3,
                "/d/city/npc/wujiang" : 1,
        ]));
        setup();
        replace_program(ROOM);
}


