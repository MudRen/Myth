inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����������ǵ���ᣬֻҪ����������Ǯ����������ͻ��ܵ������
�к����κ��㲻֪�����£������������һ�£�������֪�����˾Ų���ʮ��
����������л��ɣ�����ģ�����ߵģ����յģ���ҩ�ģ���ˣ�ģ���ζ
С�ԣ�Ӧ�о��С�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"wanju",
                "south" : __DIR__"eroad4",
        ]));
        set("objects", ([
                "/d/luoyang/npc/xianren" : 2,
                "/d/city/npc/youke" : 2,
        ]));
        setup();
        replace_program(ROOM);
}

