inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ�����
�ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ���
����������ǰѲ�ߡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"yamen",
                "west" : __DIR__"nroad2",
        ]));
        set("objects", ([
                "/d/jz/npc/yayi" : 4,
        ]));
        setup();
        replace_program(ROOM);
}

