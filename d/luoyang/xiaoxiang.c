inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
����һ����ʯС·��·������ʯ���̳ɣ��ո��¹��꣬·����Ǹɾ���
С���ھ����ĵģ�ֻ�������Լ��ĽŲ�����ż���紵����֦����ɳɳ����
����
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"xiaoxiang2",
                "west" : __DIR__"nroad4",
        ]));

        setup();
        replace_program(ROOM);
}

