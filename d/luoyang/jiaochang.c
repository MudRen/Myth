inherit ROOM;

void create()
{
        set("short", "��У��");
        set("long", @LONG
����������У�ľ�ʿ�ĵط���ֻ��У������ΡΡ����һ����̨��̨��
������ǧ�������Ӱ�ʡ�̨ǰ����������ˣ���˶��ϻ�����˶����춷��
У����ۼ����������ٱ����佫���������ｫҪ�����ı�ʽ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"wroad4",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 4,
                "/d/city/npc/wujiang" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

